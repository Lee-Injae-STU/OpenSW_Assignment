#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int my_system(const char* command){
  int child_pid = fork();

  if(child_pid == 0){
    execl("/bin/sh", "sh", "-c", command, (char *) NULL);
  }
  else{
    int wstatus;
    waitpid(child_pid, &wstatus, 0);
  }
}

int main(){
  my_system("ls -l | wc -l");
  my_system("find . -name '*.c'");

  printf("Good bye~\n");
  return 0;
}