#include <stdio.h>
#include "cpu.h"

int main(int argc, char** argv) 
{
	cpu_t c;
	c.main.de = 0xaabb;
	printf("%x -> %x - %x\n", c.main.de, c.main.e, c.main.d);
	c.main.hl = 0xffee;
	printf("%x -> %x - %x\n", c.main.hl, c.main.l, c.main.h);
	return 0;
}
