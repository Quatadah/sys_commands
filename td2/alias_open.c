#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXBUFFERSIZE 256

int check(int x,char *msg) {
    if (x == -1){ 
        perror(msg); 
        return EXIT_FAILURE; 
    }
}

int main(int argc, char* argv[]){
    int fd, rd, wr, cl;
    char buffer[MAXBUFFERSIZE];
    fd = open("data.txt", O_RDONLY);
    check(fd, "open() failed\n");

    rd = read(fd, buffer, 4);
    check(rd, "read() failed\n");

    wr = write(STDOUT_FILENO, buffer, rd);
    check(wr, "write() failed\n");

    fd = open("data.txt", O_RDONLY);
    check(fd, "open() failed\n");

    rd = read(fd, buffer, 4);
    check(rd, "read() failed\n");

    wr = write(STDOUT_FILENO, buffer, rd);
    check(wr, "write() failed\n");

    cl = close(fd);
    check(cl, "close() failed\n");

    return EXIT_SUCCESS;
}