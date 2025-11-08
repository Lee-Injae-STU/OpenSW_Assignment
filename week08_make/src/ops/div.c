#include <stdio.h>
#include "basic_ops.h"

double div(double a, double b){
  if(b == 0){
    printf("division by zero");
    return -999;
  }

  return a / b;
}