all:
	clang -O3 -c -Wall main.c
	clang -O3 -c -Wall memory.c
	clang -O3 -c -Wall instr.c
	clang -O3 -c -Wall cpu.c
	clang -O3 -c -Wall stack.c
	clang -O3 -c -Wall regs.c
	clang -O3 -c -Wall loader.c
	clang -O3 -c -Wall memdump.c
	clang -g stack.o regs.o memory.o memdump.o loader.o instr.o cpu.o main.o -o simulator
	nasm -f macho code.asm

debug:
	clang -O0 -c -Wall -g -pg main.c
	clang -O0 -c -Wall -g -pg memory.c
	clang -O0 -c -Wall -g -pg instr.c
	clang -O0 -c -Wall -g -pg cpu.c
	clang -O0 -c -Wall -g -pg stack.c
	clang -O0 -c -Wall -g -pg regs.c
	clang -O0 -c -Wall -g -pg loader.c
	clang -O0 -c -Wall -g -pg memdump.c
	clang -g -pg stack.o regs.o memory.o memdump.o loader.o instr.o cpu.o main.o -o simulator
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
	rm -rf *.o *.plist *.dSYM *.out simulator
