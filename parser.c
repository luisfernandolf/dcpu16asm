
/*  A Bison parser, made from dcpu16.bison with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	SET	258
#define	ADD	259
#define	SUB	260
#define	MUL	261
#define	MUI	262
#define	DIV	263
#define	DVI	264
#define	MOD	265
#define	AND	266
#define	BOR	267
#define	XOR	268
#define	SHR	269
#define	ASR	270
#define	SHL	271
#define	IFB	272
#define	IFC	273
#define	IFE	274
#define	IFN	275
#define	IFG	276
#define	IFA	277
#define	IFL	278
#define	IFU	279
#define	ADX	280
#define	SUX	281
#define	JSR	282
#define	INT	283
#define	ING	284
#define	INS	285
#define	HWN	286
#define	HWQ	287
#define	HWI	288
#define	ORGIN	289
#define	WORD	290
#define	BYTE	291
#define	EQU	292
#define	NUMBER	293
#define	IDENT	294
#define	EOL	295
#define	EOFILE	296
#define	ERROR	297
#define	REG_A	298
#define	REG_B	299
#define	REG_C	300
#define	REG_X	301
#define	REG_Y	302
#define	REG_Z	303
#define	REG_I	304
#define	REG_J	305
#define	REG_SP	306
#define	REG_EX	307
#define	REG_PC	308
#define	PEEK	309
#define	POP	310
#define	PICK	311
#define	PUSH	312
#define	STRING	313
#define	UMINUS	314

#line 1 "dcpu16.bison"

	#include "dcpu16.h"
	#include <io.h>
	#include <malloc.h>
	#include <assert.h>
	

	#define YY_NO_UNISTD_H 
	#define YYDEBUG 1

#line 18 "dcpu16.bison"
typedef union
{
	uint16_t _code;
	int _num;
	tag _ident;
	char* _string;
	Operand  _operand;
	Opcode _opcode;
	ast* _expr;
	Line * _line;
	arg* _args;
} YYSTYPE;

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYDEBUG
#define YYDEBUG 1
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		131
#define	YYFLAG		-32768
#define	YYNTBASE	72

#define YYTRANSLATE(x) ((unsigned)(x) <= 314 ? yytranslate[x] : 84)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,    64,     2,     2,    70,
    71,    62,    60,    67,    61,     2,    63,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    66,     2,     2,
    59,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    68,     2,    69,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    65
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     5,     8,    10,    15,    20,    25,    29,    32,
    35,    39,    42,    45,    48,    51,    54,    56,    58,    60,
    64,    68,    70,    72,    74,    76,    78,    80,    82,    84,
    86,    90,    96,   102,   104,   106,   108,   112,   115,   121,
   123,   125,   127,   131,   133,   135,   137,   139,   141,   143,
   145,   147,   149,   151,   153,   155,   157,   159,   161,   163,
   165,   167,   169,   171,   173,   175,   177,   179,   181,   183,
   185,   187,   189,   191,   193,   195,   200,   203,   207,   211,
   215,   219,   223,   227,   230,   232
};

static const short yyrhs[] = {    73,
    41,     0,    74,     0,    73,    74,     0,    40,     0,    39,
    59,    83,    40,     0,    39,    37,    83,    40,     0,    75,
    34,    83,    40,     0,    34,    83,    40,     0,    75,    40,
     0,    76,    40,     0,    75,    76,    40,     0,    83,    40,
     0,    39,    66,     0,    66,    39,     0,    35,    77,     0,
    36,    77,     0,    82,     0,    58,     0,    83,     0,    58,
    67,    77,     0,    83,    67,    77,     0,    43,     0,    44,
     0,    45,     0,    46,     0,    47,     0,    48,     0,    49,
     0,    50,     0,    78,     0,    68,    78,    69,     0,    68,
    78,    60,    83,    69,     0,    68,    83,    60,    78,    69,
     0,    57,     0,    55,     0,    54,     0,    68,    51,    69,
     0,    56,    83,     0,    68,    51,    60,    83,    69,     0,
    51,     0,    53,     0,    52,     0,    68,    83,    69,     0,
    83,     0,    27,     0,    28,     0,    29,     0,    30,     0,
    31,     0,    32,     0,    33,     0,     3,     0,     4,     0,
     5,     0,     6,     0,     7,     0,     8,     0,     9,     0,
    10,     0,    11,     0,    12,     0,    13,     0,    14,     0,
    15,     0,    16,     0,    17,     0,    18,     0,    19,     0,
    20,     0,    21,     0,    22,     0,    23,     0,    24,     0,
    25,     0,    26,     0,    81,    79,    67,    79,     0,    80,
    79,     0,    83,    60,    83,     0,    83,    61,    83,     0,
    83,    62,    83,     0,    83,    63,    83,     0,    83,    64,
    83,     0,    70,    83,    71,     0,    61,    83,     0,    38,
     0,    39,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    51,    58,    59,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    74,    75,    78,    79,    80,    83,    84,    85,
    86,    91,    92,    93,    94,    95,    96,    97,    98,   102,
   103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
   113,   114,   115,   116,   120,   121,   122,   123,   124,   125,
   126,   129,   130,   131,   132,   133,   134,   135,   136,   137,
   138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
   148,   149,   150,   151,   152,   156,   157,   160,   161,   162,
   163,   164,   165,   166,   167,   168
};

static const char * const yytname[] = {   "$","error","$undefined.","SET","ADD",
"SUB","MUL","MUI","DIV","DVI","MOD","AND","BOR","XOR","SHR","ASR","SHL","IFB",
"IFC","IFE","IFN","IFG","IFA","IFL","IFU","ADX","SUX","JSR","INT","ING","INS",
"HWN","HWQ","HWI","ORGIN","WORD","BYTE","EQU","NUMBER","IDENT","EOL","EOFILE",
"ERROR","REG_A","REG_B","REG_C","REG_X","REG_Y","REG_Z","REG_I","REG_J","REG_SP",
"REG_EX","REG_PC","PEEK","POP","PICK","PUSH","STRING","'='","'+'","'-'","'*'",
"'/'","'%'","UMINUS","':'","','","'['","']'","'('","')'","all","lines","line",
"label","macro","datseq","operand_regester","operand_expr","opcode_expr_single",
"opcode_expr_double","opcode_expr","expr",""
};
#endif

static const short yyr1[] = {     0,
    72,    73,    73,    74,    74,    74,    74,    74,    74,    74,
    74,    74,    75,    75,    76,    76,    76,    77,    77,    77,
    77,    78,    78,    78,    78,    78,    78,    78,    78,    79,
    79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
    79,    79,    79,    79,    80,    80,    80,    80,    80,    80,
    80,    81,    81,    81,    81,    81,    81,    81,    81,    81,
    81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
    81,    81,    81,    81,    81,    82,    82,    83,    83,    83,
    83,    83,    83,    83,    83,    83
};

static const short yyr2[] = {     0,
     2,     1,     2,     1,     4,     4,     4,     3,     2,     2,
     3,     2,     2,     2,     2,     2,     1,     1,     1,     3,
     3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     3,     5,     5,     1,     1,     1,     3,     2,     5,     1,
     1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     4,     2,     3,     3,     3,
     3,     3,     3,     2,     1,     1
};

static const short yydefact[] = {     0,
    52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    75,    45,    46,    47,    48,    49,    50,
    51,     0,     0,     0,    85,    86,     4,     0,     0,     0,
     0,     2,     0,     0,     0,     0,    17,     0,    86,     0,
    18,    15,    19,    16,     0,     0,    13,    84,    14,     0,
     1,     3,     0,     9,     0,    10,    22,    23,    24,    25,
    26,    27,    28,    29,    40,    42,    41,    36,    35,     0,
    34,     0,    30,    77,    44,     0,    12,     0,     0,     0,
     0,     0,     8,     0,     0,     0,     0,    83,     0,    11,
    38,     0,     0,     0,     0,    78,    79,    80,    81,    82,
    20,    21,     6,     5,     7,     0,    37,     0,    31,     0,
    43,    76,     0,     0,     0,    39,    32,    33,     0,     0,
     0
};

static const short yydefgoto[] = {   129,
    41,    42,    43,    44,    52,    83,    84,    45,    46,    47,
    53
};

static const short yypact[] = {   186,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,    -4,   -11,   -11,-32768,    -8,-32768,    -4,   -36,    -4,
   118,-32768,   254,   -34,   -31,   -31,-32768,     8,-32768,    13,
   -57,-32768,   177,-32768,    -4,    -4,-32768,-32768,-32768,    33,
-32768,-32768,    -4,-32768,    -9,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    -4,
-32768,   253,-32768,-32768,    51,   -23,-32768,    -4,    -4,    -4,
    -4,    -4,-32768,   -11,   -11,    38,    46,-32768,   265,-32768,
    51,   -58,   -17,   100,   -31,    21,    21,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,    -4,-32768,    -4,-32768,   272,
-32768,-32768,   111,   167,   -60,-32768,-32768,-32768,    36,    49,
-32768
};

static const short yypgoto[] = {-32768,
-32768,    19,-32768,   -10,   -33,   -78,   -41,-32768,-32768,-32768,
     0
};


#define	YYLAST		342


static const short yytable[] = {    48,
    54,   116,    59,   103,    86,    66,    35,    49,   128,    94,
   117,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    35,    49,    55,    38,
   100,    50,    65,    35,    49,   130,    82,    58,    40,    60,
    48,   125,   118,   105,    85,    85,    51,    87,   131,    38,
    56,   119,    93,     0,    96,    97,    38,    57,    40,    62,
   111,   112,    99,   122,     0,    40,     0,    88,    89,    90,
    91,    92,    88,    89,    90,    91,    92,   113,     0,   101,
     0,   104,    90,    91,    92,   114,     0,   106,   107,   108,
   109,   110,    88,    89,    90,    91,    92,    88,    89,    90,
    91,    92,     0,    98,    85,    88,    89,    90,    91,    92,
    88,    89,    90,    91,    92,   123,     0,   124,     0,   106,
     1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
    11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
    31,    32,    33,    34,     0,    35,    36,    37,    61,   120,
    89,    90,    91,    92,     0,     0,     0,     0,   121,     0,
    88,    89,    90,    91,    92,     0,     0,     0,    38,   126,
     0,     0,     0,    39,     0,     0,     0,    40,     1,     2,
     3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
    13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
    23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,     0,    35,    36,    37,    88,    89,    90,    91,
    92,     0,     0,     0,     0,   127,    88,    89,    90,    91,
    92,     0,     0,    95,     0,     0,    38,     0,     0,     0,
     0,    39,     0,     0,     0,    40,     1,     2,     3,     4,
     5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
    15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
    25,    26,    27,    28,    29,    30,    31,    63,    33,    34,
    35,    49,     0,    64,     0,    67,    68,    69,    70,    71,
    72,    73,    74,   102,   115,     0,     0,     0,     0,    35,
    49,     0,     0,    38,    67,    68,    69,    70,    71,    72,
    73,    74,    40,     0,    88,    89,    90,    91,    92,     0,
     0,     0,    38,     0,     0,     0,     0,     0,     0,     0,
     0,    40
};

static const short yycheck[] = {     0,
    34,    60,    39,    82,    46,    40,    38,    39,    69,    67,
    69,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,    53,    54,    55,    56,    57,    38,    39,    37,    61,
    40,    32,    43,    38,    39,     0,    68,    38,    70,    40,
    41,   120,    60,    67,    45,    46,    58,    40,     0,    61,
    59,    69,    40,    -1,    55,    56,    61,    66,    70,    41,
    94,    95,    63,   105,    -1,    70,    -1,    60,    61,    62,
    63,    64,    60,    61,    62,    63,    64,    40,    -1,    80,
    -1,    82,    62,    63,    64,    40,    -1,    88,    89,    90,
    91,    92,    60,    61,    62,    63,    64,    60,    61,    62,
    63,    64,    -1,    71,   105,    60,    61,    62,    63,    64,
    60,    61,    62,    63,    64,   116,    -1,   118,    -1,   120,
     3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
    13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
    23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    -1,    38,    39,    40,    41,    60,
    61,    62,    63,    64,    -1,    -1,    -1,    -1,    69,    -1,
    60,    61,    62,    63,    64,    -1,    -1,    -1,    61,    69,
    -1,    -1,    -1,    66,    -1,    -1,    -1,    70,     3,     4,
     5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
    15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
    25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    -1,    38,    39,    40,    60,    61,    62,    63,
    64,    -1,    -1,    -1,    -1,    69,    60,    61,    62,    63,
    64,    -1,    -1,    67,    -1,    -1,    61,    -1,    -1,    -1,
    -1,    66,    -1,    -1,    -1,    70,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    38,    39,    -1,    40,    -1,    43,    44,    45,    46,    47,
    48,    49,    50,    51,    40,    -1,    -1,    -1,    -1,    38,
    39,    -1,    -1,    61,    43,    44,    45,    46,    47,    48,
    49,    50,    70,    -1,    60,    61,    62,    63,    64,    -1,
    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    70
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 52 "dcpu16.bison"
{
	    return 0;
	  ;
    break;}
case 2:
#line 58 "dcpu16.bison"
{	pushline(yyvsp[0]._line); ;
    break;}
case 3:
#line 59 "dcpu16.bison"
{	pushline(yyvsp[0]._line); ;
    break;}
case 4:
#line 63 "dcpu16.bison"
{ yyval._line =  0; ;
    break;}
case 5:
#line 64 "dcpu16.bison"
{ yyval._line = 0; sym_val(yyvsp[-3]._ident, ast_eval(yyvsp[-1]._expr)); ;
    break;}
case 6:
#line 65 "dcpu16.bison"
{ yyval._line = 0; sym_val(yyvsp[-3]._ident, ast_eval(yyvsp[-1]._expr)); ;
    break;}
case 7:
#line 66 "dcpu16.bison"
{ yyval._line = line_origin(ast_eval(yyvsp[-1]._expr)); sym_val(yyvsp[-3]._ident, line_current_pc()); ;
    break;}
case 8:
#line 67 "dcpu16.bison"
{ yyval._line = line_origin(ast_eval(yyvsp[-1]._expr)); ;
    break;}
case 9:
#line 68 "dcpu16.bison"
{ yyval._line = 0; ;
    break;}
case 10:
#line 69 "dcpu16.bison"
{ yyval._line = yyvsp[-1]._line; ;
    break;}
case 11:
#line 70 "dcpu16.bison"
{ yyval._line = yyvsp[-1]._line; ;
    break;}
case 12:
#line 71 "dcpu16.bison"
{ yyval._line = 0;  ;
    break;}
case 13:
#line 74 "dcpu16.bison"
{ yyval._ident = yyvsp[-1]._ident;  sym_val(yyvsp[-1]._ident, line_current_pc()); ;
    break;}
case 14:
#line 75 "dcpu16.bison"
{ yyval._ident = yyvsp[0]._ident;  sym_val(yyvsp[0]._ident, line_current_pc()); ;
    break;}
case 15:
#line 78 "dcpu16.bison"
{ yyval._line = line_words(yyvsp[0]._args);  ;
    break;}
case 16:
#line 79 "dcpu16.bison"
{ yyval._line = line_bytes(yyvsp[0]._args);  ;
    break;}
case 17:
#line 80 "dcpu16.bison"
{ yyval._line = line_opcode(yyvsp[0]._opcode); ;
    break;}
case 18:
#line 83 "dcpu16.bison"
{ yyval._args = arg_array((uint8_t*)yyvsp[0]._string,strlen(yyvsp[0]._string));  ;
    break;}
case 19:
#line 84 "dcpu16.bison"
{ yyval._args = arg_expr(yyvsp[0]._expr);   ;
    break;}
case 20:
#line 85 "dcpu16.bison"
{ yyval._args = arg_array((uint8_t*)yyvsp[-2]._string,strlen(yyvsp[-2]._string)); yyval._args->next = yyvsp[0]._args;  ;
    break;}
case 21:
#line 86 "dcpu16.bison"
{ yyval._args = arg_expr(yyvsp[-2]._expr); yyval._args->next = yyvsp[0]._args;    ;
    break;}
case 22:
#line 91 "dcpu16.bison"
{ yyval._code = 0; ;
    break;}
case 23:
#line 92 "dcpu16.bison"
{ yyval._code = 1;  ;
    break;}
case 24:
#line 93 "dcpu16.bison"
{ yyval._code = 2;  ;
    break;}
case 25:
#line 94 "dcpu16.bison"
{ yyval._code = 3;  ;
    break;}
case 26:
#line 95 "dcpu16.bison"
{ yyval._code = 4;  ;
    break;}
case 27:
#line 96 "dcpu16.bison"
{ yyval._code = 5;  ;
    break;}
case 28:
#line 97 "dcpu16.bison"
{ yyval._code = 6;  ;
    break;}
case 29:
#line 98 "dcpu16.bison"
{ yyval._code = 7;  ;
    break;}
case 30:
#line 102 "dcpu16.bison"
{ yyval._operand.code = yyvsp[0]._code;		yyval._operand.expr = NULL;		;
    break;}
case 31:
#line 103 "dcpu16.bison"
{ yyval._operand.code = yyvsp[-1]._code + 8;	yyval._operand.expr = NULL;		;
    break;}
case 32:
#line 104 "dcpu16.bison"
{ yyval._operand.code = yyvsp[-3]._code + 16; yyval._operand.expr = yyvsp[-1]._expr;		;
    break;}
case 33:
#line 105 "dcpu16.bison"
{ yyval._operand.code = yyvsp[-1]._code + 16; yyval._operand.expr = yyvsp[-3]._expr;		;
    break;}
case 34:
#line 106 "dcpu16.bison"
{ yyval._operand.code  = 0x18;	yyval._operand.expr = NULL;		;
    break;}
case 35:
#line 107 "dcpu16.bison"
{ yyval._operand.code  = 0x18;	yyval._operand.expr = NULL;		;
    break;}
case 36:
#line 108 "dcpu16.bison"
{ yyval._operand.code  = 0x19;	yyval._operand.expr = NULL;		;
    break;}
case 37:
#line 109 "dcpu16.bison"
{ yyval._operand.code  = 0x19;	yyval._operand.expr = NULL;		;
    break;}
case 38:
#line 110 "dcpu16.bison"
{ yyval._operand.code  = 0x1a;	yyval._operand.expr = yyvsp[0]._expr;		;
    break;}
case 39:
#line 111 "dcpu16.bison"
{ yyval._operand.code  = 0x1a;	yyval._operand.expr = yyvsp[-1]._expr;		;
    break;}
case 40:
#line 112 "dcpu16.bison"
{ yyval._operand.code  = 0x1b;	yyval._operand.expr = NULL;		;
    break;}
case 41:
#line 113 "dcpu16.bison"
{ yyval._operand.code  = 0x1c;	yyval._operand.expr = NULL;		;
    break;}
case 42:
#line 114 "dcpu16.bison"
{ yyval._operand.code  = 0x1d;	yyval._operand.expr = NULL;		;
    break;}
case 43:
#line 115 "dcpu16.bison"
{ yyval._operand.code  = 0x1e;	yyval._operand.expr = yyvsp[-1]._expr;		;
    break;}
case 44:
#line 116 "dcpu16.bison"
{ yyval._operand.code  = 0x1f;	yyval._operand.expr = yyvsp[0]._expr;		;
    break;}
case 45:
#line 120 "dcpu16.bison"
{ yyval._code = 0x01;  ;
    break;}
case 46:
#line 121 "dcpu16.bison"
{ yyval._code = 0x08;  ;
    break;}
case 47:
#line 122 "dcpu16.bison"
{ yyval._code = 0x09;  ;
    break;}
case 48:
#line 123 "dcpu16.bison"
{ yyval._code = 0x0a;  ;
    break;}
case 49:
#line 124 "dcpu16.bison"
{ yyval._code = 0x10;  ;
    break;}
case 50:
#line 125 "dcpu16.bison"
{ yyval._code = 0x11;  ;
    break;}
case 51:
#line 126 "dcpu16.bison"
{ yyval._code = 0x12;  ;
    break;}
case 52:
#line 129 "dcpu16.bison"
{ yyval._code = 0x1;  ;
    break;}
case 53:
#line 130 "dcpu16.bison"
{ yyval._code = 0x2;  ;
    break;}
case 54:
#line 131 "dcpu16.bison"
{ yyval._code = 0x3;  ;
    break;}
case 55:
#line 132 "dcpu16.bison"
{ yyval._code = 0x4;  ;
    break;}
case 56:
#line 133 "dcpu16.bison"
{ yyval._code = 0x5;  ;
    break;}
case 57:
#line 134 "dcpu16.bison"
{ yyval._code = 0x6;  ;
    break;}
case 58:
#line 135 "dcpu16.bison"
{ yyval._code = 0x7;  ;
    break;}
case 59:
#line 136 "dcpu16.bison"
{ yyval._code = 0x8;  ;
    break;}
case 60:
#line 137 "dcpu16.bison"
{ yyval._code = 0x9;  ;
    break;}
case 61:
#line 138 "dcpu16.bison"
{ yyval._code = 0xA;  ;
    break;}
case 62:
#line 139 "dcpu16.bison"
{ yyval._code = 0xB;  ;
    break;}
case 63:
#line 140 "dcpu16.bison"
{ yyval._code = 0xC;  ;
    break;}
case 64:
#line 141 "dcpu16.bison"
{ yyval._code = 0xD;  ;
    break;}
case 65:
#line 142 "dcpu16.bison"
{ yyval._code = 0xE;  ;
    break;}
case 66:
#line 143 "dcpu16.bison"
{ yyval._code = 0x10; ;
    break;}
case 67:
#line 144 "dcpu16.bison"
{ yyval._code = 0x11; ;
    break;}
case 68:
#line 145 "dcpu16.bison"
{ yyval._code = 0x12; ;
    break;}
case 69:
#line 146 "dcpu16.bison"
{ yyval._code = 0x13; ;
    break;}
case 70:
#line 147 "dcpu16.bison"
{ yyval._code = 0x14; ;
    break;}
case 71:
#line 148 "dcpu16.bison"
{ yyval._code = 0x15; ;
    break;}
case 72:
#line 149 "dcpu16.bison"
{ yyval._code = 0x16; ;
    break;}
case 73:
#line 150 "dcpu16.bison"
{ yyval._code = 0x17; ;
    break;}
case 74:
#line 151 "dcpu16.bison"
{ yyval._code = 0x1A; ;
    break;}
case 75:
#line 152 "dcpu16.bison"
{ yyval._code = 0x1B; ;
    break;}
case 76:
#line 156 "dcpu16.bison"
{ yyval._opcode.code = yyvsp[-3]._code; yyval._opcode.b = yyvsp[-2]._operand; yyval._opcode.a =  yyvsp[0]._operand; ;
    break;}
case 77:
#line 157 "dcpu16.bison"
{ yyval._opcode.code = yyvsp[-1]._code << 5;  yyval._opcode.a = yyvsp[0]._operand; yyval._opcode.b.code = -1; ;
    break;}
case 78:
#line 160 "dcpu16.bison"
{ yyval._expr = ast_new('+', yyvsp[-2]._expr,yyvsp[0]._expr); ;
    break;}
case 79:
#line 161 "dcpu16.bison"
{ yyval._expr = ast_new('-', yyvsp[-2]._expr,yyvsp[0]._expr); ;
    break;}
case 80:
#line 162 "dcpu16.bison"
{ yyval._expr = ast_new('*', yyvsp[-2]._expr,yyvsp[0]._expr); ;
    break;}
case 81:
#line 163 "dcpu16.bison"
{ yyval._expr = ast_new('/', yyvsp[-2]._expr,yyvsp[0]._expr); ;
    break;}
case 82:
#line 164 "dcpu16.bison"
{ yyval._expr = ast_new('%', yyvsp[-2]._expr,yyvsp[0]._expr); ;
    break;}
case 83:
#line 165 "dcpu16.bison"
{ yyval._expr = yyvsp[-1]._expr; ;
    break;}
case 84:
#line 166 "dcpu16.bison"
{ yyval._expr = ast_new(AST_UMINUS, yyvsp[0]._expr,NULL); ;
    break;}
case 85:
#line 167 "dcpu16.bison"
{ yyval._expr = ast_num(yyvsp[0]._num); ;
    break;}
case 86:
#line 168 "dcpu16.bison"
{ yyval._expr = ast_name(yyvsp[0]._ident); ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 170 "dcpu16.bison"

