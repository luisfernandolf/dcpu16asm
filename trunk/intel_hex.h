#ifndef _INTEL_HEX_
#define _INTEL_HEX_
#include <stdio.h>
#include <stdint.h>

#define IHEX_SIZEOFRECROD 16

int write_intel_hex_segment(FILE * out, int segment);
int write_intel_hex_eof(FILE * out) ;
int write_intel_data(FILE * out, int len, int offset, uint8_t *mem);
int write_intel_hex_block(FILE * out, uint16_t start_pc, uint8_t* data, uint16_t len);

#endif
