#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>

void it_horloge(int sig){
    printf("Réception du signal %d : SIGALARM\n", sig);
}

void main(){
    unsigned sec;
    signal(SIGALRM, it_horloge);
    printf("On fait alarm(5)\n");
    sec = alarm(5);
    printf("Valeur retournée par alarm : %d\n", sec);
    printf("La principale boucle à l'infini (CTRL-c pour arrêter)\n");
    signal(SIGALRM, it_horloge);
    alarm(3);
    for(;;);
    
}