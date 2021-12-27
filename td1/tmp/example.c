#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void readfile(const char* pathname, int count, char *buf){
    int fd, byte, length=count;
    fd = open(pathname, O_RDONLY);
    if (fd == -1){
        perror("open() failed");
        exit(1);
    }

    /* Read count bytes from file */
    while ((byte = read(fd, buf, length)) != 0){
        printf("byte = %d\n", byte);
        if (byte == -1){
            perror("read() failed");
            exit(1);
        }
        length = length - byte;
        buf = buf + length;
        printf("%s\n", buf);
    }
    close(fd);
}

int main(int argc, char* argv[]){
    char buf[256];
    int count = 37;
    char path[] = "./test.txt";
    readfile(path, count, buf);
    return EXIT_SUCCESS;
}