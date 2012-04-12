
extern void (*instructions[])(int);

extern unsigned char *eip;

void init_cpu() {
    
}

void cpu_cycle() {

    instructions[*eip](*eip);

}
