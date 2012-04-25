%{
	#include "dcpu16.h"
	#include <io.h>
	#include <malloc.h>
	#include <assert.h>
	

	#define YY_NO_UNISTD_H 
	#define YYDEBUG 1
%}
%token SET ADD SUB MUL DIV MOD SHL SHR AND BOR XOR IFE IFN IFG IFB 
%token JSR
%token ORGIN WORD BYTE EQU NUMBER IDENT EOL EOFILE ERROR 
 
%token REG_A REG_B REG_C REG_X REG_Y REG_Z REG_I REG_J REG_SP REG_O REG_PEEK REG_POP REG_PUSH REG_PC
%union
{
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
%type <_opcode> opcode_expr
%type <_expr>  expr
%type <_args> datseq  
%type <_operand> operand_regester operand_expr
	REG_A REG_B REG_C REG_X REG_Y REG_Z REG_I REG_J REG_SP REG_O REG_PEEK REG_POP REG_PUSH REG_PC

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
    : REG_A						{ $$.code = 0; $$.expr = NULL; }	
	| REG_B						{ $$.code = 1; $$.expr = NULL; }	
	| REG_C						{ $$.code = 2; $$.expr = NULL; }	
	| REG_X						{ $$.code = 3; $$.expr = NULL; }	
	| REG_Y						{ $$.code = 4; $$.expr = NULL; }	
	| REG_Z						{ $$.code = 5; $$.expr = NULL; }	
	| REG_I						{ $$.code = 6; $$.expr = NULL; }	
	| REG_J						{ $$.code = 7; $$.expr = NULL; }	
	;

operand_expr 
	: operand_regester						{ $$ = $1;					}
	| '[' operand_regester ']'				{ $$ = $2;  $$.code  += 8;			}
	| '[' expr  '+' operand_regester ']'	{ $$ = $4; $$.code  += 16;	$$.expr = $2;		}
	| REG_POP								{ $$.code  = 0x18;	$$.expr = NULL;		}
	| REG_PEEK								{ $$.code  = 0x19;	$$.expr = NULL;		}
	| REG_PUSH								{ $$.code  = 0x1a;	$$.expr = NULL;		}
	| REG_SP								{ $$.code  = 0x1b;	$$.expr = NULL;		}
	| REG_PC								{ $$.code  = 0x1c;	$$.expr = NULL;		}
	| REG_O									{ $$.code  = 0x1d;	$$.expr = NULL;		}
	| '[' expr ']'							{ $$.code  = 0x1e;	$$.expr = $2;		}
	| expr				{   
							if(ast_isnum($1)) 
								if($1->v.num < 0x20) {
									$$.code = operand_code(0x20 + $1->v.num);
									$$.expr = NULL;
									ast_free($1);
									$1 = NULL;
								} else {
									$$.code  = 0x1f;	
									$$.expr = $1;
								}
							else {
								$$.code  = 0x1f;	
								$$.expr = $1;
							}

						}	
						
	;

opcode_expr
	: SET operand_expr ',' operand_expr	{ $$.code = 0x1; $$.a = $2; $$.b =  $4; }
	| ADD operand_expr ',' operand_expr	{ $$.code = 0x2; $$.a = $2; $$.b =  $4; }
	| SUB operand_expr ',' operand_expr	{ $$.code = 0x3; $$.a = $2; $$.b =  $4; }
	| MUL operand_expr ',' operand_expr	{ $$.code = 0x4; $$.a = $2; $$.b =  $4; }
	| DIV operand_expr ',' operand_expr	{ $$.code = 0x5; $$.a = $2; $$.b =  $4; }
	| MOD operand_expr ',' operand_expr	{ $$.code = 0x6; $$.a = $2; $$.b =  $4; }
	| SHL operand_expr ',' operand_expr	{ $$.code = 0x7; $$.a = $2; $$.b =  $4; }
	| SHR operand_expr ',' operand_expr	{ $$.code = 0x8; $$.a = $2; $$.b =  $4; }
	| AND operand_expr ',' operand_expr	{ $$.code = 0x9; $$.a = $2; $$.b =  $4; }
	| BOR operand_expr ',' operand_expr	{ $$.code = 0xA; $$.a = $2; $$.b =  $4; }
	| XOR operand_expr ',' operand_expr	{ $$.code = 0xB; $$.a = $2; $$.b =  $4; }
	| IFE operand_expr ',' operand_expr	{ $$.code = 0xC; $$.a = $2; $$.b =  $4; }
	| IFN operand_expr ',' operand_expr	{ $$.code = 0xD; $$.a = $2; $$.b =  $4; }
	| IFG operand_expr ',' operand_expr	{ $$.code = 0xE; $$.a = $2; $$.b =  $4; }
	| IFB operand_expr ',' operand_expr	{ $$.code = 0xF; $$.a = $2; $$.b =  $4; }
	| JSR operand_expr					{ $$.code = 0;   $$.a.code = 0x01; $$.b = $2; }

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
