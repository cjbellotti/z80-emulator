add_executable(main
	main.c
	)
add_executable(test
	test.c
	)
target_link_libraries(main z80)
target_link_libraries(test z80)

install(TARGETS main DESTINATION bin)
