%option noyywrap nodefault
%{
	
	
	#include <string.h>
	#include <io.h>       // isatty
	//#ifdef MSVC
	//#define  isatty _isatty  // for some reason isatty is called _isatty in VC..
	//#endif
	#ifndef _cplusplus
		#define yyinput input
	#endif
	#include <stdio.h>
	#include <stdlib.h>
	#include <assert.h>
	#include "dcpu16asm.h"
	#include "dcpu16asm_parser.h"

	void count();
	///int show_token(int op, const char * txt, YYSTYPE * lval);
	//#define token(x) show_token(x,yytext,&yylval)
	#define token(x) (x)

	void EatComment();
	void Identifier();
	void StringConstant();
	int crtlf = '\n';
%}
UCN (\\u[0-9a-fA-F]{4}|\\U[0-9a-fA-F]{8})
CHAR \'([^'\\]|\\['"?\\abfnrtv]|\\[0-7]{1,3}|\\[Xx][0-9a-fA-F]+|{UCN})+\'
STR  \"([^"\\]|\\['"?\\abfnrtv]|\\[0-7]{1,3}|\\[Xx][0-9a-fA-F]+|{UCN})*\"
IDENT    ([_a-zA-Z]|{UCN})([_a-zA-Z0-9]|{UCN})*

WSPACE   [ \t\r]+


%%
[\#\,\:\+\=\(\)\*\-\[\]]		{ count(); return token(yytext[0]); }
	 
".EQU"			{ count(); return token(EQU  ); }
".BYTE"			{ count(); return token(BYTE  ); }
".WORD"			{ count(); return token(WORD  ); }
".ORIGIN"		{ count(); return token(ORGIN); }
"SET" 			{ count(); return token(SET     ); }
"ADD" 			{ count(); return token(ADD     ); }
"SUB" 			{ count(); return token(SUB    ); }
"MUL" 			{ count(); return token(MUL    ); }
"DIV" 			{ count(); return token(DIV    ); }
"MOD" 			{ count(); return token(MOD      ); }
"SHL" 			{ count(); return token(SHL  ); }
"SHR" 			{ count(); return token(SHR  ); }
"AND" 			{ count(); return token(AND      ); }
"BOR" 			{ count(); return token(BOR    ); }
"XOR" 			{ count(); return token(XOR      ); }
"IFE" 			{ count(); return token(IFE     ); }
"IFN" 			{ count(); return token(IFN     ); }
"IFG"			{ count(); return token(IFG   ); }
"IFB" 			{ count(); return token(IFB  ); }
"JSR" 			{ count(); return token(JSR  ); }
"POP" 			{ count(); return token(REG_POP  ); }
"PEEK" 			{ count(); return token(REG_PEEK ); }
"PUSH" 			{ count(); return token(REG_PUSH  ); }
"SP"			{ count(); return token(REG_SP ); }
"PC"			{ count(); return token(REG_PC   ); }
"A"				{ count(); return token(REG_A    ); }
"B"				{ count(); return token(REG_B    ); }
"C"				{ count(); return token(REG_C    ); }
"X"				{ count(); return token(REG_X    ); }
"Y"				{ count(); return token(REG_Y     ); }
"Z"				{ count(); return token(REG_Z    ); }
"I"				{ count(); return token(REG_I   ); }
"J"				{ count(); return token(REG_J    ); }
"O"				{ count(); return token(REG_O    ); }


[a-zA-Z][a-zA-Z0-9]*	{ count(); Identifier(); return LABEL;  }
0[Xx][0-9a-fA-F]+		{ count(); yylval.num = (int)strtol(yytext,NULL,16); return NUMBER; }
[1-9][0-9]*|[0-9]		{ count(); yylval.num = (int)strtol(yytext,NULL,10); return NUMBER; }

";".*			{ count();return token(EOL  ); }
[ \t]			{ count(); } /* ignore whitespace */
"\n"			{ count(); return token(EOL); }

.				{ return ERROR;   }

%%

void EatComment()  {
	char c;
	while ((c = yyinput()) != '\n' && c != 0);
	lineno++;
}

// Pass the id name
void Identifier ()  {
	yylval.ident = lookup(yytext);
	if(yylval.ident == NULL)
		yylval.ident = install(yytext,0);
}

void StringConstant()  {
   int l = strlen(yytext)-2;
   yylval.str = tmpbuffer(l+1);
   strncpy (yylval.str, &yytext[1], l); 
   yylval.str[l] = 0;
}	

void count()
{
	int i = 0;
	for (i = 0; yytext[i]; i++)
       {
         if (yytext[i] == '\n')        { colno = 0;   lineno++; }
         else if (yytext[i] == '\t')   colno += 8 - (colno % 8);
         else                          colno++;
       }
}	



