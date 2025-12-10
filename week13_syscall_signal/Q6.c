#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(){
  sigset_t block_set;
  sigemptyset(&block_set);
  sigaddset(&block_set, SIGINT);

  sigprocmask(SIG_BLOCK, &block_set, NULL);
  printf("SIGINT blocked. Sleeping for 5 seconds...\n");
  alarm(5);
  printf("Try Ctrl + C during sleep.\n");
  sleep(3);
  sigpending(&block_set);
  
  if(sigismember(&block_set, SIGINT) == 1){
    printf("\nSIGINT is pending\n");
  }
  else{
    printf("\nSIGINT is not pending\n");
  }
}