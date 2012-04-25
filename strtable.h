#ifndef _STRTABLE_H_
#define _STRTABLE_H_

#include <string.h>
#include <stdint.h>

typedef const char* tag;

#define tagcmp(a,b) ((a) == (b))
tag taglstr(const char* str, size_t l);
tag tagstr(const char* str);
void init_strtable();

typedef struct s_vec {
	char _initb[512];
	char *buffer;  /* buffer address */
	size_t allocated;
	size_t size;  
	int lastc;
} t_vec;

char* vec_init();
char* vec_buff();
int vec_len();
void vec_pushbyte(uint8_t b);
void vec_pushword(uint16_t w);
char* vec_strdup();
void vec_pushstr(const char* s);
void vec_pushlstr(const char* s, size_t l);
void vec_sprintf(const char* fmt, ...);
int vec_putc(int c);
int vec_getc();
int vec_ungetc();
void vec_replace(char (*func)(char));

#endif