#include <stdio.h>
#include "opcodes.h"

void
extract_opcode(uint8_t opcode, opcode_t* opstruct)
{

	opstruct->x = (opcode & OPC_X) >> 6;
	opstruct->y = (opcode & OPC_Y) >> 3;
	opstruct->z = (opcode & OPC_Z);
	opstruct->p = (opcode & OPC_P) >> 4;
	opstruct->q = (opcode & OPC_Q) >> 3;

}

void
execute_opcode(cpu_t* cpu) 
{

	// Extract opcode
	uint8_t opcode = cpu->mem[cpu->pc++];

	opcode_t st_opcode;
	extract_opcode(opcode, &st_opcode);
	printf("Opcode: %x\nX: %x\nY: %x\nZ: %x\nP: %x\n Q: %x\n", 
			opcode,
			st_opcode.x,
			st_opcode.y,
			st_opcode.z,
			st_opcode.p,
			st_opcode.q);

	// Process opcode

	// Other operations	
	
}

