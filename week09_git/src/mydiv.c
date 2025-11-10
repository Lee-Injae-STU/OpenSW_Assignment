#include "myops.h"

double mydiv(double a, double b){
  if(b == 0){
    printf("Unable to divide by zero");
    return -999;
  }
  
  return a / b;
}