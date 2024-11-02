/*
Write a statement that randomly assigns one of the numbers 7, 11, 15 or 19 to
the variable n.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL));
  int n = 7 + (4 * (rand() % 4));

  printf("%d\n", n);

  return 0;
}
