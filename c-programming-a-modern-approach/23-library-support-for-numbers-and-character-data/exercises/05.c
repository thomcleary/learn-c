/*
Using isxdigit, write a function that checks whether a string represents a valid
hexadecimal number (it consists solely of hexadecimal digits).

If so, the function returns the value of the number as a long int. Otherwise,
the function returns -1.
*/

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int hexstr_to_long(char *str) {
  for (char *str_p = str; *str_p; str_p++) {
    if (!isxdigit(*str_p)) {
      return -1;
    }
  }

  long int value;
  sscanf(str, "%lx", &value);
  return value;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: ./05 hexnum\n");
    exit(EXIT_FAILURE);
  }

  long int hexnum = hexstr_to_long(argv[1]);

  if (hexnum == -1) {
    fprintf(stderr, "Invalid hexstring\n");
    exit(EXIT_FAILURE);
  }

  printf("%ld\n", hexnum);

  return 0;
}
