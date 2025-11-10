#include "myops.h"

double mymod(double a, double b){
  if(b == 0){
    printf("Unable to divide by zero\n");
    return -999;
  }

  return (double)((int)a % (int)b);
}