add_executable(main
	main.c
	)
target_link_libraries(main z80)

install(TARGETS main DESTINATION bin)
