#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <Windows.h>
#include <stdio.h>
#include "dcpu16asm.h"
extern char* yytext;
int errors = 0;
int lineno = 1;
int colno = 0;
// Function used to report errors
void Error (char *format, ...)   {
   va_list args;

   errors++;
   fprintf (stderr, "Line %d: Col: %d ", lineno,colno);
   va_start(args, format);
   vfprintf(stderr, format, args);
   va_end(args);
   printf("\n");
}

// Show an error count
void ErrorSummary ()  {
   fprintf (stderr, "%d error(s) were found.\n", errors);
}

// Function called by the parser when an error occurs while parsing
// (parse error or stack overflow)
void yyerror(char *msg) {
   Error ("%s (yytext:%s)",msg,yytext);
}





static void usage(const char * prog);
FILE *  fout= NULL;
FILE * out  = 0;
FILE * sym  = 0;
FILE * list = 0;
FILE * ihx  = 0;
char listname[256];
char outname [256];
char ihxname [256];
char symname [256];


int main(int argc, char * argv[])
{
	char * asmname=NULL;
	char * asmend=NULL;
	emit_init();
	// Set the input stream (either a file from the command line or stdin)
	yyin = NULL;
	*stderr = *stdout;
	if (argc == 2) {
		printf("Opening %s\n", argv[1]);
		yyin = fopen (argv[1], "rt");
		if(!yyin) {
			perror ("Could not open file");
			//printf("Could not open %s\n",argv[1]);
			return 1;
		}
		asmname = argv[1];
	} else { yyin = stdin; }
	

	asmend = strrchr(asmname, '.');
	if (asmend)   *asmend = 0;
	sprintf(listname, "%s.lst", asmname);
	sprintf(ihxname, "%s.hex", asmname);
	fout = fopen(listname,"wt");
	fprintf(fout,"LISTING: %s",argv[1]);
	//fout = stdout;
	yyparse (); // call the parser
	fclose(fout);
	ihx = fopen(ihxname,"wt");
	write_intel_hex(ihx);
	fclose(ihx);

	ErrorSummary ();	
	

	//fixerr();

   return 0;
}
//-----------------------------------------------------------------------------
void usage(const char * prog)
{
   fprintf(stderr, "Usage: %s [-l] file.asm [file.asm]\r\n", prog);
}
//-----------------------------------------------------------------------------
