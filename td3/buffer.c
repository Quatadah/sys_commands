#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define CHAINE1 "Hello\n"
#define CHAINE2 "World!"

void show(){
#ifdef USE_FPRINTF


#ifdef OUT
fprintf(stdout, CHAINE1);
sleep(3);
fprintf(stdout, CHAINE2);
#elif ERR
fprintf(stderr, CHAINE1);
sleep(3);
fprintf(stderr, CHAINE2);
#endif


#elif USE_WRITE

#ifdef OUT
write(STDOUT_FILENO, CHAINE1, strlen(CHAINE1));
sleep(3);
write(STDOUT_FILENO, CHAINE2, strlen(CHAINE2));

#elif ERR
write(STDERR_FILENO, CHAINE1, strlen(CHAINE1));
sleep(3);
write(STDERR_FILENO, CHAINE2, strlen(CHAINE2));
#endif

#endif

#ifdef EXIT
_exit(1);
#else
exit(1);
#endif
}


int main(int argc, char *argv[]){
  show();
  
  return EXIT_SUCCESS;
}