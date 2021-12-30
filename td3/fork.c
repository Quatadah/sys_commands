#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>



int main(int argc, char *argv[]){
    pid_t pid;
    printf("this is my pid : %d\n", getpid());
    pid = fork();
    switch (pid)
    {
    case 0:
        printf("my pid is : %d and I'm the son\n", getpid());
        printf("this is my father's pid : %d\n", getppid());
        break;
    
    default:
        break;
    }
    
    return 0;
}