#include "simulator.h"

extern void (*instructions[])(int);

extern unsigned int eip;
extern unsigned char *memory;

void init_cpu() {

    eip = 0;
}

void cpu_cycle() {

    instructions[memory[eip]](memory[eip]);


}
