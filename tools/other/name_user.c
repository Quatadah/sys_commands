#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc, char *argv[]){
    if (argc != 2){
        fprintf(stderr, "One argument is necessary\n");
        return EXIT_FAILURE;
    }
    struct passwd *pswd;
    if ((pswd = getpwuid(atoi(argv[1]))) == NULL){
        fprintf(stderr, "This user id does not exist\n");
        return EXIT_FAILURE;
    }
    
    printf("Username : %s\n", pswd->pw_name);
    printf("Password : %s\n", pswd->pw_passwd);

    return EXIT_SUCCESS;
}