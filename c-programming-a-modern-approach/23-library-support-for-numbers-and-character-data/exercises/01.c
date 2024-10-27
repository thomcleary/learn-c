/*
Extend the round_nearest function so that it rounds a floating-point number x
to n digits after the decimal point.

For example, the call round_nearest(3.1459, 3) would return 3.142.

Hint: Multiply x by 10^n, round to the nearest integer,
then divide by 10^n.

Be sure that your function works correctly for both positive and negative values
of x
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double round_nearest(double x) {
  return x < 0.0 ? ceil(x - 0.5) : floor(x + 0.5);
}

double round_nearest_extended(double x, int precision) {
  unsigned int factor = pow(10, precision);
  return round_nearest(x * factor) / factor;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "usage: ./01 float precision\n");
    exit(EXIT_FAILURE);
  }

  float num = strtof(argv[1], NULL);
  int precision = strtol(argv[2], NULL, 10);

  printf("round_nearest(%f): %lf\n", num, round_nearest(num));
  printf("round_nearest_extended(%f, %d): %lf\n", num, precision,
         round_nearest_extended(num, precision));

  return 0;
}
