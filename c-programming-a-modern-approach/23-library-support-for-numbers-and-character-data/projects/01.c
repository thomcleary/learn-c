/*
Write a program that finds the roots of the quadtric equation using the
quadratic formula

Have the program prompt for the values of a, b and c, then print both values of
x.

(If b^2-4ac is negative, the program should instead print a message to the
effect that the roots are complex).
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Roots {
  long double left, right;
};

struct Roots quadratic_roots(long double a, long double b, long double c) {
  long double discriminant = (b * b) - (4 * a * c);

  if (discriminant < 0) {
    fprintf(stderr, "Roots are complex\n");
    exit(EXIT_FAILURE);
  }

  return (struct Roots){.left = ((-b - sqrt(discriminant)) / (2 * a)),
                        .right = ((-b + sqrt(discriminant)) / (2 * a))};
}

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "usage: ./01 a b c\n");
    exit(EXIT_FAILURE);
  }

  long double a = strtold(argv[1], NULL);
  long double b = strtold(argv[2], NULL);
  long double c = strtold(argv[3], NULL);

  struct Roots roots = quadratic_roots(a, b, c);

  printf("roots: (%Lf, %Lf)\n", roots.left, roots.right);

  return 0;
}
