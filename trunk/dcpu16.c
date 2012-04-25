#include "dcpu16.h"
#include "intel_hex.h"
#include <assert.h>
#include <stdint.h>

const char* opcode_str[] =     { 
	"E00", "SET", "ADD", "SUB", "MUL", "MUI", "DIV", "DVI", "MOD", "AND", "BOR", "XOR", "SHR", "ASR", "SHL", "E0F", 
	"IFB", "IFC", "IFE", "IFN", "IFG", "IFA", "IFL", "IFU", "E18", "E19", "ADX", "SUX", "E1C", "E1D", "E1E", "E1F" 
};
const char* opcode_ext_str[] = { 
	"S00", "JSR", "S02", "S03", "S04", "S05", "S06", "S07", "INT", "ING", "INS", "S0B", "S0C", "S0D", "S0E", "S0F",
	"HWN", "HWQ", "HWI", "S13", "S14", "S15"," S16", "S17", "S18", "S19", "S1A", "S1B", "S1C", "S1D", "S1E", "S1F" 
};
const char* regester_str[] =    { "A", "B","C","X","Y","Z","I","J", NULL};
const char* special_reg_str[] = { "POP","PEEK","PICK","SP","PC","EX",NULL };

 enum {
	 ARG_EXPR,
	 ARG_ARRAY
 };
 
arg* arg_array(uint8_t* data, size_t len) {
	arg* t;
	assert(data);
	
	t = (arg*)malloc(sizeof(arg));
	t->type = ARG_ARRAY;
	t->v.data.dat = (uint8_t*)malloc(sizeof(uint8_t) * len);
	memcpy(t->v.data.dat, data,sizeof(uint8_t) * len);
	t->v.data.len = len;
	t->next = NULL;
	return t;
}
arg* arg_expr(ast* expr) {
	arg* t;
	assert(expr);

	t = (arg*)malloc(sizeof(arg));
	t->type = ARG_EXPR;
	t->v.val = expr;
	t->next = NULL;
	return t;
}
void arg_free(arg* a) {
	arg* next = NULL;
	while(a) {
		next = a->next;
		switch(a->type) {
		case ARG_EXPR:
			ast_free(a->v.val);
			a->v.val = NULL;
			break;
		case ARG_ARRAY:
			free(a->v.data.dat);
			a->v.data.dat = NULL;
			a->v.data.len = 0;
			break;
		}
		free(a);
		a = next;
	}
}

int list_operand(FILE* f,Operand* op, int is_a) 
{
	if(op->code >= 0x00 && op->code <= 0x07)
		return fprintf(f,"%s",regester_str[op->code]);
	else if(op->code >=0x08 && op->code <= 0x0f)
		return fprintf(f,"[%s]",regester_str[op->code & 3]);
	else if(op->code >= 0x10 && op->code <=0x17)
		return fprintf(f,"[%s+%#4.1x]",regester_str[op->code & 3],ast_eval(op->expr));
	else if(op->code >= 0x20 && op->code <= 0x3f && is_a)
		return fprintf(f,"%#2.1x",op->code - 0x20);
	else switch(op->code) {
	case 0x18: return is_a ? fprintf(f,"POP") : fprintf(f,"PUSH");
	case 0x1b: return fprintf(f,"SP");
	case 0x1c: return fprintf(f,"PC");
	case 0x1e: return fprintf(f,"[%#4.1x]",ast_eval(op->expr));
	case 0x1f: return fprintf(f,"%#4.1x",ast_eval(op->expr));
	}
	yyerror("list_operand: Invalid Operand");
	fatal_error(1);
	return 0;
}

