#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
    long a = 5;
    ssize_t r = write(STDOUT_FILENO, &a, sizeof(a));
    if (r == -1){
        perror("write() failed\n");
        exit(1);
    } else if (r != sizeof(a)){
        fprintf(stderr, "Less bytes than expected were written ...\n");
        exit(1);
    }
    r = write(STDOUT_FILENO, &r, sizeof(r));
    if (r == -1){
        perror("write() (2) failed\n");
        exit(1);
    } else if (r != sizeof(r)){
        fprintf(stderr, "Less bytes than expected were written (2) ...\n");
        exit(1);
    }
    
    return 0;
}