#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[]){
  if(argc < 2){
    printf("Usage: %s [file name]...\n", argv[0]);
    exit(0);
  }

  int* fd = (int*)malloc(sizeof(int) * (argc - 1));

  for(int i = 1; i < argc; i++){
    fd[i - 1] = open(argv[i], O_RDONLY);
    
    if(fd[i - 1] == -1){
      perror(argv[i]);
    }
    else{
      printf("Success to open a file : %s\n", argv[i]);
    }
  }

  for(int i = 0; i < argc - 1; i++){
    int cd;

    if(fd[i] != -1){
      cd = close(fd[i]);
      printf("Closed successfully %s\n", argv[i + 1]);
    }
    
    if(cd == -1){
      perror(argv[i + 1]);
    }
  }
  
  free(fd);
  return 0;
}
