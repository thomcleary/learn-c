/*
Write a program that copies a text file from standard input to standard output,
capitalizing the first letter in each word.
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
  bool in_space = true;
  int ch;

  while ((ch = getchar()) != EOF) {
    if (isspace(ch)) {
      in_space = true;
    } else if (in_space) {
      in_space = false;
      ch = toupper(ch);
    }

    putchar(ch);
  }

  return 0;
}
