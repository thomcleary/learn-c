/*
Write a function that returns a random double value d in the range 0.0 <= d
< 1.0
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double drand() { return (double)RAND_MAX / ((long)RAND_MAX + 1); }

int main(void) {
  sranddev();

  printf("%.10lf\n", drand());

  return 0;
}
