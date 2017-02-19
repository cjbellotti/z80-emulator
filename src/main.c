#include <stdio.h>
#include "cpu.h"
#include "opcodes.h"

int main(int argc, char** argv) 
{
	cpu_t c;
	c.pc = 0x0000;
	c.mem[0x0000] = 0xaf;
	execute_opcode(&c);
	return 0;
}
