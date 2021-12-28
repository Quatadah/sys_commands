#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void zones(){
        int t[10];
        int s = 0;
        void *p = malloc(10);
        printf("Code: %p\nData: %p\nHeap: %p, %p\nStack: %p\n", zones, t, sbrk(0), p, &s);
        free(p);
    }

int main(int argc, char *argv[]){
    //zones();
    pid_t id = fork();
    switch(id){
        case 0:
            printf("Je suis le fils\n");
            break;
        case -1:
            printf("Erreur\n");
            break;
        default:
            printf("Je suis le père\n");
            break;
    }


    return 0;
}