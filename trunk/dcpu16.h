#ifndef _DCPU16_H_
#define _DCPU16_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "strtable.h"
#include "ast.h"

extern FILE* errAsm;

// Symbol lookups
int sym_tok(tag name, int token);
int sym_val(tag name, uint16_t val);
int sym_lookup(tag name);
int sym_list(FILE * f);
// Arg list
typedef struct s_arglist {
	int type;
	struct s_arglist *next;
	union {
		ast* val;
		struct { size_t len; uint8_t* dat; } data;
	} v;
} arg;

arg* arg_list(arg* a, arg* next);
arg* arg_array(uint8_t* data, size_t len);
arg* arg_expr(ast* expr);

typedef struct  { int code; ast* expr; } Operand;
#define operand_code(o) ((void)assert((o) >= 0 && (o) <= 0x3f),o & 0x3f)

typedef struct  {
	int code;
	Operand     a;    // oerand 1
	Operand     b;    // oerand 2
} Opcode;

typedef struct s_Line {
	int type;
	int lineno;
	uint16_t pc;
	struct s_Line* next;
	union {
		Opcode opcode;
		struct { size_t len; uint16_t* dat; } data;
		int origin;
	} v;
} Line;

uint16_t line_current_pc();
Line* line_origin(int origin);
Line* line_opcode(Opcode opcode);
Line* line_bytes(arg* args);
Line* line_words(arg* args);
void pushline(Line * line);

int line_binary(FILE * f); 
int line_list(FILE * f);
int line_intel_hex(FILE * f);

int yylex();

void write_intel_hex(FILE* out);

// General error display.  It wil print the line and col number of the error
void yyerror(const char *,...);
// This will also print the line and coll with "fatel error" message.  Run after yyerror.
void fatal_error(int i);
// This will take a string and count the amount of char and increase line/col in it
void count(const char* str);

extern FILE *yyin;  // the input stream
int yyparse();

#endif