#include <stdio.h>
#include "cpu.h"
#include "opcodes.h"

#define K_GREEN "\x1B[32m"
#define K_RED "\x1B[31m"

void test_nop() {

	printf("Opcode NOP:");
	cpu_t cpu;
	cpu.pc = 0x0000;
	cpu.mem[0x0000] = 0x00;
	execute_opcode(&cpu);
	if (cpu.m_cycles == 1 &&
	    cpu.t_states == 4 &&
    	    cpu.pc == 0x0001)
	{
		printf("%sOK", K_GREEN);
	}
	else
	{
		printf("%sERROR", K_RED);
	}
	printf("\n");	

	
	
}

int main(int argc, char** argv) 
{
	init();
	test_nop();
	return 0;
}
