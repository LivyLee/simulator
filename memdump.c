#include <stdio.h>

#include "simulator.h"

extern unsigned char *memory;
extern unsigned int ebp, esp;

extern int eax, ebx, ecx, edx, esi, edi;

extern unsigned int eip;

void memory_dump() {

    int i, e, addr;

    addr = 0;

    printf("Memory Dump:\n");
    printf("0x%-8.2x", addr);
    for(i=0,e=1;i<MEMORYSIZE;i++, e++) {


        printf("0x%.2x   ", memory[i]);
        if(e == 16){
            addr += e;
            puts("");
            printf("0x%-8.2x", addr);
            e = 0;
        }

    }

    printf("\nRegisters\n");
    printf("eax: 0x%.2x   ebx: 0x%.2x   ecx: 0x%.2x   edx: 0x%.2x   esi: 0x%.2x   edi: 0x%.2x   ebp: 0x%.2x   esp: 0x%.2x   eip: 0x%.2x\n",
            eax, ebx, ecx, edx, esi, edi, ebp, esp, eip);

}
