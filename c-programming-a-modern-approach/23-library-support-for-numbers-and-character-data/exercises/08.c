/*
Use strchr to write the following function

int numchar(const char *s, char ch);

numchar returns the number of times the character ch occurs in the string s
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numchar(const char *s, char ch) {
  if (s == NULL) {
    return 0;
  }

  int count = 0;
  while ((s = strchr(s, ch)) != NULL) {
    count++;
    s++;
  }

  return count;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "usage: ./08 str chr\n");
    exit(EXIT_FAILURE);
  }

  printf("%d\n", numchar(argv[1], *argv[2]));

  return 0;
}
