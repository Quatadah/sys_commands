#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

char *string;
void ping_sh(int s){
  printf("%s\n", string);
}

void ping(pid_t p){
  signal(SIGUSR1, ping_sh);
  for (int i = 0; i < 10; i++){
    if (p==0){ // processus fils
      kill(getppid(), SIGUSR1);
      pause();
      sleep(1);
    }else{
      pause();
      sleep(1);
      kill(p, SIGUSR1);
    }
  }
}

int main(){
  pid_t p;
  p = fork();
  switch(p){
  case -1:
    perror("fork() failed\n");
    exit(1);
  case 0: // processus fils
    string="pong";
    break;
  default:
    string="ping";
    break;
  }
  ping(p);
  return 0;
}
