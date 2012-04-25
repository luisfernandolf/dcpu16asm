#include "dcpu16.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

typedef struct s_symbol {
	int type;
	tag name;
	union {
		int val;
		int token;
	} u;
	struct s_symbol* next;  // For chaining.
	struct s_symbol* allnext;  // For chaining.
} symbol;

enum 
{
	SYM_UNDEF=0,
	SYM_TOKEN,
	SYM_STRING,
	SYM_NUMBER
};
// hacks to get at the hash and len compoents of tags without having 
// to expose the under tag structure
#define uintptr(p)  ((uint32_t)(void*)(p))
static uint32_t hashptr(uint32_t a) 
{
	a = (a+0x7ed55d16) + (a<<12);
    a = (a^0xc761c23c) ^ (a>>19);
    a = (a+0x165667b1) + (a<<5);
    a = (a+0xd3a2646c) ^ (a<<9);
    a = (a+0xfd7046c5) + (a<<3);
    a = (a^0xb55a4f09) ^ (a>>16);
    return a;
}
/* simple symtab of fixed size */
#define NHASH 9997
static symbol* _symall = NULL;
static symbol* _symall_last = NULL;
static symbol** _symtab = NULL;
static int _symtab_alloc = 0;
static int _nsym = 0;
/* list of symbols, for an argument list */

static void _check_symtab() {
	if(!_symtab) { 
		_symtab = (symbol**)malloc(sizeof(symbol*) * NHASH);
		assert(_symtab);
		memset(_symtab,0,sizeof(symbol*) * NHASH);
		_symtab_alloc = NHASH;
		_nsym = 0;
	}
}

static symbol* _sym_hlookup(tag name, uint32_t h) {
	symbol *t = 0;
	_check_symtab();
	t = _symtab[h % _symtab_alloc];
	while(t && !tagcmp(t->name,name)) t = t->next;
	if(t) return t;	
	// make a new symbol undefined of course
	t = (symbol*)malloc(sizeof(symbol));
	t->type = SYM_UNDEF;
	t->name = name;
	t->next = _symtab[h % _symtab_alloc];
	_symtab[h % _symtab_alloc] = t;
	if(!_symall) { 
		_symall = t;
		_symall->allnext = NULL;
		_symall_last = t;
	} else {
		_symall_last->allnext = t;
		t->allnext = NULL;
		_symall_last = t;
	}
	return t;
}
int sym_list(FILE * f) {
	int ret = 0;
	symbol* s = _symall;
	while(s) {
		ret += fprintf(f,"%4.4x: %s\n",s->name,s->u.val);
		s = s->allnext;
	}
	return ret;
}

int sym_lookup(tag name) {
	symbol *sp = _sym_hlookup(name,hashptr(uintptr(name)));
	switch(sp->type)
	{
	case SYM_TOKEN: 
		return sp->u.token;
	case SYM_NUMBER: 
		return sp->u.val;
	default:
		yyerror("Symbol %s Not defined!");
		fatal_error(1);
	}
}
	
int sym_tok(tag name, int token) {
	uint32_t h = hashptr(uintptr(name));
	symbol *sp = _sym_hlookup(name,hashptr(uintptr(name)));
	if(sp->type != SYM_UNDEF) return -1; // sorry pointer exists  Cannot change a const token
	sp->type = SYM_TOKEN;
	sp->u.token = token;
	return token;
}

int sym_val(tag name, int val) {
	uint32_t h = hashptr(uintptr(name));
	symbol *sp = _sym_hlookup(name,hashptr(uintptr(name)));
	if(sp->type == SYM_TOKEN) return -1; // sorry pointer exists  Cannot change a const token
	sp->type = SYM_NUMBER;
	sp->u.val = val;
	return val;
}

