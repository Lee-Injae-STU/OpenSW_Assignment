#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argv, char* argc[]){
  if(argv < 2){
    printf("Usage: ./03_execve <program> [OPTION] ...\n");
    return -1;
  }
  
  int child_pid = fork();

  if(child_pid == 0){
    execve(argc[1], argc + 1, NULL);
  }
  else{
    int wstatus;
    waitpid(child_pid, &wstatus, 0);
    if(WIFEXITED(wstatus)){
      printf("Child exited with status: %d\n", WEXITSTATUS(wstatus));
    }
  }
  return 0;
}