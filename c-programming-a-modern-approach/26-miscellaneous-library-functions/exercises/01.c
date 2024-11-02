/*
Rewrite the max_int function so that, instead of passing the number of integers
as the first argument, we must supply 0 as the last argument.

Hint: max_int must have at least one "normal" parameter, so you can't remove the
parameter n. Instead assume that it represents one of the numbers to be
compared.
*/

#include <stdarg.h>
#include <stdio.h>

int max_int_original(int n, ...) {
  va_list ap;
  int i, current, largest;

  va_start(ap, n);
  largest = va_arg(ap, int);

  for (i = 1; i < n; i++) {
    current = va_arg(ap, int);
    if (current > largest) {
      largest = current;
    }
  }

  va_end(ap);
  return largest;
}

int max_int(int n, ...) {
  va_list ap;

  va_start(ap, n);
  int largest = n;
  int current = largest;

  while ((current = va_arg(ap, int)) != 0) {
    if (current > largest) {
      largest = current;
    }
  }

  va_end(ap);
  return largest;
}

int main(void) {
  int n = 5;
  int a = 1;
  int b = 2;
  int c = 37;
  int d = 4;
  int e = 5;

  printf("max_int_original: %d\n", max_int_original(n, a, b, c, d, e));
  printf("max_int: %d\n", max_int(a, b, c, d, e, a, b, c, d, e, 0));

  return 0;
}
