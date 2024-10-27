/*
Using isalpha and isalnum, write a function that checks whether a string has the
syntax of a C identifier.
(it consists of letters, digits, and underscores, with a letter or underscore at
the beginning)
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool is_identifier(char *identifier) {
  if (!(isalpha(*identifier) || *identifier == '_')) {
    return false;
  }

  identifier = identifier + 1;
  while (*identifier) {
    if (!(isalnum(*identifier) || *identifier == '_')) {
      return false;
    }

    identifier++;
  }

  return true;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: ./04 identifier\n");
    exit(EXIT_FAILURE);
  }

  char *identifier = argv[1];

  if (is_identifier(identifier)) {
    printf("Valid identifier\n");
  } else {
    printf("Invalid identifier\n");
  }

  return 0;
}
