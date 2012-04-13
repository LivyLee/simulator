#include <stdio.h>
#include <string.h>

#include "simulator.h"

extern int eax, ebx, ecx, edx, esi, edi;

extern unsigned int esp, ebp;

extern unsigned int eip;

extern unsigned char *memory;

static void mov(int i) {

    printf("Execute an mov instruction\n");

    unsigned char *ip;

    switch(i) {
        case 0xb8:
            eip++;
            ip = &(memory[eip]);
            memcpy(&eax, ip, 4);
            eip += 4;
            break;
        case 0xbb:
            eip++;
            ip = &memory[eip];
            memcpy(&ebx, ip, 4);
            eip += 4;
            break;
        case 0xbd:
            eip++;
            ip = &memory[eip];
            memcpy(&ebp, ip, 4);
            eip += 4;
            break;
        case 0xbc:
            eip++;
            ip = &memory[eip];
            memcpy(&esp, ip, 4);
            eip += 4;
            break;
        case 0xb9:
            eip++;
            ip = &memory[eip];
            memcpy(&ecx, ip, 4);
            eip += 4;
            break;
        case 0xba:
            eip++;
            ip = &memory[eip];
            memcpy(&edx, ip, 4);
            eip += 4;
            break;
        case 0xbe:
            eip++;
            ip = &memory[eip];
            memcpy(&esi, ip, 4);
            eip += 4;
            break;
        case 0xbf:
            eip++;
            ip = &memory[eip];
            memcpy(&edi, ip, 4);
            eip += 4;
            break;
    }

}

//static void add(int i) {
//    printf("Execute an add instruction\n");
//}

static void push(int i) {

    printf("Execute an push instruction\n");

    unsigned char *sp;

    if(esp == MEMORYSIZE - 1) {
        esp -= 3;
    } else {
        esp -= 4;
    }


    switch(i) {
        case 0x50:
            sp = &memory[esp];
            memcpy(sp, &eax, 4);
            eip++;
            break;
        case 0x51:
            sp = &memory[esp];
            memcpy(sp, &ecx, 4);
            eip++;
            break;
        case 0x52:
            sp = &memory[esp];
            memcpy(sp, &edx, 4);
            eip++;
            break;
        case 0x53:
            sp = &memory[esp];
            memcpy(sp, &ebx, 4);
            eip++;
            break;
        case 0x54:
            sp = &memory[esp];
            memcpy(sp, &ebp, 4);
            eip++;
            break;
        case 0x55:
            sp = &memory[esp];
            memcpy(sp, &esp, 4);
            eip++;
            break;
        case 0x56:
            sp = &memory[esp];
            memcpy(sp, &esi, 4);
            eip++;
            break;
        case 0x57:
            sp = &memory[esp];
            memcpy(sp, &edi, 4);
            eip++;
            break;
        case 0x68:
            //memcpy(esp, &edi, 4);
            //68 0a 00 00 00        push   $0xa
            break;
    }



}

static void nop(int i){
    printf("Executing an nop instruction\n");
    eip++;

}

void (*instructions[])(int) = {
[0x50]  =   push,
[0x51]  =   push,
[0x52]  =   push,
[0x53]  =   push,
[0x54]  =   push,
[0x55]  =   push,
[0x56]  =   push,
[0x57]  =   push,
[0x68]  =   push,
[0x90]  =   nop,
[0xb8]  =   mov,
[0xbb]  =   mov,
[0xb9]  =   mov,
[0xba]  =   mov,
[0xbd]  =   mov,
[0xbc]  =   mov,
[0xbe]  =   mov,
[0xbf]  =   mov,
};
