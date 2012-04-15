%{
	#include "dcpu16asm.h"
	#define YY_NO_UNISTD_H 
	#define YYDEBUG 1
%}
%union{
	int num;
	t_symbol* ident;
	char* str;
	t_operand operand;
	unsigned short opcode;
}
%token <num> NUMBER
%token <str> STRING
%token <ident> LABEL 
%type <ident> label
%type <num> expr
%type <opcode> opcode_expr
%type <opcode> rest
%type <operand> operand_expr 
%type <operand> operand_regester

%token SET ADD SUB MUL DIV MOD SHL SHR AND BOR XOR IFE IFN IFG IFB 
%token JSR
%token ORGIN WORD BYTE EQU

%token REG_A REG_B REG_C REG_X REG_Y REG_Z REG_I REG_J REG_SP REG_O REG_PEEK REG_POP REG_PUSH REG_PC

%token EOL
%token WRONGTOKEN ERROR PRINT

%right '='
%left '+' '-'
%left '*' '/' '%'
%left UNARYMINUS
%left '|' '&'
%left '!'
%left UNARYNOT
%%

lines
	: line				{  }
	| lines line		{  }
	;

line	: 						EOL
		| PRINT LABEL			EOL { printf("(%s:=%i)\n", $2->name, $2->val); fflush(stdout); }
		| rest  				EOL {}
		| error					EOL	{ yyerrok; }
		;

rest	: label '=' expr		{ $1->val = $3;		 }
		| label EQU expr		{ $1->val = $3;	 	 }
		| label 				{ $1->val = emit_pc();  }
		| label ORGIN expr		{ emit_origin($3); $1->val = emit_pc();	 }	
		| ORGIN expr			{ emit_origin($2);	 }	
		| WORD { emit_raw_start(); }	wordseq			{  }
		| BYTE { emit_raw_start();	 }  byteseq			{  }
		| label opcode_expr		{ $1->val = emit_pc(); $$ = 0;	 }
		| opcode_expr			{ $$ = 0;			 }
		;

byteseq	: 
		| expr				{ emit_byte($1);	}
		| byteseq ',' expr	{ emit_byte($3);	}
		;

wordseq	: 
        | expr				{ emit_word($1);	}
		| wordseq ',' expr	{ emit_word($3);	}
		;

label	: LABEL  			{ $$ = $1; }
		| ':' LABEL 		{ $$ = $2; }
		| LABEL ':'			{ $$ = $1; }
		;

expr:	NUMBER				{ $$ = $1; }
		| LABEL				{ $$ = $1->val; }
		| expr '+' expr		{ $$ = $1 + $3; }
		| expr '-' expr		{ $$ = $1 - $3; }
		| expr '*' expr		{ $$ = $1 * $3; }
		| expr '/' expr		{ $$ = $1 / $3; }
		| expr '%' expr		{ $$ = $1 % $3; }
		| expr '&' expr		{ $$ = $1 & $3; }
		| expr '|' expr		{ $$ = $1 | $3; }
		| '(' expr ')'		{ $$ = $2; }
		| '-' expr %prec UNARYMINUS { $$ = -$2; }
		| '!' expr %prec UNARYNOT { $$ = !$2; }
		;

operand_regester 
    : REG_A						{ $$.code =  0; }	
	| REG_B						{ $$.code  = 1; }	
	| REG_C						{ $$.code  = 2; }	
	| REG_X						{ $$.code  = 3; }	
	| REG_Y						{ $$.code  = 4; }	
	| REG_Z						{ $$.code  = 5; }	
	| REG_I						{ $$.code  = 6; }	
	| REG_J						{ $$.code  = 7; }	
	;

operand_expr 
	: operand_regester					{ $$.code  = $1.code;		$$.offset = -1;		}
	| '[' operand_regester ']'			{ $$.code  = $2.code + 8;	$$.offset = -1;		}
	| '[' expr '+' operand_regester ']'	{ $$.code  = $4.code + 16;	$$.offset = $2;		}
	| REG_POP							{ $$.code  = 0x18;			$$.offset = -1;		}
	| REG_PEEK							{ $$.code  = 0x19;			$$.offset = -1;		}
	| REG_PUSH							{ $$.code  = 0x1a;			$$.offset = -1;		}
	| REG_SP							{ $$.code  = 0x1b;			$$.offset = -1;		}
	| REG_PC							{ $$.code  = 0x1c;			$$.offset = -1;		}
	| REG_O								{ $$.code  = 0x1d;			$$.offset = -1;		}
	| '[' expr ']'						{ $$.code  = 0x1e;			$$.offset = $2;		}
	| expr								
			{ 
				if($1 < 0x20)
				{
					$$.code  = $1 + 0x20;
					$$.offset = -1;	
				}
				else
				{
					$$.code  = 0x1f;
					$$.offset = $1;	
				}	
			}
	;
opcode_expr
	: SET operand_expr ',' operand_expr	{ emit_std_opcode(0x1, $2, $4); }
	| ADD operand_expr ',' operand_expr	{ emit_std_opcode(0x2, $2, $4); }
	| SUB operand_expr ',' operand_expr	{ emit_std_opcode(0x3, $2, $4); }
	| MUL operand_expr ',' operand_expr	{ emit_std_opcode(0x4, $2, $4); }
	| DIV operand_expr ',' operand_expr	{ emit_std_opcode(0x5, $2, $4); }
	| MOD operand_expr ',' operand_expr	{ emit_std_opcode(0x6, $2, $4); }
	| SHL operand_expr ',' operand_expr	{ emit_std_opcode(0x7, $2, $4); }
	| SHR operand_expr ',' operand_expr	{ emit_std_opcode(0x8, $2, $4); }
	| AND operand_expr ',' operand_expr	{ emit_std_opcode(0x9, $2, $4); }
	| BOR operand_expr ',' operand_expr	{ emit_std_opcode(0xa, $2, $4); }
	| XOR operand_expr ',' operand_expr	{ emit_std_opcode(0xb, $2, $4); }
	| IFE operand_expr ',' operand_expr	{ emit_std_opcode(0xc, $2, $4); }
	| IFN operand_expr ',' operand_expr	{ emit_std_opcode(0xd, $2, $4); }
	| IFG operand_expr ',' operand_expr	{ emit_std_opcode(0xe, $2, $4); }
	| IFB operand_expr ',' operand_expr	{ emit_std_opcode(0xf, $2, $4); }
	| JSR operand_expr					{ emit_ext_opcode(0x1,$2);		}
%%
