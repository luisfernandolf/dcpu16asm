
/*  A Bison parser, made from dcpu16.bison with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	SET	258
#define	ADD	259
#define	SUB	260
#define	MUL	261
#define	DIV	262
#define	MOD	263
#define	SHL	264
#define	SHR	265
#define	AND	266
#define	BOR	267
#define	XOR	268
#define	IFE	269
#define	IFN	270
#define	IFG	271
#define	IFB	272
#define	JSR	273
#define	ORGIN	274
#define	WORD	275
#define	BYTE	276
#define	EQU	277
#define	NUMBER	278
#define	IDENT	279
#define	EOL	280
#define	EOFILE	281
#define	ERROR	282
#define	REG_A	283
#define	REG_B	284
#define	REG_C	285
#define	REG_X	286
#define	REG_Y	287
#define	REG_Z	288
#define	REG_I	289
#define	REG_J	290
#define	REG_SP	291
#define	REG_O	292
#define	REG_PEEK	293
#define	REG_POP	294
#define	REG_PUSH	295
#define	REG_PC	296
#define	STRING	297
#define	UMINUS	298

#line 1 "dcpu16.bison"

	#include "dcpu16.h"
	#include <io.h>
	#include <malloc.h>
	#include <assert.h>
	

	#define YY_NO_UNISTD_H 
	#define YYDEBUG 1

#line 16 "dcpu16.bison"
typedef union
{
	int _num;
	tag _ident;
	tag _string;
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



#define	YYFINAL		146
#define	YYFLAG		-32768
#define	YYNTBASE	56

#define YYTRANSLATE(x) ((unsigned)(x) <= 298 ? yytranslate[x] : 66)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,    48,     2,     2,    54,
    55,    46,    44,    51,    45,     2,    47,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    50,     2,     2,
    43,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    52,     2,    53,     2,     2,     2,     2,     2,     2,     2,
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
    36,    37,    38,    39,    40,    41,    42,    49
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     5,     8,    10,    15,    20,    25,    29,    32,
    35,    39,    42,    45,    48,    51,    54,    56,    58,    60,
    64,    68,    70,    72,    74,    76,    78,    80,    82,    84,
    86,    90,    96,    98,   100,   102,   104,   106,   108,   112,
   114,   119,   124,   129,   134,   139,   144,   149,   154,   159,
   164,   169,   174,   179,   184,   189,   192,   196,   200,   204,
   208,   212,   216,   219,   221
};

static const short yyrhs[] = {    57,
    26,     0,    58,     0,    57,    58,     0,    25,     0,    24,
    43,    65,    25,     0,    24,    22,    65,    25,     0,    59,
    19,    65,    25,     0,    19,    65,    25,     0,    59,    25,
     0,    60,    25,     0,    59,    60,    25,     0,    65,    25,
     0,    24,    50,     0,    50,    24,     0,    20,    61,     0,
    21,    61,     0,    64,     0,    42,     0,    65,     0,    42,
    51,    61,     0,    65,    51,    61,     0,    28,     0,    29,
     0,    30,     0,    31,     0,    32,     0,    33,     0,    34,
     0,    35,     0,    62,     0,    52,    62,    53,     0,    52,
    65,    44,    62,    53,     0,    39,     0,    38,     0,    40,
     0,    36,     0,    41,     0,    37,     0,    52,    65,    53,
     0,    65,     0,     3,    63,    51,    63,     0,     4,    63,
    51,    63,     0,     5,    63,    51,    63,     0,     6,    63,
    51,    63,     0,     7,    63,    51,    63,     0,     8,    63,
    51,    63,     0,     9,    63,    51,    63,     0,    10,    63,
    51,    63,     0,    11,    63,    51,    63,     0,    12,    63,
    51,    63,     0,    13,    63,    51,    63,     0,    14,    63,
    51,    63,     0,    15,    63,    51,    63,     0,    16,    63,
    51,    63,     0,    17,    63,    51,    63,     0,    18,    63,
     0,    65,    44,    65,     0,    65,    45,    65,     0,    65,
    46,    65,     0,    65,    47,    65,     0,    65,    48,    65,
     0,    54,    65,    55,     0,    45,    65,     0,    23,     0,
    24,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    45,    52,    53,    57,    58,    59,    60,    61,    62,    63,
    64,    65,    68,    69,    72,    73,    74,    77,    78,    79,
    80,    85,    86,    87,    88,    89,    90,    91,    92,    96,
    97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
   127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
   137,   138,   139,   140,   141,   142,   144,   145,   146,   147,
   148,   149,   150,   151,   152
};

static const char * const yytname[] = {   "$","error","$undefined.","SET","ADD",
"SUB","MUL","DIV","MOD","SHL","SHR","AND","BOR","XOR","IFE","IFN","IFG","IFB",
"JSR","ORGIN","WORD","BYTE","EQU","NUMBER","IDENT","EOL","EOFILE","ERROR","REG_A",
"REG_B","REG_C","REG_X","REG_Y","REG_Z","REG_I","REG_J","REG_SP","REG_O","REG_PEEK",
"REG_POP","REG_PUSH","REG_PC","STRING","'='","'+'","'-'","'*'","'/'","'%'","UMINUS",
"':'","','","'['","']'","'('","')'","all","lines","line","label","macro","datseq",
"operand_regester","operand_expr","opcode_expr","expr",""
};
#endif

static const short yyr1[] = {     0,
    56,    57,    57,    58,    58,    58,    58,    58,    58,    58,
    58,    58,    59,    59,    60,    60,    60,    61,    61,    61,
    61,    62,    62,    62,    62,    62,    62,    62,    62,    63,
    63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
    64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
    64,    64,    64,    64,    64,    64,    65,    65,    65,    65,
    65,    65,    65,    65,    65
};

static const short yyr2[] = {     0,
     2,     1,     2,     1,     4,     4,     4,     3,     2,     2,
     3,     2,     2,     2,     2,     2,     1,     1,     1,     3,
     3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     3,     5,     1,     1,     1,     1,     1,     1,     3,     1,
     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
     4,     4,     4,     4,     4,     2,     3,     3,     3,     3,
     3,     3,     2,     1,     1
};

static const short yydefact[] = {     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
    65,     4,     0,     0,     0,     0,     2,     0,     0,    17,
     0,    65,    22,    23,    24,    25,    26,    27,    28,    29,
    36,    38,    34,    33,    35,    37,     0,    30,     0,    40,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    56,     0,    18,    15,    19,    16,
     0,     0,    13,    63,    14,     0,     1,     3,     0,     9,
     0,    10,    12,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     8,     0,     0,     0,     0,
    62,     0,    11,    57,    58,    59,    60,    61,    31,     0,
    39,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    52,    53,    54,    55,    20,    21,     6,     5,
     7,     0,    32,     0,     0,     0
};

static const short yydefgoto[] = {   144,
    26,    27,    28,    29,    68,    48,    49,    30,    50
};

static const short yypact[] = {   170,
     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
     4,     4,     4,     4,     4,     4,    29,     6,     6,-32768,
    32,-32768,    29,    -4,    29,   118,-32768,   246,    -3,-32768,
    21,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   173,-32768,   -27,   228,
   -20,     8,    13,    19,    22,    25,    26,    27,    30,    54,
    55,    65,    66,    68,-32768,   184,    89,-32768,    67,-32768,
    29,    29,-32768,-32768,-32768,   101,-32768,-32768,    29,-32768,
   130,-32768,-32768,    29,    29,    29,    29,    29,   104,   106,
     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
     4,     4,     4,     4,     4,-32768,     6,     6,   189,   194,
-32768,   200,-32768,    15,    15,-32768,-32768,-32768,-32768,   173,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   105,-32768,    50,    57,-32768
};

static const short yypgoto[] = {-32768,
-32768,   134,-32768,    52,     2,   -31,    -1,-32768,     0
};


#define	YYLAST		276


static const short yytable[] = {    31,
    51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    65,    89,    66,    69,    69,    75,
    70,    82,    74,    91,    76,    31,    20,    32,    20,    32,
    92,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    83,    90,    67,    23,   145,
    23,    20,    32,    71,     0,    47,   146,    25,    93,    25,
    86,    87,    88,    94,    84,    85,    86,    87,    88,    95,
   109,   110,    96,    23,    72,    97,    98,    99,   112,    81,
   100,    73,    25,   114,   115,   116,   117,   118,   142,   122,
   123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
   133,   134,   135,   136,   101,   102,    69,    69,   137,   138,
    84,    85,    86,    87,    88,   103,   104,   108,   105,   114,
     1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
    11,    12,    13,    14,    15,    16,    17,    18,    19,   107,
    20,    21,    22,    77,    84,    85,    86,    87,    88,   120,
    85,    86,    87,    88,   113,   111,   119,   143,   121,    78,
     0,     0,    23,     0,     0,     0,     0,    24,     0,     0,
     0,    25,     1,     2,     3,     4,     5,     6,     7,     8,
     9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
    19,     0,    20,    21,    22,    20,    32,     0,     0,     0,
    33,    34,    35,    36,    37,    38,    39,    40,   106,     0,
     0,     0,     0,   139,    23,     0,     0,    23,   140,    24,
     0,     0,     0,    25,   141,     0,    25,    84,    85,    86,
    87,    88,    84,    85,    86,    87,    88,    84,    85,    86,
    87,    88,     0,    84,    85,    86,    87,    88,     1,     2,
     3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
    13,    14,    15,    16,    79,    18,    19,     0,     0,     0,
    80,    84,    85,    86,    87,    88
};

static const short yycheck[] = {     0,
     2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
    12,    13,    14,    15,    16,    47,    17,    18,    19,    24,
    19,    25,    23,    51,    25,    26,    23,    24,    23,    24,
    51,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    25,    47,    42,    45,     0,
    45,    23,    24,    22,    -1,    52,     0,    54,    51,    54,
    46,    47,    48,    51,    44,    45,    46,    47,    48,    51,
    71,    72,    51,    45,    43,    51,    51,    51,    79,    28,
    51,    50,    54,    84,    85,    86,    87,    88,   120,    91,
    92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
   102,   103,   104,   105,    51,    51,   107,   108,   107,   108,
    44,    45,    46,    47,    48,    51,    51,    51,    51,   120,
     3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
    13,    14,    15,    16,    17,    18,    19,    20,    21,    51,
    23,    24,    25,    26,    44,    45,    46,    47,    48,    44,
    45,    46,    47,    48,    25,    55,    53,    53,    53,    26,
    -1,    -1,    45,    -1,    -1,    -1,    -1,    50,    -1,    -1,
    -1,    54,     3,     4,     5,     6,     7,     8,     9,    10,
    11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
    21,    -1,    23,    24,    25,    23,    24,    -1,    -1,    -1,
    28,    29,    30,    31,    32,    33,    34,    35,    25,    -1,
    -1,    -1,    -1,    25,    45,    -1,    -1,    45,    25,    50,
    -1,    -1,    -1,    54,    25,    -1,    54,    44,    45,    46,
    47,    48,    44,    45,    46,    47,    48,    44,    45,    46,
    47,    48,    -1,    44,    45,    46,    47,    48,     3,     4,
     5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
    15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
    25,    44,    45,    46,    47,    48
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
#line 46 "dcpu16.bison"
{
	    return 0;
	  ;
    break;}
case 2:
#line 52 "dcpu16.bison"
{	pushline(yyvsp[0]._line); ;
    break;}
case 3:
#line 53 "dcpu16.bison"
{	pushline(yyvsp[0]._line); ;
    break;}
case 4:
#line 57 "dcpu16.bison"
{ yyval._line =  0; ;
    break;}
case 5:
#line 58 "dcpu16.bison"
{ yyval._line = 0; sym_val(yyvsp[-3]._ident, ast_eval(yyvsp[-1]._expr)); ;
    break;}
case 6:
#line 59 "dcpu16.bison"
{ yyval._line = 0; sym_val(yyvsp[-3]._ident, ast_eval(yyvsp[-1]._expr)); ;
    break;}
case 7:
#line 60 "dcpu16.bison"
{ yyval._line = line_origin(ast_eval(yyvsp[-1]._expr)); sym_val(yyvsp[-3]._ident, line_current_pc()); ;
    break;}
case 8:
#line 61 "dcpu16.bison"
{ yyval._line = line_origin(ast_eval(yyvsp[-1]._expr)); ;
    break;}
case 9:
#line 62 "dcpu16.bison"
{ yyval._line = 0; ;
    break;}
case 10:
#line 63 "dcpu16.bison"
{ yyval._line = yyvsp[-1]._line; ;
    break;}
case 11:
#line 64 "dcpu16.bison"
{ yyval._line = yyvsp[-1]._line; ;
    break;}
case 12:
#line 65 "dcpu16.bison"
{ yyval._line = 0;  ;
    break;}
case 13:
#line 68 "dcpu16.bison"
{ yyval._ident = yyvsp[-1]._ident;  sym_val(yyvsp[-1]._ident, line_current_pc()); ;
    break;}
case 14:
#line 69 "dcpu16.bison"
{ yyval._ident = yyvsp[0]._ident;  sym_val(yyvsp[0]._ident, line_current_pc()); ;
    break;}
case 15:
#line 72 "dcpu16.bison"
{ yyval._line = line_words(yyvsp[0]._args);  ;
    break;}
case 16:
#line 73 "dcpu16.bison"
{ yyval._line = line_bytes(yyvsp[0]._args);  ;
    break;}
case 17:
#line 74 "dcpu16.bison"
{ yyval._line = line_opcode(yyvsp[0]._opcode); ;
    break;}
case 18:
#line 77 "dcpu16.bison"
{ yyval._args = arg_array((uint8_t*)yyvsp[0]._ident,strlen(yyvsp[0]._ident));  ;
    break;}
case 19:
#line 78 "dcpu16.bison"
{ yyval._args = arg_expr(yyvsp[0]._expr);   ;
    break;}
case 20:
#line 79 "dcpu16.bison"
{ yyval._args = arg_array((uint8_t*)yyvsp[-2]._ident,strlen(yyvsp[-2]._ident)); yyval._args->next = yyvsp[0]._args;  ;
    break;}
case 21:
#line 80 "dcpu16.bison"
{ yyval._args = arg_expr(yyvsp[-2]._expr); yyval._args->next = yyvsp[0]._args;    ;
    break;}
case 22:
#line 85 "dcpu16.bison"
{ yyval._operand.code = 0; yyval._operand.expr = NULL; ;
    break;}
case 23:
#line 86 "dcpu16.bison"
{ yyval._operand.code = 1; yyval._operand.expr = NULL; ;
    break;}
case 24:
#line 87 "dcpu16.bison"
{ yyval._operand.code = 2; yyval._operand.expr = NULL; ;
    break;}
case 25:
#line 88 "dcpu16.bison"
{ yyval._operand.code = 3; yyval._operand.expr = NULL; ;
    break;}
case 26:
#line 89 "dcpu16.bison"
{ yyval._operand.code = 4; yyval._operand.expr = NULL; ;
    break;}
case 27:
#line 90 "dcpu16.bison"
{ yyval._operand.code = 5; yyval._operand.expr = NULL; ;
    break;}
case 28:
#line 91 "dcpu16.bison"
{ yyval._operand.code = 6; yyval._operand.expr = NULL; ;
    break;}
case 29:
#line 92 "dcpu16.bison"
{ yyval._operand.code = 7; yyval._operand.expr = NULL; ;
    break;}
case 30:
#line 96 "dcpu16.bison"
{ yyval._operand = yyvsp[0]._operand;					;
    break;}
case 31:
#line 97 "dcpu16.bison"
{ yyval._operand = yyvsp[-1]._operand;  yyval._operand.code  += 8;			;
    break;}
case 32:
#line 98 "dcpu16.bison"
{ yyval._operand = yyvsp[-1]._operand; yyval._operand.code  += 16;	yyval._operand.expr = yyvsp[-3]._expr;		;
    break;}
case 33:
#line 99 "dcpu16.bison"
{ yyval._operand.code  = 0x18;	yyval._operand.expr = NULL;		;
    break;}
case 34:
#line 100 "dcpu16.bison"
{ yyval._operand.code  = 0x19;	yyval._operand.expr = NULL;		;
    break;}
case 35:
#line 101 "dcpu16.bison"
{ yyval._operand.code  = 0x1a;	yyval._operand.expr = NULL;		;
    break;}
case 36:
#line 102 "dcpu16.bison"
{ yyval._operand.code  = 0x1b;	yyval._operand.expr = NULL;		;
    break;}
case 37:
#line 103 "dcpu16.bison"
{ yyval._operand.code  = 0x1c;	yyval._operand.expr = NULL;		;
    break;}
case 38:
#line 104 "dcpu16.bison"
{ yyval._operand.code  = 0x1d;	yyval._operand.expr = NULL;		;
    break;}
case 39:
#line 105 "dcpu16.bison"
{ yyval._operand.code  = 0x1e;	yyval._operand.expr = yyvsp[-1]._expr;		;
    break;}
case 40:
#line 106 "dcpu16.bison"
{   
							if(ast_isnum(yyvsp[0]._expr)) 
								if(yyvsp[0]._expr->v.num < 0x20) {
									yyval._operand.code = operand_code(0x20 + yyvsp[0]._expr->v.num);
									yyval._operand.expr = NULL;
									ast_free(yyvsp[0]._expr);
									yyvsp[0]._expr = NULL;
								} else {
									yyval._operand.code  = 0x1f;	
									yyval._operand.expr = yyvsp[0]._expr;
								}
							else {
								yyval._operand.code  = 0x1f;	
								yyval._operand.expr = yyvsp[0]._expr;
							}

						;
    break;}
case 41:
#line 127 "dcpu16.bison"
{ yyval._opcode.code = 0x1; yyval._opcode.a = yyvsp[-2]._operand; yyval._opcode.b =  yyvsp[0]._operand; ;
    break;}
case 42:
#line 128 "dcpu16.bison"
{ yyval._opcode.code = 0x2; yyval._opcode.a = yyvsp[-2]._operand; yyval._opcode.b =  yyvsp[0]._operand; ;
    break;}
case 43:
#line 129 "dcpu16.bison"
{ yyval._opcode.code = 0x3; yyval._opcode.a = yyvsp[-2]._operand; yyval._opcode.b =  yyvsp[0]._operand; ;
    break;}
case 44:
#line 130 "dcpu16.bison"
{ yyval._opcode.code = 0x4; yyval._opcode.a = yyvsp[-2]._operand; yyval._opcode.b =  yyvsp[0]._operand; ;
    break;}
case 45:
#line 131 "dcpu16.bison"
{ yyval._opcode.code = 0x5; yyval._opcode.a = yyvsp[-2]._operand; yyval._opcode.b =  yyvsp[0]._operand; ;
    break;}
case 46:
#line 132 "dcpu16.bison"
{ yyval._opcode.code = 0x6; yyval._opcode.a = yyvsp[-2]._operand; yyval._opcode.b =  yyvsp[0]._operand; ;
    break;}
case 47:
#line 133 "dcpu16.bison"
{ yyval._opcode.code = 0x7; yyval._opcode.a = yyvsp[-2]._operand; yyval._opcode.b =  yyvsp[0]._operand; ;
    break;}
case 48:
#line 134 "dcpu16.bison"
{ yyval._opcode.code = 0x8; yyval._opcode.a = yyvsp[-2]._operand; yyval._opcode.b =  yyvsp[0]._operand; ;
    break;}
case 49:
#line 135 "dcpu16.bison"
{ yyval._opcode.code = 0x9; yyval._opcode.a = yyvsp[-2]._operand; yyval._opcode.b =  yyvsp[0]._operand; ;
    break;}
case 50:
#line 136 "dcpu16.bison"
{ yyval._opcode.code = 0xA; yyval._opcode.a = yyvsp[-2]._operand; yyval._opcode.b =  yyvsp[0]._operand; ;
    break;}
case 51:
#line 137 "dcpu16.bison"
{ yyval._opcode.code = 0xB; yyval._opcode.a = yyvsp[-2]._operand; yyval._opcode.b =  yyvsp[0]._operand; ;
    break;}
case 52:
#line 138 "dcpu16.bison"
{ yyval._opcode.code = 0xC; yyval._opcode.a = yyvsp[-2]._operand; yyval._opcode.b =  yyvsp[0]._operand; ;
    break;}
case 53:
#line 139 "dcpu16.bison"
{ yyval._opcode.code = 0xD; yyval._opcode.a = yyvsp[-2]._operand; yyval._opcode.b =  yyvsp[0]._operand; ;
    break;}
case 54:
#line 140 "dcpu16.bison"
{ yyval._opcode.code = 0xE; yyval._opcode.a = yyvsp[-2]._operand; yyval._opcode.b =  yyvsp[0]._operand; ;
    break;}
case 55:
#line 141 "dcpu16.bison"
{ yyval._opcode.code = 0xF; yyval._opcode.a = yyvsp[-2]._operand; yyval._opcode.b =  yyvsp[0]._operand; ;
    break;}
case 56:
#line 142 "dcpu16.bison"
{ yyval._opcode.code = 0;   yyval._opcode.a.code = 0x01; yyval._opcode.b = yyvsp[0]._operand; ;
    break;}
case 57:
#line 144 "dcpu16.bison"
{ yyval._expr = ast_new('+', yyvsp[-2]._expr,yyvsp[0]._expr); ;
    break;}
case 58:
#line 145 "dcpu16.bison"
{ yyval._expr = ast_new('-', yyvsp[-2]._expr,yyvsp[0]._expr); ;
    break;}
case 59:
#line 146 "dcpu16.bison"
{ yyval._expr = ast_new('*', yyvsp[-2]._expr,yyvsp[0]._expr); ;
    break;}
case 60:
#line 147 "dcpu16.bison"
{ yyval._expr = ast_new('/', yyvsp[-2]._expr,yyvsp[0]._expr); ;
    break;}
case 61:
#line 148 "dcpu16.bison"
{ yyval._expr = ast_new('%', yyvsp[-2]._expr,yyvsp[0]._expr); ;
    break;}
case 62:
#line 149 "dcpu16.bison"
{ yyval._expr = yyvsp[-1]._expr; ;
    break;}
case 63:
#line 150 "dcpu16.bison"
{ yyval._expr = ast_new(AST_UMINUS, yyvsp[0]._expr,NULL); ;
    break;}
case 64:
#line 151 "dcpu16.bison"
{ yyval._expr = ast_num(yyvsp[0]._num); ;
    break;}
case 65:
#line 152 "dcpu16.bison"
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
#line 154 "dcpu16.bison"

