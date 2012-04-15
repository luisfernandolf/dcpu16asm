#ifndef _DCPU16ASM_H_
#define _DCPU16ASM_H_
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <malloc.h>


void setoutput(FILE* f);

typedef struct s_symbol {
	struct s_symbol* next;
	int val;
	char name[1];
} t_symbol;

typedef struct s_operand {
	uint16_t code;
	int offset;
} t_operand;

// emit code out
void emit_ext_opcode(int op, t_operand a);
void emit_std_opcode(int op, t_operand a, t_operand b); 
void emit_word(int data);
void emit_byte(int data);
void emit_origin(int pc); 
void emit_raw_start();
void emit_raw_end();
int emit_pc(); 
void emit_init();

int yylex();
t_symbol* lookup(const char* name);
t_symbol* install(const char* name, int value);

char* tmpbuffer(unsigned long size);
void *erealloc (void *oldblock, unsigned long size);
#define emalloc(size) erealloc(NULL,size)
void efree(void* block);

void write_intel_hex(FILE* out);


int yylex();
int yyparse();
int yyinput();
void yyerror(const char *);
extern int lineno;
extern int colno;
extern FILE *yyin;  // the input stream

void syntaxerror (char *s);


#endif