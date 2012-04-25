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
#define	JSR	280
#define	INT	281
#define	ING	282
#define	INS	283
#define	HWN	284
#define	HWQ	285
#define	HWI	286
#define	ORGIN	287
#define	WORD	288
#define	BYTE	289
#define	EQU	290
#define	NUMBER	291
#define	IDENT	292
#define	EOL	293
#define	EOFILE	294
#define	ERROR	295
#define	REG_A	296
#define	REG_B	297
#define	REG_C	298
#define	REG_X	299
#define	REG_Y	300
#define	REG_Z	301
#define	REG_I	302
#define	REG_J	303
#define	REG_SP	304
#define	REG_EX	305
#define	REG_PC	306
#define	PEEK	307
#define	POP	308
#define	PICK	309
#define	PUSH	310
#define	STRING	311
#define	UMINUS	312


extern YYSTYPE yylval;