int opcode_size(Opcode* op) {
	int ret = 1;
	ret += op->a.expr ? 1 : 0;
	ret += op->b.expr ? 1 : 0;
	return ret;
}
int opcode_list(FILE * f, Opcode* op) {
	int ret = 0;
	uint16_t n = 0;
	if((op->code & 0x1f) == 0) {
		n = (op->code >> 5) & 0x1f;
		ret += fprintf(f,"%s ", opcode_ext_str[n]);
		ret += list_operand(f,&op->a,1);
	} else {
		n = op->code & 0x1f;
		ret += fprintf(f,"%s ", opcode_str[n]);
		ret += list_operand(f,&op->a,1);
		ret += fprintf(f," ,\t");
		ret += list_operand(f,&op->b,0);
	}
	return ret;
}
int opcode_emit(Opcode* op,uint16_t* mem) {
	int ret = 0;
	uint16_t n = 0;
	if((op->code & 0x1f) == 0) {
		n = (op->code >> 5) & 0x1f;
		mem[ret++] = ((op->a.code & 0x3F) << 10) | ((n) << 4);
		if(op->b.expr) mem[ret++] =  ast_eval(op->b.expr);
	} else {
		n = op->code & 0x1f;
		mem[ret++] = ((op->a.code & 0x3F) << 10) | ((op->b.code & 0x1F) << 4) | n;
		if(op->a.expr) mem[ret++] =  ast_eval(op->a.expr);
		if(op->b.expr) mem[ret++] =  ast_eval(op->b.expr);
	}
	return ret;
}
int opcode_hex(FILE *f, Opcode* o) {
	uint16_t mem[3];
	int len = 0;
	len = opcode_emit(o,mem);
	switch(len) 
	{
	case 1: return fprintf(f,"%4.4X          ",mem[0]);
	case 2: return fprintf(f,"%4.4X %4.4X     ",mem[0],mem[1]);
	case 3: return fprintf(f,"%4.4X %4.4X %4.4X",mem[0],mem[1],mem[2]);
	default:
		yyerror("opcode_hex: Len out or range\n");
		exit(1);
	}
}

uint16_t PC = 0;
static Line* root = NULL;
static Line* last = NULL;
extern int lineno;

enum {
	LINE_BLANK,
	LINE_OPCODE,
	LINE_ORIGIN,
	LINE_ASSIGN,
	LINE_BYTES,
	LINE_WORDS
};
uint16_t line_current_pc() { return PC; }

extern int yylineno;
void pushline(Line * line) {
	if(!line) return;
	if(!root) { root = last = line; return; }
	last->next = line;
	last = line;
	line->lineno = yylineno;
}

static Line * _line_new(int type) {
	Line * t = (Line*)malloc(sizeof(Line));
	t->next = NULL;
	t->type = type;
	t->pc = PC;
	return t;
}
Line* line_origin(int origin) {
	Line * t = _line_new(LINE_ORIGIN);
	PC = t->v.origin = origin;
	return t;
}
Line* line_opcode(Opcode opcode) {
	Line * t = _line_new(LINE_OPCODE);
	t->v.opcode = opcode;
	PC += opcode_size(&opcode);
	return t;
 }

