#include <stdio.h>
#include "cpu.h"
#include "opcodes.h"

int main(int argc, char** argv) 
{
	init();
	cpu_t c;
	c.pc = 0x0000;
	c.mem[0x0000] = 0x08;
	c.main.af = 0xaa;
	c.alternative.af = 0xbb;
	printf("AF: %x - AF': %x\n", c.main.af, c.alternative.af);
	execute_opcode(&c);
	printf("MC: %d TS: %d\n", c.m_cycles, c.t_states);
	printf("AF: %x - AF': %x\n", c.main.af, c.alternative.af);
	return 0;
}
