#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void type(mode_t mode){
    if (S_ISREG(mode))
        printf("Regular file\n");
    else if (S_ISDIR(mode))
        printf("Directory \n");
    else if (S_ISBLK(mode))
        printf("Block\n");
    else if (S_ISCHR(mode)))
        printf("Character device\n");
    else if (S_ISFIFO(mode))
        printf("Fifo \n");
    else if (S_ISLNK(mode))
        printf("Link\n");
    else if (S_ISSOCK(mode))
        printf("Socket\n");
}

int main(int argc, char *argv[]){
    struct stat st;
    if (fstat(STDIN_FILENO, &st) == -1){
        perror("fstat() failed\n");
        exit(1);
    }
    type(st.st_mode);

    return 0;
}
