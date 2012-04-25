#include "dcpu16.h"
#include "intel_hex.h"
#include <assert.h>
#include <stdint.h>

const char* opcode_str[] =     { "ER0", "SET", "ADD", "SUB", "MUL", "DIV", "MOD", "SHL", "SHR", "AND", "BOR", "XOR", "IFE", "IFN", "IFG", "IFB", NULL };
const char* opcode_ext_str[] = { "ER1", "JSR", NULL };
const char* regester_str[] = { "A", "B","C","X","Y","Z","I","J", NULL};
const char* special_reg_str[] = { "POP","PEEK","PUSH","SP","PC","O",NULL };

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

int list_operand(FILE* f,Operand* op) 
{
	if(op->code >= 0x00 && op->code <= 0x07)
		return fprintf(f,"%s",regester_str[op->code]);
	else if(op->code >=0x08 && op->code <= 0x0f)
		return fprintf(f,"[%s]",regester_str[op->code & 3]);
	else if(op->code >= 0x10 && op->code <=0x17)
		return fprintf(f,"[%s+%#4.1x]",regester_str[op->code & 3],ast_eval(op->expr));
	else if(op->code >=0x18 && op->code <= 0x1d)
		return fprintf(f,"%s",special_reg_str[op->code -0x18]);
	else if(op->code == 0x1e)
		return fprintf(f,"[%#4.1x]",ast_eval(op->expr));
	else if(op->code == 0x1f) 
		return fprintf(f,"%#4.1x",ast_eval(op->expr));
	else if(op->code >= 0x20 && op->code <= 0x3f)
		return fprintf(f,"%#2.1x",op->code - 0x20);
	fprintf(errAsm,"list_operand: Invalid Operand");
	assert(0);
	exit(1);
}
int opcode_size(Opcode* op) {
	int ret = 1;
	ret += op->a.expr ? 1 : 0;
	ret += op->b.expr ? 1 : 0;
	return ret;
}
int opcode_list(FILE * f, Opcode* op) {
	int ret = 0;
	if(op->code == 0) {
		if(op->a.code != 1) { yyerror("We do not support more than JSR at this time"); exit(1); }
		// Special opcode handling, fix this if we get more
		ret += fprintf(f,"%s ", opcode_ext_str[op->a.code]);
		ret += list_operand(f,&op->b);
	} else {
		ret += fprintf(f,"%s ", opcode_str[op->code & 0xf]);
		ret += list_operand(f,&op->a);
		ret += fprintf(f," ,\t");
		ret += list_operand(f,&op->b);
	}
	return ret;
}
int opcode_emit(Opcode* op,uint16_t* mem) {
	int ret = 0;
	if(op->code == 0) {
		if(op->a.code != 1) { yyerror("We do not support more than JSR at this time"); exit(1); }
		// Special opcode handling, fix this if we get more
		mem[ret++] = ((op->b.code & 0x3F) << 10) | ((op->a.code & 0x3F) << 4);
		if(op->b.expr) mem[ret++] =  ast_eval(op->b.expr);
	} else {
		mem[ret++] = ((op->b.code & 0x3F) << 10) | ((op->a.code & 0x3F) << 4) | (op->code & 0xF);
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


void pushline(Line * line) {
	if(!line) return;
	if(!root) { root = last = line; return; }
	last->next = line;
	last = line;
	line->lineno = lineno;
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
	// Lets verify we have a valid opcode, if not spit out an error and drop.
	if(opcode.code == 0 && opcode.a.code != 1)
	{
		// We only support extended JSR at this time, so lets let eveyone know we don't support
		// anything else
		yyerror("Only support JSR right now");
		fatal_error(1);
	} else if(opcode.code > 0x3f) {
		yyerror("Opcode out of range, programing glitch?");
		fatal_error(1);
	}
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
