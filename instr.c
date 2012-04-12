#include <stdio.h>
#include <string.h>

#include "simulator.h"

extern int eax, ebx, ecx, edx, esi, edi;

extern unsigned char *esp, *ebp, *eip;

extern unsigned char *memory;

static void mov(int i) {

    printf("Execute an mov instruction\n");

    switch(i) {
        case 0xb8:
            eip++;
            memcpy(&eax, eip, 4);
            eip += 4;
            break;
        case 0xbb:
            eip++;
            memcpy(&ebx, eip, 4);
            eip += 4;
            break;
        case 0xb9:
            eip++;
            memcpy(&ecx, eip, 4);
            eip += 4;
            break;
        case 0xba:
            eip++;
            memcpy(&edx, eip, 4);
            eip += 4;
            break;
        case 0xbe:
            eip++;
            memcpy(&esi, eip, 4);
            eip += 4;
            break;
        case 0xbf:
            eip++;
            memcpy(&edi, eip, 4);
            eip += 4;
            break;
    }

}

//static void add(int i) {
//    printf("Execute an add instruction\n");
//}

static void push(int i) {

    printf("Execute an push instruction\n");

    if(esp == (memory + MEMORYSIZE - 1)) {
        esp -= 3;
    } else {
        esp -= 4;
    }


    switch(i) {
        case 0x50:
            printf("\tpush 0x50\n");
            memcpy(esp, &eax, 4);
            eip++;
            break;
        case 0x51:
            printf("\tpush 0x51\n");
            memcpy(esp, &ecx, 4);
            eip++;
            break;
        case 0x52:
            printf("\tpush 0x52\n");
            memcpy(esp, &edx, 4);
            eip++;
            break;
        case 0x53:
            printf("\tpush 0x53\n");
            memcpy(esp, &ebx, 4);
            eip++;
            break;
        case 0x56:
            printf("\tpush 0x56\n");
            memcpy(esp, &esi, 4);
            eip++;
            break;
        case 0x57:
            printf("\tpush 0x57\n");
            memcpy(esp, &edi, 4);
            eip++;
            break;
        case 0x68:
            //memcpy(esp, &edi, 4);
            //68 0a 00 00 00        push   $0xa
            break;
    }



}

void (*instructions[])(int) = {
[0x50]  =   push,
[0x51]  =   push,
[0x52]  =   push,
[0x53]  =   push,
[0x56]  =   push,
[0x57]  =   push,
[0x68]  =   push,
[0xb8]  =   mov,
[0xbb]  =   mov,
[0xb9]  =   mov,
[0xba]  =   mov,
[0xbe]  =   mov,
[0xbf]  =   mov,
};
