/*
Convert the below calls of atoi, atol and atoll into calls of strtol, strtol,
and strtoll, respectively
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *str = "37";

  printf("atoi(%s): %d\n", str, atoi(str));
  printf("strtol(%s): %ld\n\n", str, strtol(str, NULL, 10));

  printf("atol(%s): %ld\n", str, atol(str));
  printf("strtol(%s): %ld\n\n", str, strtol(str, NULL, 10));

  printf("atoll(%s): %lld\n", str, atoll(str));
  printf("strtoll(%s): %lld\n\n", str, strtoll(str, NULL, 10));

  return 0;
}
