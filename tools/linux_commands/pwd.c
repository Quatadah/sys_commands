#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXBUFFERSIZE 256


int main(int argc, char *argv[]){

    char buf[MAXBUFFERSIZE];
    char *wd = NULL;
    wd = getwd(buf);
    printf("%s \n", wd);
    return EXIT_SUCCESS;
}