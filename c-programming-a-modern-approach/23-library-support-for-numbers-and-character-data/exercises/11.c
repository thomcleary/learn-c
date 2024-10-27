/*
Write a call of memset that replaces the last n characters in a null-terminated
string s with ! characters
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(x, y) ((x) > (y)) ? (x) : (y)
#define MIN(x, y) ((x) < (y)) ? (x) : (y)

char *str_replace_last_n(char *s, int n, char ch) {
  size_t s_len = strlen(s);
  n = MIN(s_len, MAX(n, 0));

  memset(s + (s_len - n), ch, n);
  return s;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "usage: ./11 str n\n");
    exit(EXIT_FAILURE);
  }

  printf("%s\n", str_replace_last_n(argv[1], strtol(argv[2], NULL, 10), '!'));

  return 0;
}
