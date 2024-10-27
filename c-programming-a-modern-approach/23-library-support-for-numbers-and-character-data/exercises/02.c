/*
Write the following function:

double evaluate_polynomial(double a[], int n, double x);

The function should return the value of the polynomial

(a sub n)(x^n) + (a sub (n-1))(x^(n-1)) + ... + (a sub 0)

where the (a sub i)'s are stored in  corresponding elements of the array a,
which has length n + 1.

Have the function use Horner's Rule to cpmpute the value of the polynomial.

Use the fma function to performa the multiplications and additions.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double evaluate_polynomial(double a[], int n, double x) {
  if (n < 0) {
    fprintf(stderr, "evaluate_polynomial: n must be >= 0\n");
    exit(EXIT_FAILURE);
  }

  if (n == 0) {
    return a[0];
  }

  double result = fma(a[n], x, a[n - 1]);
  n--;

  while (n > 0) {
    result = fma(result, x, a[n - 1]);
    n--;
  }

  return result;
}

int main(void) {
  double a[] = {1, 2, 3, 4};
  int n = sizeof(a) / sizeof(a[0]) - 1;
  double x = 2.5;

  // 4(2.5^3) + 3(2.5^2) + 2(2.5^1) + 1;
  // 62.5 + 18.75 + 5 + 1;
  // 87.25

  printf("%lf\n", evaluate_polynomial(a, n, x));

  return 0;
}
