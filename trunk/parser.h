typedef union
{
	uint16_t _code;
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


extern YYSTYPE yylval;
