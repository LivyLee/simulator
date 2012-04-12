all:
	clang -O0 -c -Wall -g main.c
	clang -O0 -c -Wall -g memory.c
	clang -O0 -c -Wall -g instr.c
	clang -O0 -c -Wall -g cpu.c
	clang -O0 -c -Wall -g stack.c
	clang -O0 -c -Wall -g regs.c
	clang -O0 -c -Wall -g loader.c
	clang -O0 -c -Wall -g memdump.c
	clang -g stack.o regs.o memory.o memdump.o loader.o instr.o cpu.o main.o -o simulator
	nasm -f macho code.asm

analyze:
	clang --analyze main.c
	clang --analyze memory.c
	clang --analyze instr.c
	clang --analyze cpu.c
	clang --analyze stack.c
	clang --analyze regs.c
	clang --analyze loader.c
	clang --analyze memdump.c

clean:
	rm -rf *.o *.plist *.dSYM simulator
