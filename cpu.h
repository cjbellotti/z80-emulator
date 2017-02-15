#ifndef CPU_H
#define CPU_H
#include "registers.h"
typedef struct {
       	uint8_t mem[0xffff];		// Memory	
	registers_t main;			// Main Registers Bank
	registers_t alternative;		// Alternative Registers Bank
} cpu_t;
#endif
