#include "simulator.h"

extern void (*instructions[])(int);

extern unsigned int eip;
extern unsigned char *memory;

void init_cpu() {

    eip = 0;
}

int cpu_cycle() {

    if(memory[eip] != 0x00) {
        instructions[memory[eip]](memory[eip]);
        return 1;
    }

    return 0;


}
