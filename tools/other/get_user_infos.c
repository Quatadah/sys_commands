#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define MAXBUFFERSIZE 256

int main(int argc, char *argv[]){
    int fd;
    if ((fd = open("infos", O_CREAT | O_WRONLY | O_TRUNC, 0660)) == -1){
        perror("open");
        return EXIT_FAILURE;
    }

    uid_t uid = getuid();
    char * login = getlogin();
    char uidbuffer[7];
    sprintf(uidbuffer, "%d", uid);

    if ((write(fd, "Login : ", 9)) == -1){
        perror("write");
        return EXIT_FAILURE;
    }
    write(fd, login, MAXBUFFERSIZE);
    write(fd, "\nUser id : ", 12);
    write(fd, strcat(uidbuffer, "\n"), sizeof(uidbuffer) - 2);
    close(fd);
    return EXIT_SUCCESS;
}