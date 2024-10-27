/*
Section 23.6 explains how to casll strchr repeatedly to locate all occurences of
a character within a string. Is it possible to locate all occurences in reverse
order by calling strrch repeatedley?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "usage: ./07 str ch\n");
    exit(EXIT_FAILURE);
  }

  char *str = argv[1];
  char ch = *argv[2];

  char *located;
  while ((located = strrchr(str, ch)) != NULL) {
    printf("located: [%s]\n", located);
    *located = '\0';
  }

  return 0;
}
