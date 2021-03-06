#include <stdio.h>
#include "cpu.h"
#include "opcodes.h"

#define K_NORMAL "\x1B[0m"
#define K_GREEN "\x1B[32m"
#define K_RED "\x1B[31m"
#define K_WHITE "\x1B[37m"

void test_nop() {

	printf("%sOpcode NOP:", K_WHITE);
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

void test_ex_af_af()
{
	printf("%sOpcode EX AF,AF':", K_WHITE);
	cpu_t cpu;
	cpu.pc = 0x0000;
	cpu.mem[0x0000] = 0x08;
	cpu.main.af = 0xaa;
	cpu.alternative.af = 0xbb;
	execute_opcode(&cpu);
	if (cpu.m_cycles == 1 &&
	    cpu.t_states == 4 &&
	    cpu.main.af == 0xbb &&
	    cpu.alternative.af == 0xaa)
	{
		printf("%sOK", K_GREEN);
	}
	else
	{
		printf("%sERROR", K_RED);
	}
	printf("\n");	
	

}

void test_djnz()
{
	printf("%sOpcode DJNZ, d:", K_WHITE);
	cpu_t cpu;
	cpu.pc = 0x00ff;
	cpu.mem[0x00ff] = 0x10;
	cpu.mem[0x0100] = 0x05;
	cpu.main.b = 0x0a;
	execute_opcode(&cpu);
	if (cpu.m_cycles == 3 &&
	    cpu.t_states == 13 &&
	    cpu.main.b == 0x09 &&
	    cpu.pc == 0x0106)
	{
		printf("%sOK", K_GREEN);
	}
	else
	{
		printf("%sERROR", K_RED);
	}
	printf("\n");	
	
}

void test_jr()
{
	printf("%sOpcode JR d:", K_WHITE);
	cpu_t cpu;
	cpu.pc = 0x00fa;
	cpu.mem[0x00fa] = 0x18;
	cpu.mem[0x00fb] = 0x06;
	execute_opcode(&cpu);
	if (cpu.m_cycles == 3 &&
	    cpu.t_states == 12 &&
	    cpu.pc == 0x0102)
	{
		printf("%sOK", K_GREEN);
	}
	else
	{
		printf("%sERROR", K_RED);
	}
	printf("\n");
}

void test_jrc() 
{
	printf("%sOpcode JR C,d:", K_WHITE);
	cpu_t cpu;
	cpu.main.f &= FLAG_C;
	cpu.pc = 0x00fa;
	cpu.mem[0x00fa] = 0x38;
	cpu.mem[0x00fb] = 0x06;
	execute_opcode(&cpu);
	if (cpu.m_cycles == 3 &&
	    cpu.t_states == 12 &&
	    cpu.pc == 0x0102)
	{
		cpu.main.f = 0x0;
		cpu.pc = 0x00fa;
		cpu.mem[0x00fa] = 0x38;
		cpu.mem[0x00fb] = 0x06;
		execute_opcode(&cpu);
		if (cpu.m_cycles == 2 &&
		    cpu.t_states == 7 &&
		    cpu.pc == 0xfc)
		{
			printf("%sOK", K_GREEN);
		}
		else
		{
			printf("%sERROR", K_RED);
		}
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
	test_ex_af_af();
	test_djnz();
	test_jr();
	test_jrc();
	printf("%s\n", K_NORMAL);
	return 0;
}
