#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>


void it_fils(){
    printf("\tInterrepution : kill(getpid(), SIGINT)\n");
    kill(getpid(), SIGINT);
}

void fils(){
    signal(SIGUSR1, it_fils);
    printf("Looping !\n");
    while(1);
}

int main(){
    int pid;
    if ((pid = fork()) == 0) fils();
    else {
        sleep(3);
        printf(" kill (pid, SIGUSR1) ;\n");
        kill(pid, SIGUSR1);
    }
    return 0;
}