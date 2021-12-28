#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>

#define FIFONAME "versserveur.fifo"
#define MAXBUFFERSIZE 256


int main(int argc, char *argv[]){
    int mk, fd, rd, wr;
    char buffer[MAXBUFFERSIZE];

    mk = mknod(FIFONAME, S_IFIFO | 0666, 0);
    if (mk == -1){
        perror("mknod() failed\n");
        return EXIT_FAILURE;
    }
    fd = open(FIFONAME, O_RDONLY);
    if (fd == -1){
        perror("open() failed\n");
        return EXIT_FAILURE;
    }
    while(1){
    rd = read(fd, buffer, MAXBUFFERSIZE);
    if (rd == -1){
        perror("read() failed\n");
        return EXIT_FAILURE;
    }

    wr = write(STDOUT_FILENO, buffer, rd);
    if (wr == -1){
        perror("write() failed\n");
        return EXIT_FAILURE;
    }
    }
    return 0;
}