%option noyywrap stack never-interactive
%{
	#include "dcpu16.h"
	#include "parser.h"
	#include <malloc.h>
	#include <io.h>       // isatty
	#include <assert.h>	

	//#define token(x) (x)
	#define token(x) (count(yytext),(x))
	long char_lit_val = -1;
	int str_or_char = 0;
%}
UCN (\\u[0-9a-fA-F]{4}|\\U[0-9a-fA-F]{8})
CHAR \'([^'\\]|\\['"?\\abfnrtv]|\\[0-7]{1,3}|\\[Xx][0-9a-fA-F]+|{UCN})+\'
STR  \"([^"\\]|\\['"?\\abfnrtv]|\\[0-7]{1,3}|\\[Xx][0-9a-fA-F]+|{UCN})*\"
IDENT    ([_a-zA-Z]|{UCN})([_a-zA-Z0-9]|{UCN})*

WSPACE   [ \t\r]+

%x comment_block
%x comment_line
%%
[\#\,\:\+\=\(\)\*\-\[\]]		{ return token(yytext[0]); }
	 
".EQU"			{ return token(EQU); }
".BYTE"			{ return token(BYTE); }
".WORD"			{ return token(WORD); }
".ORIGIN"		{ return token(ORGIN); }
"SET" 			{  return token(SET); }
"ADD" 			{  return token(ADD); }
"SUB" 			{  return token(SUB); }
"MUL" 			{  return token(MUL); }
"DIV" 			{  return token(DIV); }
"MOD" 			{  return token(MOD); }
"SHL" 			{  return token(SHL); }
"SHR" 			{  return token(SHR); }
"AND" 			{  return token(AND); }
"BOR" 			{  return token(BOR); }
"XOR" 			{  return token(XOR); }
"IFE" 			{  return token(IFE); }
"IFN" 			{  return token(IFN); }
"IFG"			{  return token(IFG); }
"IFB" 			{  return token(IFB); }
"JSR" 			{  return token(JSR); }
"POP" 			{  return token(REG_POP); }
"PEEK" 			{  return token(REG_PEEK); }
"PUSH" 			{  return token(REG_PUSH); }
"SP"			{  return token(REG_SP); }
"PC"			{  return token(REG_PC); }
"A"				{  return token(REG_A); }
"B"				{  return token(REG_B); }
"C"				{  return token(REG_C); }
"X"				{  return token(REG_X); }
"Y"				{  return token(REG_Y); }
"Z"				{  return token(REG_Z); }
"I"				{  return token(REG_I); }
"J"				{  return token(REG_J); }
"O"				{  return token(REG_O); }

"//"|";"        {  BEGIN(comment_line); }
<comment_line>{
     \n			{   BEGIN(INITIAL); return token(EOL); }
     [^\n]+     {  }
     "/"        {  }
}

"/*"		   {  BEGIN(comment_block); }
<comment_block>{
     "*/"      {  BEGIN(INITIAL); }
     [^*\n]+   {  }
     "*"       {  }
     \n        {  }
}



[a-zA-Z][a-zA-Z0-9]*	{	 
							yylval._ident = tagstr(yytext);
							return token(IDENT);  
						}
0[Xx][0-9a-fA-F]+		{  sscanf(yytext, "%x", &yylval._num); return token(NUMBER); }
[1-9][0-9]*|[0-9]		{  yylval._num = atoi(yytext); return token(NUMBER); }

[ \t]					{  } /* ignore whitespace */
"\n"					{  return token(EOL); }
<<EOF>>					{ return EOFILE;  }

.			return 0; 
%%
