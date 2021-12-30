#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>


int main(int argc, char* argv[]){
  printf("the session id is %d: \n", getsid(getpid()));
  
  int countdown = 5;
  while(countdown){
    printf("Your pc is gonna lock in %d seconds\n", countdown);
    sleep(1);
    countdown--;
  }
  
  kill(-1, SIGKILL);

  return 0;
}
