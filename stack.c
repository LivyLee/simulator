#include "simulator.h"

extern unsigned char *ebp;
extern unsigned char *esp;

extern unsigned char *memory;

void init_stack(){

    ebp = memory + (MEMORYSIZE - 1);
    esp = memory + (MEMORYSIZE - 1);
    
}
