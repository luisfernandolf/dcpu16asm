%option noyywrap stack never-interactive yylineno case-insensitive
%{
	#include "dcpu16.h"
	#include "parser.h"
	#include <malloc.h>
	#include <io.h>       // isatty
	#include <assert.h>	

	//#define token(x) (x)
	#define token(x) ((x))
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
%x strlit
%x chrlit
%%
[\#\,\:\+\=\(\)\*\-\[\]]		{ return token(yytext[0]); }
	 
"EQU"			{ return token(EQU); }
"DB"			{ return token(BYTE); }
"DW"			{ return token(WORD); }
"ORG"		    { return token(ORGIN); }

"SET" 			{  return token(SET); }
"ADD" 			{  return token(ADD); }
"SUB" 			{  return token(SUB); }
"MUL" 			{  return token(MUL); }
"MUI" 			{  return token(MUI); }
"DIV" 			{  return token(DIV); }
"DVI" 			{  return token(DVI); }
"MOD" 			{  return token(MOD); }
"AND" 			{  return token(AND); }
"BOR" 			{  return token(BOR); }
"XOR" 			{  return token(XOR); }
"SHR" 			{  return token(SHR); }
"ASR" 			{  return token(ASR); }
"SHL" 			{  return token(SHL); }
"IFB" 			{  return token(IFB); }
"IFC" 			{  return token(IFC); }
"IFE" 			{  return token(IFE); }
"IFN" 			{  return token(IFN); }
"IFG"			{  return token(IFG); }
"IFA" 			{  return token(IFA); }
"IFL" 			{  return token(IFL); }
"IFU" 			{  return token(IFU); }
"ADX" 			{  return token(ADX); }
"SUX" 			{  return token(SUX); }

"JSR" 			{  return token(JSR); }
"INT" 			{  return token(INT); }
"ING" 			{  return token(ING); }
"INS" 			{  return token(INS); }
"HWQ" 			{  return token(HWQ); }
"HWN" 			{  return token(HWN); }
"HWI" 			{  return token(HWI); }

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
"EX"		    {  return token(REG_EX); }

"POP" 			{  return token(POP);  }
"PEEK" 			{  return token(PEEK); }
"PUSH" 			{  return token(PUSH); }
"PICK"			{  return token(PICK); }

"//"|";"        {  BEGIN(comment_line); }
<comment_line>{
     \n			{   BEGIN(INITIAL);  return token(EOL); }
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
\"                      { vec_init(); BEGIN(strlit); }
<strlit>{
	\"                { BEGIN(INITIAL);
						yylval._string = vec_strdup();
						printf("TEST: %s\n",yylval._string); 
						return token(STRING);  
					  }
	\\\"              { vec_putc('"');     }
	\\a               { vec_putc('\a');    }
	\\b               { vec_putc('\b');    }
	\\f               { vec_putc('\f');    }
	\\n               { vec_putc('\n');    }
	\\r               { vec_putc('\r');    }
	\\t               { vec_putc('\t');    }
	\n                { yyerror("End of line before end of string"); fatal_error(1); return 0;   }
	.                 { vec_putc(*yytext);  }
}
\'					  { yylval._num = 0; BEGIN(chrlit); }
<chrlit>{
	\'                { BEGIN(INITIAL); printf("TEST: %c\n",yylval._num); return token(NUMBER);  }
	\\\'              { yylval._num = '\'';    }
	\\a               { yylval._num = '\a';    }
	\\b               { yylval._num = '\b';    }
	\\f               { yylval._num = '\f';    }
	\\n               { yylval._num = '\n';    }
	\\r               { yylval._num = '\r';    }
	\\t               { yylval._num = '\t';    }
	\n                { yyerror("End of line before end of char"); fatal_error(1); return 0;   }
	.                 { yylval._num = *yytext;  }
}

[a-zA-Z][a-zA-Z0-9]*	{	 
							yylval._ident = tagstr(yytext);
							return token(IDENT);  
						}
0[Xx][0-9a-fA-F]+		{  sscanf(yytext, "%x", &yylval._num); return token(NUMBER); }
[1-9][0-9]*|[0-9]		{  yylval._num = atoi(yytext); return token(NUMBER); }

[ \t]					{  } /* ignore whitespace */
"\n"					{ return token(EOL); }
<<EOF>>					{ return EOFILE;  }

.			            { yyerror("Invalid Token %s", yytext); return 0; }
%%

