#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int exist(char *str, char *tab[], int len){
    for(int i = 0; i < len; i++){
        if (strcmp(str, tab[i]) == 0){
            return i;
        }
    }
    return -1;
}


int main(int argc, char* argv[]){
    int then_index, else_index;
    if ((strcmp(argv[1], "if") == 0) 
        && (then_index = exist("then", argv, argc) != -1) 
        && (else_index = exist("else", argv, argc) != -1) ) {
            if (fork() == 0){
                char *cat = strcat("/bin/", argv[1]);
                execl(cat);
            }else{

            }

            return EXIT_SUCCESS;
    }
    printf("failure\n");
    return EXIT_FAILURE;
}