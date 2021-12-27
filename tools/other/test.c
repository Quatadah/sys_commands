#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main(){
    if (fork() == 0) execl("/bin/ls", "ls", NULL);
    else {
        sleep(10);
        printf("Je suis le père et je peux continuer\n");
    }
}