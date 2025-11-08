#include "advanced_ops.h"

double Mod(double a, double b){
  if(b == 0){
    printf("division by zero");
    return -999;
  }

  return (double)((int)a % (int)b);
}