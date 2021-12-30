#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>


#define MAXSIZE 256

int main(int argc, char *argv[]){
  int fd, status;
  if (argc <= 2){
    fprintf(stderr, "At least three arguments are mandatory !\n");
    exit(1);
  }
  fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
  pid_t pid;
  pid = fork();
  switch(pid){
  case -1:
    perror("fork() failed");
    exit(1);
  case 0:
    if (fd == -1){
      perror("open() failed");
      exit(1);
    }
    if (dup2(fd, STDOUT_FILENO) == -1){
      perror("dup2() failed");
      exit(1);
    }
    execvp(argv[2], argv + 2);
  default:
    if (wait(&status) == -1){ 
      perror("wait() failed");
      exit(1); 
    } 
    if (WIFEXITED(status)) 
      printf("Normally exited, code : %d\n", WEXITSTATUS(status)); 
    else { 
      if (WIFSIGNALED(status)){ 
 	printf("Ended with a signal, signal code : %d\n", WTERMSIG(status)); 
      } 
    } 
  }
  close(fd);
  exit(0);
}
