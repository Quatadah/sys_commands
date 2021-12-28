#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  
#include <dirent.h>

char get_type(mode_t m){
    if (S_ISREG(m))
        return 'r';
    if (S_ISDIR(m))
        return 'd';
    else
        return 'u';
}

int main(int argc, char* argv[]){
    if (argc == 1 || argc > 2){
        fprintf(stderr, "the path to the repository is mandatory ..\n");
        return EXIT_FAILURE;
    }
    DIR* d;
    struct dirent *dirent;
    struct stat st;
    d = opendir(argv[1]);
    while ((dirent = readdir(d)) != NULL){
        stat(dirent->d_name, &st);
        printf("%s - %c \n", dirent->d_name, get_type(st.st_mode));
    }
    closedir(d);
    return EXIT_SUCCESS;
}