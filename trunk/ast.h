#ifndef  _AST_H_
#define _AST_H_
#include "strtable.h"
#include <stdint.h>

enum { 
	AST_NUMBER,
	AST_NAME,
	AST_DATA,
	AST_UMINUS
};

typedef struct s_ast {
	int type;
	union {
		struct { struct s_ast *l; struct s_ast *r; } exp;
		struct { size_t len; uint8_t* dat; } data;
		tag name;
		int num;
	} v;
} ast;
#define ast_isnum(a) ((a)->type == AST_NUMBER)

ast *ast_new(int op, ast *l, ast *r);
ast *ast_num(int num);
ast *ast_name(tag name);
ast *ast_dat(uint8_t* data, size_t len);

int ast_eval(ast * a);
void ast_free(ast * a);


#endif