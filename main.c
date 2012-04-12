#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "simulator.h"

#define MEMORY_SIZE


int main(int argc, char **argv) {

    init_memory();

    init_stack();

    init_cpu();

    loadcode(argv[1]);

    cpu_cycle();

    memory_dump();

    free_memory();
    return 0;
}
