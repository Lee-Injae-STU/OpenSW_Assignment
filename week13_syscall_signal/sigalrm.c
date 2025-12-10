#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

struct two_double{
  double a;
  double b;
} data;

void sigalarm_handler(int sig){
  printf("%f, %f\n", data.a, data.b);
  alarm(1);
}

int main(){
  struct two_double zeros={0.0, 0.0};
  struct two_double ones = {1.0, 1.0};

  struct sigaction sa_alarm;
  sa_alarm.sa_flags = 0;
  sigemptyset(&sa_alarm.sa_mask);
  sa_alarm.sa_handler = sigalarm_handler;

  if(sigaction(SIGALRM, &sa_alarm, NULL) == -1){
    perror("sigaction error: ");
    exit(0);
  }

  sigset_t block_set, prev_set;
  sigemptyset(&block_set);
  sigaddset(&block_set, SIGALRM);

  alarm(1);

  while(1){
    sigprocmask(SIG_BLOCK, &block_set, NULL);
    data = ones;
    sigprocmask(SIG_UNBLOCK, &block_set, NULL);

    sigprocmask(SIG_BLOCK, &block_set, NULL);
    data = zeros;
    sigprocmask(SIG_UNBLOCK, &block_set, NULL);
  } 
}