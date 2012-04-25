#include "dcpu16.h"
#include "strtable.h"
#include "intel_hex.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdarg.h>


FILE* errAsm = NULL;

extern char* yytext;
int errors = 0;
extern int yylineno;

	

void fatal_error(int i) {
	yyerror("Fatal Error (%4.1x), exiting",i);
	exit(i);
}

// Show an error count
void ErrorSummary ()  {
   fprintf (errAsm, "%d error(s) were found.\n", errors);
}

// Function called by the parser when an error occurs while parsing
// (parse error or stack overflow)
void yyerror(const char * format, ...)
{
	static int did_crlf = 0;
	va_list args;

	if(did_crlf)
		fprintf (errAsm, "\n(%d) %s: ", yylineno,yytext);
	else { 
		fprintf (errAsm, "(%d) %s: ", yylineno,yytext); 
		did_crlf = 1; 
	}
	va_start(args, format);
	vfprintf(errAsm, format, args);
	va_end(args);
	fprintf (errAsm,"\n");
	errors++;
}

static void usage(const char * prog);
FILE *  fout= NULL;
FILE * out  = 0;
FILE * sym  = 0;
FILE * list = 0;
FILE * ihx  = 0;


int main(int argc, char * argv[])
{
	FILE * f = NULL;
	char * b=NULL;
	char * asmname=NULL;
	char * asmend=NULL;
	errAsm = stdout;
//	emit_init();
	init_strtable();
	// Set the input stream (either a file from the command line or stdin)
	yyin = NULL;

	if (argc == 2) {
		printf("Opening %s\n", argv[1]);
		yyin = fopen (argv[1], "rt");
		if(!yyin) {
			perror ("Could not open file");
			//printf("Could not open %s\n",argv[1]);
			return 1;
		}
		asmname = argv[1];
	} else { usage(argv[0]); exit(1); }
	
	
	yyparse (); // call the parser
	//line_list(stdout);

	asmend = strrchr(asmname, '.');
	if (asmend)   *asmend = 0;

	b = vec_init();
	vec_sprintf("%s.lst", asmname);
	f = fopen(b,"wt");
	if(f) line_list(f);
	fclose(f);

	vec_init();
	vec_sprintf("%s.ihx", asmname);
	f = fopen(b,"wt");
	if(f) line_intel_hex(f);
	fclose(f);

	vec_init();
	vec_sprintf("%s.bin", asmname);
	f = fopen(b,"wt");
	if(f) line_binary(f);
	fclose(f);

	vec_init();
	vec_sprintf("%s.sym", asmname);
	f = fopen(b,"wt");
	if(f) sym_list(f);
	fclose(f);

	ErrorSummary ();	
	
	//sym_list(stdout);
	//fixerr();

   return 0;
}
//-----------------------------------------------------------------------------
void usage(const char * prog)
{
   fprintf(stderr, "Usage: %s file.asm\r\n", prog);
}
//-----------------------------------------------------------------------------
