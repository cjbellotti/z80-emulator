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

// opcodes X=0 and Z=0 to 7
void 
opcodes00(opcode_t* opcode, cpu_t* cpu)
{
	uint16_t utmp16;
	uint8_t utmp8;
	int8_t tmp8;
	switch(opcode->y)
	{
		// NOP
		case 0:
			cpu->m_cycles=1;
			cpu->t_states=4;
			break;
	
		// EX AF, AF'	
		case 1:
			utmp16 = cpu->main.af;
			cpu->main.af = cpu->alternative.af;
			cpu->alternative.af = utmp16;
			cpu->m_cycles=1;
			cpu->t_states=4;
			break;

		// DJNZ d
		case 2:
			if (cpu->main.b > 0) {
				cpu->main.b--;
				tmp8 = cpu->mem[cpu->pc++];
				// cpu->pc += tmp8 + 2;
				cpu->pc += tmp8;
				cpu->m_cycles=3;
				cpu->t_states=13;
			} else {
				cpu->m_cycles=2;
				cpu->t_states=8;
			}
			break;
			
		default:
			break;
	}
}

void 
opcodes01(opcode_t* opcode, cpu_t* cpu)
{
}

void 
opcodes02(opcode_t* opcode, cpu_t* cpu)
{
}

void 
opcodes04(opcode_t* opcode, cpu_t* cpu)
{
}

void 
opcodes05(opcode_t* opcode, cpu_t* cpu)
{
}

void 
opcodes06(opcode_t* opcode, cpu_t* cpu)
{
}

void 
opcodes07(opcode_t* opcode, cpu_t* cpu)
{
}


// opcodes X=1 and Z=6
void 
opcodes16(opcode_t* opcode, cpu_t* cpu)
{
}

void
init()
{
	opcodes[0][0] = opcodes00;
}

void
execute_opcode(cpu_t* cpu) 
{

	// Extract opcode
	uint8_t opcode = cpu->mem[cpu->pc++];

	opcode_t st_opcode;
	extract_opcode(opcode, &st_opcode);

	// Process opcode
	opcodes[st_opcode.x][st_opcode.z](&st_opcode, cpu);

	// Other operations	
	
}


