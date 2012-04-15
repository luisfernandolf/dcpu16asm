#include "dcpu16asm.h"
#include <string.h>
#include <malloc.h>

static t_symbol *symlist = NULL;
static unsigned long buffsize = 0;
static char* buffer = NULL;

  void printsymlist(const char* filename)
  {




  }

  
  void *erealloc (void *oldblock, unsigned long size)
{
  void *block;
  size_t s = (size_t)size;
  if (s != size)
    yyerror("Allocation Error: Block too big");
  block = oldblock ? realloc(oldblock, s) : malloc(s);
  if (block == NULL)
    yyerror("not enough memory");
  return block;
}
char* tmpbuffer (unsigned long size)
{
	if (size > buffsize) buffer = (char*)erealloc(buffer, buffsize=size);
	return buffer;
}


void efree (void *block)
{
  if (block)
  {
    *((int *)block) = -1;  /* to catch errors */
    free(block);
  }
}





t_symbol* lookup(const char* name)
{
	t_symbol* sp = NULL;
	for(sp = symlist; sp != NULL; sp = sp->next)
		if(!strcmp(sp->name,name))
			return sp;
	return NULL;
}

t_symbol* install(const char* name, int value)
{
	t_symbol* sp;
	sp = (t_symbol*)emalloc(sizeof(char) * (strlen(name)) + sizeof(t_symbol));
	sp->val = value;
	strcpy(sp->name,name);

	sp->next = symlist;
	symlist = sp;
	return sp;
}


