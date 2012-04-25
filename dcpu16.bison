%{
	#include "dcpu16.h"
	#include <io.h>
	#include <malloc.h>
	#include <assert.h>
	

	#define YY_NO_UNISTD_H 
	#define YYDEBUG 1
%}
%token SET ADD SUB MUL MUI DIV DVI MOD AND BOR XOR SHR ASR SHL 
%token IFB IFC IFE IFN IFG IFA IFA IFL IFU 
%token JSR INT ING INS HWN HWQ HWI
%token ORGIN WORD BYTE EQU NUMBER IDENT EOL EOFILE ERROR 
 
%token REG_A REG_B REG_C REG_X REG_Y REG_Z REG_I REG_J REG_SP REG_EX  REG_PC
%token PEEK POP PICK PUSH
%union
{
	uint16_t _code;
	int _num;
	tag _ident;
	tag _string;
	Operand  _operand;
	Opcode _opcode;
	ast* _expr;
	Line * _line;
	arg* _args;
}
%token <_num> NUMBER 
%token <_ident> STRING IDENT
%type <_ident> label 
%type <_line>  line macro
%type <_code> opcode_expr_double opcode_expr_single operand_regester
%type <_opcode> opcode_expr

%type <_expr>  expr
%type <_args> datseq  
%type <_operand>  operand_expr
	REG_A REG_B REG_C REG_X REG_Y REG_Z REG_I REG_J

%right '=' EQU ORGIN
%left '+' '-' 
%left '*' '/' '%'
%nonassoc UMINUS

%start	all
%%

all	: lines EOFILE
	  {
	    return 0;
	  }
	;

lines
	: line			{	pushline($1); }			
	| lines line	{	pushline($2); }	
	;

line
	:						EOL			{ $$ =  0; }
	| IDENT	'=' expr		EOL		    { $$ = 0; sym_val($1, ast_eval($3)); }
	| IDENT	EQU expr		EOL		    { $$ = 0; sym_val($1, ast_eval($3)); }		
	| label ORGIN expr		EOL	        { $$ = line_origin(ast_eval($3)); sym_val($1, line_current_pc()); }
	| ORGIN expr		    EOL	        { $$ = line_origin(ast_eval($2)); }
	| label					EOL		    { $$ = 0; }
	| macro					EOL			{ $$ = $1; }
	| label        macro	EOL			{ $$ = $2; }
	| expr					EOL		    { $$ = 0;  }
	;

label	: IDENT ':'  { $$ = $1;  sym_val($1, line_current_pc()); }
		| ':' IDENT  { $$ = $2;  sym_val($2, line_current_pc()); }
		;

macro :	WORD datseq				{ $$ = line_words($2);  }
	  | BYTE datseq				{ $$ = line_bytes($2);  }
	  | opcode_expr 			{ $$ = line_opcode($1); }
	  ;

datseq  : STRING            { $$ = arg_array((uint8_t*)$1,strlen($1));  }
		| expr				{ $$ = arg_expr($1);   }
		| STRING ',' datseq { $$ = arg_array((uint8_t*)$1,strlen($1)); $$->next = $3;  }
		| expr   ',' datseq { $$ = arg_expr($1); $$->next = $3;    }
		;


operand_regester 
    : REG_A						{ $$ = 0; }	
	| REG_B						{ $$ = 1;  }	
	| REG_C						{ $$ = 2;  }	
	| REG_X						{ $$ = 3;  }	
	| REG_Y						{ $$ = 4;  }	
	| REG_Z						{ $$ = 5;  }	
	| REG_I						{ $$ = 6;  }	
	| REG_J						{ $$ = 7;  }	
	;

operand_expr 
	: operand_regester						{ $$.code = $1;		$$.expr = NULL;		}
	| '[' operand_regester ']'				{ $$.code = $2 + 8;	$$.expr = NULL;		}
	| '[' operand_regester '+' expr ']'	    { $$.code = $2 + 16; $$.expr = $4;		}
	| '[' expr '+' operand_regester ']'	    { $$.code = $4 + 16; $$.expr = $2;		}
	| PUSH									{ $$.code  = 0x18;	$$.expr = NULL;		}
	| POP								    { $$.code  = 0x18;	$$.expr = NULL;		}
	| PEEK								    { $$.code  = 0x19;	$$.expr = NULL;		}
	| '[' REG_SP ']'					    { $$.code  = 0x19;	$$.expr = NULL;		}
	| PICK expr					            { $$.code  = 0x1a;	$$.expr = $2;		}
	| '[' REG_SP '+'  expr ']'		        { $$.code  = 0x1a;	$$.expr = $4;		}
	| REG_SP								{ $$.code  = 0x1b;	$$.expr = NULL;		}
	| REG_PC								{ $$.code  = 0x1c;	$$.expr = NULL;		}
	| REG_EX								{ $$.code  = 0x1d;	$$.expr = NULL;		}
	| '[' expr ']'							{ $$.code  = 0x1e;	$$.expr = $2;		}
	| expr									{ $$.code  = 0x1f;	$$.expr = $1;		}
	;

opcode_expr_single
	: JSR 	{ $$ = 0x01;  }
	| INT 	{ $$ = 0x08;  }
	| ING 	{ $$ = 0x09;  }
	| INS 	{ $$ = 0x0a;  }
	| HWN 	{ $$ = 0x10;  }
	| HWQ 	{ $$ = 0x11;  }
	| HWI 	{ $$ = 0x12;  }
	;
opcode_expr_double
	: SET 	{ $$ = 0x1;  }
	| ADD 	{ $$ = 0x2;  }
	| SUB 	{ $$ = 0x3;  }
	| MUL 	{ $$ = 0x4;  }
	| MUI 	{ $$ = 0x5;  }
	| DIV 	{ $$ = 0x6;  }
	| DVI 	{ $$ = 0x7;  }
	| MOD 	{ $$ = 0x8;  }
	| AND 	{ $$ = 0x9;  }
	| BOR 	{ $$ = 0xA;  }
	| XOR 	{ $$ = 0xB;  }
	| SHR 	{ $$ = 0xC;  }
	| ASR 	{ $$ = 0xD;  }
	| SHL 	{ $$ = 0xE;  }
	| IFB 	{ $$ = 0x10; }
	| IFC 	{ $$ = 0x11; }
	| IFE 	{ $$ = 0x12; }
	| IFN 	{ $$ = 0x13; }
	| IFG 	{ $$ = 0x14; }
	| IFA 	{ $$ = 0x15; }
	| IFL 	{ $$ = 0x16; }
	| IFU 	{ $$ = 0x17; }
	;

opcode_expr
	: opcode_expr_double operand_expr ',' operand_expr	{ $$.code = $1; $$.b = $2; $$.a =  $4; }
	| opcode_expr_single operand_expr					{ $$.code = $1 << 5;  $$.a = $2; $$.b.code = -1; }
	;

expr	: expr '+' expr					{ $$ = ast_new('+', $1,$3); }
		| expr '-' expr					{ $$ = ast_new('-', $1,$3); }
		| expr '*' expr					{ $$ = ast_new('*', $1,$3); }
		| expr '/' expr					{ $$ = ast_new('/', $1,$3); }
		| expr '%' expr					{ $$ = ast_new('%', $1,$3); }
		| '(' expr ')'		            { $$ = $2; }
		| '-' expr  %prec UMINUS        { $$ = ast_new(AST_UMINUS, $2,NULL); }
		| NUMBER						{ $$ = ast_num($1); }
		| IDENT							{ $$ = ast_name($1); }
		;
%%
