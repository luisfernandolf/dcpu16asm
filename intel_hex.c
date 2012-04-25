#include "intel_hex.h"


enum IHEX_FORMAT
{
	IHEX_DATA				=0,
	IHEX_EOF				=1,
	IHEX_SEGMENT			=2,
	IHEX_START_SEGMENT		=3,
	IHEX_LINEAR				=4,
	IHEX_START_LINEAR		=5
};

static int write_intel_header(FILE*out, uint8_t reclen, uint16_t offset, int type, int8_t* checksum)
{
	int ret = 0;
	ret += fprintf(out, ":%2.2X%4.4X%2.2X%", reclen,offset,type);
	*checksum = reclen + (offset & 0xFF) + ((offset>>8) & 0xFF) + type;
	return ret;
}

int write_intel_hex_segment(FILE * out, int segment)
{ 
	int ret = 0;
	int8_t checksum = 0; 
	ret += write_intel_header(out,0x02,0x0000, IHEX_SEGMENT,&checksum);
	checksum += (segment & 0xFF) + ((segment>>8) & 0xFF);
	ret += fprintf(out,"%4.4X%2.2X\n", segment & 0xFFFF, (-checksum) & 0xFF);
	return ret;
}
int write_intel_hex_eof(FILE * out) 
{ 
	int ret = 0;
	int8_t checksum = 0; 
	ret += write_intel_header(out,0x00,0x0000, IHEX_EOF,&checksum);
	ret += fprintf(out,"FF\n"); 
	return ret;
}
int  write_intel_data(FILE * out, int len, int offset, uint8_t *mem)
{
	int i;
	int ret = 0;
	int8_t checksum = 0; 
	ret += write_intel_header(out,len ,offset, IHEX_DATA,&checksum);
	for (i=0; i <  len; i++){
		ret +=fprintf(out, "%2.2X", mem[i]);
		checksum += mem[i];
	}
	ret +=fprintf(out, "%2.2X\n", (-checksum) & 0xFF);
	return ret;
}
//-----------------------------------------------------------------------------


int write_intel_hex_block(FILE * out, uint16_t start_pc, uint8_t* data, uint16_t len)
{
	int ret=0;
	uint16_t i =0;
	uint16_t end_pc = len + start_pc;
	for(i=start_pc; i < end_pc; i += IHEX_SIZEOFRECROD)
	{
		int len = i < end_pc ? IHEX_SIZEOFRECROD :  end_pc - i;
		// The basic records of the intel file format dosn't support more than
		// 64k.  we can get around this by writing a 02 segment record.
		// http://http://en.wikipedia.org/wiki/Intel_HEX for more info
		// Basicly, we put a 16 bit address on.  When the emulator loads this file and gets to this
		// record, it needs to read the datafield, shift it to the right (segment <<4) and add
		// that to all the next offsets.  the map file is sorted naturaly so I just
		// need to see when the orgin is more than 0x8000 or half the word memory space
		
		ret+=write_intel_data(out,len,i,data);
	}
	ret+=write_intel_hex_eof(out);
	return ret;
}

