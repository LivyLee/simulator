#ifndef SIMULATOR_H
#define SIMULATOR_H


#define MEMORYSIZE 4096

// Memory functions
void init_memory();
void free_memory();

// Stack function
void init_stack();

// CPU
void init_cpu();
int cpu_cycle();

// Loader
void loadcode(char *);

// Memory Dumper
void memory_dump();

#endif
