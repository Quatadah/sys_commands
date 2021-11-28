#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



int main(int argc, char *argv[]){
    if (argc != 2){
        printf("One argument is necessary\n");
        return EXIT_FAILURE;
    }
    struct stat st;
    if ((stat(argv[1], &st)) == -1){
        perror("stat");
        return EXIT_FAILURE;
    }
    printf("the file %s is%s executable\n", argv[1], st.st_mode & S_IXUSR ? "" : " not");
    
    return EXIT_SUCCESS;
}