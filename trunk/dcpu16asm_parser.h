typedef union{
	int num;
	t_symbol* ident;
	char* str;
	t_operand operand;
	unsigned short opcode;
} YYSTYPE;
#define	NUMBER	258
#define	STRING	259
#define	LABEL	260
#define	SET	261
#define	ADD	262
#define	SUB	263
#define	MUL	264
#define	DIV	265
#define	MOD	266
#define	SHL	267
#define	SHR	268
#define	AND	269
#define	BOR	270
#define	XOR	271
#define	IFE	272
#define	IFN	273
#define	IFG	274
#define	IFB	275
#define	JSR	276
#define	ORGIN	277
#define	WORD	278
#define	BYTE	279
#define	EQU	280
#define	REG_A	281
#define	REG_B	282
#define	REG_C	283
#define	REG_X	284
#define	REG_Y	285
#define	REG_Z	286
#define	REG_I	287
#define	REG_J	288
#define	REG_SP	289
#define	REG_O	290
#define	REG_PEEK	291
#define	REG_POP	292
#define	REG_PUSH	293
#define	REG_PC	294
#define	EOL	295
#define	WRONGTOKEN	296
#define	ERROR	297
#define	PRINT	298
#define	UNARYMINUS	299
#define	UNARYNOT	300


extern YYSTYPE yylval;
