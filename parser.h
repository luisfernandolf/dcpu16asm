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


extern YYSTYPE yylval;
