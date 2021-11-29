#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>



int main(int argc, char *argv[]){
    if (argc != 2){
        fprintf(stderr, "One argument is necessary\n");
        return EXIT_FAILURE;
    }
    DIR* d;
    if ((d = opendir(argv[1])) == NULL){
        perror("opendir");
        return EXIT_FAILURE;
    }

    struct stat st;
    struct dirent *dir = NULL;
    while((dir = readdir(d)) != NULL){
        stat(dir->d_name, &st);
        if (S_ISREG(st.st_mode)){  
            printf("Name: %s\nSize: %ld octets\n\n", dir->d_name, st.st_size);
        }
    }
    closedir(d);
    return EXIT_SUCCESS;
}