#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
    if (argc == 1){
        printf("At least one argument is mandatory ..\n");
        exit(1);
    }
    int i = 1;
    while (i != argc){
        if ((write(STDOUT_FILENO, argv[i], strlen(argv[i]))) == -1){
            perror("write() failed");
            exit(1);
        }
        write(STDOUT_FILENO, " ", 1);
        i++;
    }
    printf("\n");
    exit(0);
}