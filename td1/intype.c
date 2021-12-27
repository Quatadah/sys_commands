#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int main(int argc, char *argv[]){
    struct stat st;
    if (fstat(STDIN_FILENO, &st) == -1){
        perror("fstat() failed\n");
        exit(1);
    }
    if (S_ISREG(st.st_mode))
        printf("Regular file\n");
    else if (S_ISDIR(st.st_mode))
        printf("Directory \n");
    else if (S_ISBLK(st.st_mode))
        printf("Block\n");
    else if (S_ISCHR(st.st_mode))
        printf("Character device\n");
    else if (S_ISFIFO(st.st_mode))
        printf("Fifo \n");
    else if (S_ISLNK(st.st_mode))
        printf("Link\n");
    else if (S_ISSOCK(st.st_mode))
        printf("Socket\n");

    return 0;
}
