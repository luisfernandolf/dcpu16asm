#include "strtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>

void yyerror(const char * format, ...);

#ifndef MAX_SIZET
#define MAX_SIZET	((size_t)(~(size_t)0)-2)

#define MAX_INT (INT_MAX-2)  /* maximum value of an int (-2 for safety) */
#endif
#define cast(t, exp)	((t)(exp))
//#define lmod(s,size) ((void)(assert((size&(size-1))==0)), cast(int,(s) & ((size)-1)))
#define twoto(x)	(1<<(x))
#define touint(p)  ((unsigned int)(void*)(p))



/*	I would like to thank the people who made Lua(http://www.lua.org)
	I have learned more from reading their code for all their versions than 
	ever in any book or class.  As such, most of this code is copyied from 
	their source.  A little of Lua 5.2, 2.5 and even some 1.1  
*/

#define INIT_VEC_SIZE 512

// In lua 5.2, it dosn't have the str and its a union that aligns the data
// Right now byte alligment isn't that importanet and I am also combining the
// container class with the string and only returning the const char* pointer
// Also, if you havn't figured it out, there is no way to remove strings.
// youve been warnned
#define TABLE_SIZE 1024
typedef struct s_tag_string {
	struct s_tag_string* next;
	size_t len;
	uint32_t hash;
	char str[1];   /* \0 byte already reserved */
} tag_string;

static tag_string** _hash = NULL;
static uint32_t _alloc = 0;
static uint32_t _nuse=0;  /* number of elements */


#define lmod(s) ((void)(assert((TABLE_SIZE&(TABLE_SIZE-1))==0)), cast(int,(s) & ((TABLE_SIZE)-1)))
#define ml_newtag(s)  ((tag_string*)malloc(sizeof(tag_string) + sizeof(char) *(s)))         



static tag_string *_newlstr (const char *str, size_t l, unsigned int h) {
	tag_string *ts;
	if (l+1 > (MAX_SIZET - sizeof(tag_string))/sizeof(char)) 
			{ yyerror("newlstr: trying to make a string bigger than a pointer can hold\n"); exit(1); }
	ts =  ml_newtag(l);
	// add it to the chain
	ts->next = _hash[lmod(h)];
	_hash[lmod(h)] = ts;
	_nuse++;
	// Finaly put the stuff in the new tag string
	ts->len = l;
	ts->hash = h;
	memcpy(ts->str,str,l * sizeof(char));
	ts->str[l] = '\0';
	// return it
	return ts;
}
void init_strtable() { 
	if(!_hash) { // clear table for inital useyyerror
		_alloc = TABLE_SIZE;
		_hash = (tag_string**)malloc(sizeof(tag_string*) * _alloc);
		memset(_hash,0,sizeof(tag_string*) * _alloc);
	}
}

tag taglstr(const char* str, size_t l) {
	tag_string *ts = NULL;
	uint32_t h = cast(uint32_t, l);
	size_t step = (l>>5)+1;  /* if string is too long, don't hash all its chars */
	size_t l1;
	for (l1=l; l1>=step; l1-=step)  /* compute hash */
		h = h ^ ((h<<5)+(h>>2)+cast(unsigned char, str[l1-1]));
	for(ts = _hash[lmod(h)];
		ts != NULL; ts = ts->next) 
			if(h == ts->hash && ts->len == l && (memcmp(str,ts->str,l * sizeof(char))==0))
				return ts->str;
	ts = _newlstr(str,l,h);
	return ts->str;
}

tag tagstr(const char* str) { return taglstr(str,strlen(str)); }


static char *_buff = NULL;  /* buffer address */
static size_t _allocated = 0;
static size_t _size = 0;  


static void _resize(size_t sz)
{
	if(!_buff) { 
		_buff = (char*)malloc(sizeof(char) * 1024); 
		_allocated = 1024; 
	}
	if(_allocated - _size < sz) {
		char* newbuff = NULL;
		size_t newsize = _allocated * 2 + 1;
		if(newsize - _size < sz) newsize = _size + sz + 1;
		_buff = (char*)realloc(_buff,sizeof(char) * newsize);
		_allocated = newsize;
	}
}
static char* _grow(size_t sz) {
	char*b = &_buff[_size];
	_resize(sz + _size);
	_size += sz;
	return b;
}

static int _lastc = EOF;
char* vec_init() { _resize(1024); _size = 0; _buff[0] = '\0'; return _buff; }
char* vec_buff() { return _buff; }
int vec_len() { return _size; }
char* vec_strdup() {
	char* ret = NULL;
	ret = (char*)malloc(sizeof(char) * _size + 1);
	memcpy(ret,_buff,sizeof(char) * _size);
	ret[_size] = '\0';
	return ret;
}
void vec_pushlstr(const char* s, size_t l) {
	memcpy(_grow(l),s,l);
	_buff[_size] = '\0';
}
void vec_pushstr(const char* s) { vec_pushlstr(s,strlen(s)); }

void vec_replace(char (*func)(char)) {
	size_t i=0;
	for(; i < _size; i++)
		_buff[i] = (*func)(_buff[i]);
}

int  vec_putc(int c) {
	if(_size + 1 < _allocated) _grow(2);
	_buff[_size++] = _lastc = (char)c;
	_buff[_size++] = '\0';
	return c;
}
int  vec_getc() {
	_lastc = _size > 0 ? _buff[--_size] : EOF;
	_buff[_size] = '\0';
	return _lastc;
}

int vec_ungetc() {
	if(_lastc == EOF) return EOF;
	return vec_putc(_lastc);
}
void vec_pushbyte(uint8_t b) {
	uint8_t* a = (uint8_t*)_grow(sizeof(uint8_t));
	*a = b;
}
void vec_pushword(uint16_t w) {
	uint16_t* a = (uint8_t*)_grow(sizeof(uint16_t));
	*a = w;
}

void vec_sprintf(const char* fmt, ...) {
	va_list va;
	int n = 0, f = 0, size = 0;
	char * b = NULL;
	// Get the size first
	b = _buff + _size;
	size = _allocated - _size;
	va_start(va,fmt);
	n = vsnprintf(b, size ,fmt,va) + 1;
	va_end(va);
	if(n  < size) return;

	_grow(n);
	va_start(va,fmt);
	f = n = vsnprintf(b, size ,fmt,va);
	va_end(va);
	assert(n == f);
}
