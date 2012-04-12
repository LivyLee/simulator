#include <stdio.h>

#include "simulator.h"

extern unsigned char *memory, *ebp, *esp, *eip;

extern int eax, ebx, ecx, edx, esi, edi;

void memory_dump() {

    int i, e;

    printf("Memory Dump:\n");
    for(i=0,e=1;i<MEMORYSIZE;i++, e++) {

        printf("0x%.2x   ", memory[i]);

        if(e == 16){
            puts("");
            e = 0;
        }
    }

    printf("Registers\n");
    printf("eax: %.2x   ebx: %.2x   ecx: %.2x   edx: %.2x   esi: %.2x   edi: %.2x   ebp: %p   esp: %p   eip: %p\n",
            eax, ebx, ecx, edx, esi, edi, ebp, esp, eip);

}
