#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void donotdo(int sig){
  printf("alarm ...\n");
}

void mysleep(unsigned int s){
  signal(SIGALRM, donotdo);
  alarm(s);
  pause();
}

int main(int argc, char *argv[]){
  mysleep(atoi(argv[1]));
  return 0;
}
