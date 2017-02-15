#ifndef REGISTERS_H
#define REGISTERS_H
#include <stdint.h>

typedef struct {
	struct {
		union {
			struct {
				uint8_t f;
				uint8_t a;
			};
			uint16_t af;
		};
	};

	struct {
		union {
			struct {
				uint8_t c;
				uint8_t b;
			};
			uint16_t bc;
		};
	};

	struct {
		union {
			struct {
				uint8_t e;
				uint8_t d;
			};
			uint16_t de;
		};
	};

	struct {
		union {
			struct {
				uint8_t l;
				uint8_t h;
			};
			uint16_t hl;
		};
	};

	uint16_t sp;     // Stack Pointer
	uint16_t pc;     // Program Counter
	uint16_t ix;     // Index X
	uint16_t iy;     // Index Y

	uint8_t i;       // Interrupt Vector
	uint8_t r;       // Memory Refresh
} registers_t;
#endif
