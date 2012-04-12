#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

extern unsigned char *memory, *eip;

void loadcode(char *file) {

    int fd;
    int data;
    unsigned char *m;
    unsigned char buf;

    fd = open(file, O_RDONLY);

    if(fd == -1) {
        printf("Nao foi possivel abrir o arquivo\n");
        exit(0);
    }

    m = memory;

    // EIP aponta pro inicio do codigo
    eip = m;

    while((data = read(fd, &buf, 1))) {

        memcpy(m, &buf, 1);
        m++;

    }



    close(fd);

}
