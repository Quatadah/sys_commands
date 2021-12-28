#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#define MAXBUFFERSIZE 256

int main(int argc, char *argv[]){
    int fd;
    if ((fd = open("versserveur.fifo", O_RDWR)) == -1){
        perror("open() failed\n");
        return EXIT_FAILURE;
    }else{
        while(1){
        int rd;
        char buffer[MAXBUFFERSIZE];
        if ((rd = read(STDIN_FILENO, buffer, MAXBUFFERSIZE)) == -1){
            perror("read() failed\n");
            return EXIT_FAILURE;
        }else{
            int wr;
            if ((wr = write(fd, buffer, rd)) == -1){
                perror("write() failed\n");
                return EXIT_FAILURE;
            }
        }
        }
    }
    return 0;
}