Line* line_bytes(arg* args) {
	arg* next = NULL;
	size_t n = 0;
	Line * t = NULL;

	t = _line_new(LINE_BYTES);
	vec_init();
	while(args) {
		next = args->next;
		switch(args->type) {
		case ARG_EXPR:
			n = ast_eval(args->v.val);
			vec_pushbyte(n);
			break;
		case ARG_ARRAY:
			for(n = 0; n < args->v.data.len; n++)
				vec_pushbyte(args->v.data.dat[n]);
			break;
		}
		args = next;
	}
	arg_free(args);
	if(vec_len() & 1) vec_pushbyte(0);
	t->v.data.dat = (uint16_t*)vec_strdup();
	t->v.data.len = vec_len() >> 1;
	PC += t->v.data.len;
	return t;
}
Line* line_words(arg* args) {
	arg* next = NULL;
	size_t n = 0;
	Line * t = NULL;

	t = _line_new(LINE_WORDS);
	vec_init();
	while(args) {
		switch(args->type) {
		case ARG_EXPR:
			n = ast_eval(args->v.val);
			vec_pushword(n);
			break;
		case ARG_ARRAY:
			for(n = 0; n < args->v.data.len; n++)
				vec_pushword(args->v.data.dat[n]);
			break;
		}
		args = args->next;
	}
	arg_free(args);
	t->v.data.dat = (uint16_t*)vec_strdup();
	t->v.data.len = vec_len() >> 1;
	PC += t->v.data.len;
	return t;
}
int list_bytes(FILE* f, uint16_t* dat, size_t len) {
	int ret = 0;
	size_t i;
	for(i=0;i < len; i++)
		ret += fprintf(f,"%2.2x %2.2x ",(uint8_t)dat[i],(uint8_t)(dat[i] >> 8));
	return ret;
}
int list_words(FILE* f, uint16_t* dat, size_t len) {
	int ret = 0;
	size_t i;
	for(i=0;i < len; i++)
		ret += fprintf(f,"%4.4x ",dat[i]);
	return ret;
}
static uint16_t scrach[0x10000];

static int test_row(uint8_t* row) {
	int i;
	for(i = 0; i < 16; i++)  if(row[i]) return 0;
	return 1;
}
int line_intel_hex(FILE * f) {
	int ret = 0;
	int segment = 0;
	uint8_t *row;
	size_t i;
	Line* l;
	l = root;
	memset(scrach,0,sizeof(uint16_t) * 0x10000);
	while(l) {
		switch(l->type) {
		case LINE_OPCODE: 
				opcode_emit(&l->v.opcode,scrach + l->pc);
			break;
		case LINE_BYTES:
		case LINE_WORDS:
				for(i=0; i < l->v.data.len; i++)
					scrach[l->pc + i] = l->v.data.dat[i];
			break;
		}
		l = l->next;
	}

	for(i=0; i < 0x20000; i+=16) {
		row = (uint8_t*)&scrach[i >> 1];
		// do some minor compresson and skip rows with no data
		if(test_row(row)) continue;
		if(i > 0xFFFF && !segment) {
			ret+= write_intel_hex_segment(f,0x1000);
			segment++;
		}
		ret+=write_intel_data(f,16,i & 0xFFFF,row);
	}
	ret+=write_intel_hex_eof(f);
	return ret;
}
int line_binary(FILE * f) {
	size_t i;
	Line* l;
	l = root;
	memset(scrach,0,sizeof(uint16_t) * 0x10000);
	while(l) {
		switch(l->type) {
		case LINE_OPCODE: 
				opcode_emit(&l->v.opcode,scrach + l->pc);
			break;
		case LINE_BYTES:
		case LINE_WORDS:
				for(i=0; i < l->v.data.len; i++)
					scrach[l->pc + i] = l->v.data.dat[i];
			break;
		}
		l = l->next;
	}
	return fwrite(scrach , 1 , sizeof(scrach) , f );
}
int line_list(FILE * f) {
	int ret = 0;
	Line* l = NULL;
	l = root;
	while(l) {
		switch(l->type) {
		case LINE_OPCODE:
			ret +=fprintf(f,"%4.4X: ",l->pc);
			ret +=opcode_hex(f,&l->v.opcode);
			ret +=fprintf(f," ; ");
			ret +=opcode_list(f,&l->v.opcode);
			ret +=fprintf(f,"\n");
			break;
		case LINE_BYTES:
			ret +=fprintf(f,"%4.4X: ",l->pc);
			ret +=list_bytes(f, l->v.data.dat, l->v.data.len);
			ret +=fprintf(f,"\n");
			break;
		case LINE_WORDS:
			ret +=fprintf(f,"%4.4X: ",l->pc);
			ret +=list_words(f, l->v.data.dat, l->v.data.len);
			ret +=fprintf(f,"\n");
			break;
		}
		fflush(f);
		l = l->next;
	}
	return ret;
}
