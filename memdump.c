#include <stdio.h>

#include "simulator.h"

extern char *memory;

void memory_dump() {

    int i, e;

    printf("Memory Dump:\n");
    for(i=0,e=1;i<MEMORYSIZE;i++, e++) {

        printf("0x%x ", memory[i]);

        if(e == 32){
            puts("");
            e = 0;
        }
    }

}
