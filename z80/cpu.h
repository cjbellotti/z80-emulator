#ifndef CPU_H
#define CPU_H
#include "registers.h"

enum flag_t
{
	FLAG_S = 0x80,	// Sign flag
	FLAG_Z = 0x40,	// Zero flag
	FLAG_5 = 0x20,	// 5-flag (reserved)
	FLAG_H = 0x10,	// Half carry flag
	FLAG_3 = 0x08,	// 3-flag (reserved)
	FLAG_P = 0x04,	// Parity/Overflow flag
	FLAG_N = 0x02,	// DAA flag
	FLAG_C = 0x01	// Carry flag
};

typedef struct {
       	uint8_t mem[0xffff];		// Memory	
	registers_t main;		// Main Registers Bank
	registers_t alternative;	// Alternative Registers Bank

	uint16_t sp;     		// Stack Pointer
	uint16_t pc;     		// Program Counter
	uint16_t ix;     		// Index X
	uint16_t iy;     		// Index Y

	uint8_t i;       		// Interrupt Vector
	uint8_t r;       		// Memory Refresh
	
	uint8_t m_cycles;
	uint8_t t_states;
} cpu_t;

#endif
