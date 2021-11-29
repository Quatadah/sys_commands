#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

ssize_t file_size(char* path){
    struct stat st;
    if (stat(path, &st) == 0){
        return st.st_size;
    } else {
        perror("Cannot have the file size");
        return -1;
    }
}

int main(int argc, char *argv[]){
    if (argc != 2){
        perror("One argument is needed!");
        return EXIT_FAILURE;
    }

    ssize_t size = file_size(argv[1]);
    if (size != -1){
        printf("Size of %s : %ld\n", argv[1], size);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}