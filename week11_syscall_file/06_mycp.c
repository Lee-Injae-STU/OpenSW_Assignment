#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 32

int main(int argc, char *argv[]){
  if(argc < 3){
    printf("Usage : %s [source file] [destination file1] [destination file2] ... \n", argv[0]);
    return -1;
  }

  int src_fd = open(argv[1], O_RDONLY);

  if(src_fd == -1){
    perror(argv[1]);
    return -2;
  }

  int num_files = argc - 2;
  int* dest_fd = (int *)malloc(sizeof(int) * num_files);
  for(int i = 0; i < num_files; i++){
    dest_fd[i] = open(argv[i + 2], O_WRONLY | O_CREAT, 0644);
  }
  
  char* readStr = (char*)malloc(sizeof(char) * BUF_SIZE);
  int read_result;
  while(1){
    read_result = read(src_fd, readStr, BUF_SIZE);

    if(read_result == 0){
      printf("\nprogram end ... \n");
      break;
    }

    write(1, readStr, read_result);

    for(int i = 0; i < num_files; i++){
      write(dest_fd[i], readStr, read_result);
    }
  }

  free(dest_fd);
  free(readStr);
  return 0;
}