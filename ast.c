#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>

int sym_lookup(tag name);

ast *ast_new(int op, ast *l, ast *r) {
	ast * t = (ast*)malloc(sizeof(ast));
	t->type = op;
	t->v.exp.l = l;
	t->v.exp.r = r;
	return t;
}
ast *ast_num(int num) {
	ast * t = (ast*)malloc(sizeof(ast));
	t->type = AST_NUMBER;
	t->v.num = num;
	return t;
}
ast *ast_name(tag name) {
	ast * t = (ast*)malloc(sizeof(ast));
	t->type = AST_NAME;
	t->v.name = name;
	return t;
}
ast *ast_dat(uint8_t* data, size_t len) {
	ast * t = (ast*)malloc(sizeof(ast));
	t->type = AST_DATA;
	t->v.data.dat = (uint8_t*)malloc(sizeof(uint8_t) * len);
	t->v.data.len = len;
	memcpy(t->v.data.dat,data,sizeof(uint8_t) * len);
	return t;

}
int ast_eval(ast *a)
{
	int v=0;
	switch(a->type) {
		case AST_NUMBER: v = a->v.num; break;
		case AST_NAME: 
			v = sym_lookup(a->v.name); 
			if(v==-1) {
				printf("ast_eval: undefined symbol %s\n", a->v.name);
				assert(0);
				exit(0);
			}
				break;
		case '+': v = ast_eval(a->v.exp.l) + ast_eval(a->v.exp.r); break;
		case '-': v = ast_eval(a->v.exp.l) - ast_eval(a->v.exp.r); break;
		case '*': v = ast_eval(a->v.exp.l) * ast_eval(a->v.exp.r); break;
		case '/': v = ast_eval(a->v.exp.l) / ast_eval(a->v.exp.r); break;
		case '%': v = ast_eval(a->v.exp.l) % ast_eval(a->v.exp.r); break;
		case AST_UMINUS: v = -ast_eval(a->v.exp.l); break;
		default: 
			printf("ast_eval: bad node %c\n", a->type);
			assert(0);
			exit(0);
	}
	return v;
}

void ast_free(ast *a) {
	// string table handles all the strings so we just need to free the nodes
	if(a->type != AST_NUMBER && a->type != AST_NAME) {
		if(a->v.exp.l) ast_free(a->v.exp.l);
		free(a->v.exp.l);
		if(a->v.exp.r) ast_free(a->v.exp.r);
		free(a->v.exp.r);
		a->v.exp.r = a->v.exp.l = NULL;
		return;
	} else if(a->type == AST_DATA) {
		free(a->v.data.dat);
		a->v.data.dat = NULL;
		a->v.data.len = 0;
	}
	free(a);
	return;
}