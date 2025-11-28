#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  unsigned int child_pid;
  child_pid = fork();

  if(child_pid == 0){ // child process
    sleep(1);
    printf("Child proess PID: %lu\n", (unsigned long)getpid());
    printf("Child proess PPID: %lu\n", (unsigned long)getppid());
    return 7;
  }
  else{ // parent process
    int wstatus;
    //waitpid(child_pid, &wstatus, 0);
    if(WIFEXITED(wstatus)){
      printf("Child exited with status: %d\n", WEXITSTATUS(wstatus));
    }
    printf("Parent process PID: %lu\n", (unsigned long)getpid());
    printf("Parent process PPID: %lu\n", (unsigned long)getppid());
  }

  return 0;
}