#ifndef OPCODES_H
#define OPCODES_H
#include <stdint.h>
#include "cpu.h"

#define OPC_X 0xc0
#define OPC_Y 0x38
#define OPC_Z 0x07
#define OPC_P 0x30
#define OPC_Q 0x08

#define FETCH_IN(X) X = cpu->mem[cpu->pc++]

typedef struct 
{
			// 7 6 5 4  3 2 1 0
	uint8_t x;	// 1 1 0 0  0 0 0 0 - 0xC0
	uint8_t y;	// 0 0 1 1  1 0 0 0 - 0x38
	uint8_t z;	// 0 0 0 0  0 1 1 1 - 0x07
	uint8_t p;	// 0 0 1 1  0 0 0 0 - 0x30
	uint8_t q;	// 0 0 0 0  1 0 0 0 - 0x08

} opcode_t;

typedef void (*OPCODE)(opcode_t*, cpu_t*);

OPCODE opcodes[4][8];

void extract_opcode(uint8_t opcode, opcode_t* opstruct);
void execute_opcode(cpu_t*);

// opcodes X=0 and Z=0 to 7
void opcodes00(opcode_t*, cpu_t*);
void opcodes01(opcode_t*, cpu_t*);
void opcodes02(opcode_t*, cpu_t*);
void opcodes04(opcode_t*, cpu_t*);
void opcodes05(opcode_t*, cpu_t*);
void opcodes06(opcode_t*, cpu_t*);
void opcodes07(opcode_t*, cpu_t*);

// opcodes X=1 and Z=6
void opcodes16(opcode_t*, cpu_t*);

#endif
