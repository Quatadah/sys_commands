#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define STDOUT 1

int main(int argc, char* argv[]){
    int fd;
    if ((fd = open("ps_out", O_WRONLY | O_CREAT | O_TRUNC, 0660)) == -1){
        perror("Unable to open the file");
        return EXIT_FAILURE;
    }
    
    dup2(fd, STDOUT);
    execl("/bin/ps", "ps", NULL);
    return EXIT_SUCCESS;

}