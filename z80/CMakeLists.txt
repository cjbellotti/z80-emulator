add_library(z80 STATIC
	cpu.h
	opcodes.h
	opcodes.c
	)

target_include_directories(z80 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
