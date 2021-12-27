#include <unistd.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXBUFFER 256

int main(int argc, char *argv[]){

    while (1)
    {
        ssize_t r, w;
        char buffer[MAXBUFFER];
        if ((r = read(STDIN_FILENO, buffer, MAXBUFFER)) == -1){
            perror("read() failed\n");
            exit(1);
        }
        if ((w = write(STDOUT_FILENO, buffer, r)) == -1){
            perror("write() failed\n");
            exit(1);
        }
    }
    
    

    return 0;
}