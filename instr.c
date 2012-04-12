#include <stdio.h>
#include <string.h>

#include "simulator.h"

extern int eax, ebx, ecx, edx, esi, edi, eip;

extern unsigned char *esp, *ebp;

extern unsigned char *memory;

static void mov() {

    eax = 10;

    printf("Execute an mov instruction\n");

}

static void add() {

    printf("Execute an add instruction\n");

}

static void push() {

    printf("Execute an push instruction\n");

    if(esp == (memory + MEMORYSIZE - 1)) {
        esp -= 3;
    } else {
        esp -= 4;
    }

    unsigned int value = 4;
    memcpy(esp, &value, 4);



}

void (*instructions[])(void) = {
[0x00]  =   mov,
[0x01]  =   add,
[0x02]  =   push,
};
