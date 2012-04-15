#include "dcpu16asm.h"
#define MAX_WORDS 0x10000
#define MAX_BYTES MAX_WORDS * 2

uint8_t  mem[MAX_BYTES];


uint16_t origins[0x10000];

static int current_pc= 0;
static int current_origin=0;
static int first_line;

#define add_pc(v) (current_pc+=v, origins[current_origin]+=v)

static void push_word(int val)
{
	// make sure we are always 16 bit alligned
	if(current_pc & 1){ current_pc++; origins[current_origin]++; }
	mem[current_pc++] = (uint8_t)val;
	mem[current_pc++] = (uint8_t)(val>>8);
	origins[current_origin]+=2;
}
static void push_byte(int val)
{
	mem[current_pc] = (uint8_t)val;
	origins[current_origin]++;
}
int emit_pc() { return current_pc; } 

void emit_origin(int pc) { current_origin = current_pc = pc; origins[current_origin] = 0; }
void emit_init() { int i = 0; for(i=0; i<0x10000;i++) origins[i] = mem[i] = 0;  current_pc = 0; first_line = 1; }
 
extern FILE* fout;

void write_intel_record(FILE * out, int adr, int len)
{
	int i = 0;
	char checksum = 0;

   fprintf(out, ":");

   fprintf(out, "%2.2X", len & 0xFF);
   checksum += len;

   fprintf(out, "%4.4X", adr & 0xFFFF);
   checksum += adr >> 8;
   checksum += adr;

   if (len == 0)   { fprintf(out, "01");   checksum ++; }   // end of file
   else            { fprintf(out, "00");                }   // data

   for (i = adr; i < adr + len; i++)
       {
         fprintf(out, "%2.2X", mem[i] & 0xFF);
         checksum += mem[i];
       }

   fprintf(out, "%2.2X\n", (-checksum) & 0xFF);
}
//-----------------------------------------------------------------------------
void write_intel_hex(FILE * out)
{
	int i,j;
	for(j=0; j< 0x10000; j++)
		if(origins[j])
		{
			int end = origins[j] + j;
			for (i = j; i < end; i += 16)
			{
				int len = origins[j] - i;
				if (len > 16)   len = 16;
				write_intel_record(out, i, len);
			}
		}
   write_intel_record(out, 0, 0);
}

void setoutput(FILE* f) { fout = f; }


void emit_raw_end()
{
	fprintf(fout,"\n");
}
void emit_raw_start()
{
	fprintf(fout,"\n%4.4X: ", current_pc);
}

void emit_byte(int data)
{
	push_byte(data);
	fprintf(fout, "%2.2X ",(uint8_t)data); 
	fflush(fout);
}

void emit_word(int data)
{
	push_word(data);
	fprintf(fout, "%4.4X ",(uint8_t)data);
	fflush(fout);
}


void emit_ext_opcode(int op, t_operand a)
{
	int code=0;

	code = ((a.code & 0x3F) << 10) | ((op & 0x3F) << 4);
	fprintf(fout,"\n%4.4X: %4.4X ",current_pc,code);
	push_word(code);
	if(a.offset != -1) { fprintf(fout,"%4.4X ",a.offset); push_word(a.offset);}
	fflush(fout);
}
void emit_std_opcode(int op, t_operand a, t_operand b)
{
	int code=0;

	code = ((b.code & 0x3F) << 10) | ((a.code & 0x3F) << 4) | (op & 0xF);
	fprintf(fout,"\n%4.4X: %4.4X ",current_pc,code);
	push_word(code);
	
	if(a.offset != -1) {  fprintf(fout,"%4.4X ",a.offset); push_word(a.offset);  }
	if(b.offset != -1) {  fprintf(fout,"%4.4X ",b.offset); push_word(b.offset);  }
	fflush(fout);
} 