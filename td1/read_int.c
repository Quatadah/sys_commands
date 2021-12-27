#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
    ssize_t r, w;
    long l;

    r = read(STDIN_FILENO, &l, sizeof(l));
    if (r == -1){
        perror("read() failed\n");
        exit(1);
    }
    printf("value : %ld\n", l);
    return 0;
}