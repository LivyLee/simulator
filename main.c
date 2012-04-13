#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "simulator.h"

#define MEMORY_SIZE


int main(int argc, char **argv) {

    if(argc < 2) {
        printf("Especifique o arquivo com o codigo\n");
        exit(0);
    }

    init_memory();

    init_stack();

    loadcode(argv[1]);

    init_cpu();

    while(cpu_cycle());

    memory_dump();

    free_memory();
    return 0;
}
