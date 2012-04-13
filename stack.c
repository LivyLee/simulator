#include "simulator.h"

extern unsigned int ebp;
extern unsigned int esp;


void init_stack(){

    ebp = MEMORYSIZE - 1;
    esp = MEMORYSIZE - 1;
    
}
