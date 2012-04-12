
extern void (*instructions[])(void);

void init_cpu() {
}

void cpu_cycle() {

    instructions[0]();
    instructions[1]();

    instructions[2]();
    instructions[2]();
    instructions[2]();

}
