#ifndef OPCODES_H
#define OPCODES_H
#include <stdint.h>
#include "cpu.h"

#define OPC_X 0xc0
#define OPC_Y 0x38
#define OPC_Z 0x07
#define OPC_P 0x30
#define OPC_Q 0x08

typedef struct 
{
			// 7 6 5 4  3 2 1 0
	uint8_t x;	// 1 1 0 0  0 0 0 0 - 0xC0
	uint8_t y;	// 0 0 1 1  1 0 0 0 - 0x38
	uint8_t z;	// 0 0 0 0  0 1 1 1 - 0x07
	uint8_t p;	// 0 0 1 1  0 0 0 0 - 0x30
	uint8_t q;	// 0 0 0 0  1 0 0 0 - 0x08

} opcode_t;

void extract_opcode(uint8_t opcode, opcode_t* opstruct);
void execute_opcode(cpu_t*);

#endif
