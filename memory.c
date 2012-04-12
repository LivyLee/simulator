#include <string.h>
#include <stdlib.h>

#include "simulator.h"

unsigned char *memory;

void init_memory() {
    memory = (unsigned char *) malloc(MEMORYSIZE);
    memset(memory, 0, MEMORYSIZE);
}

void free_memory() {
    free(memory);
}
