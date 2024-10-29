/*
Write a program that copies a text file from standard input to standard output,
removing all whitespace characters from the beginning of each line.

A lint consisting entirely of whitespace characters will not be copied.
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
  bool trim = true;
  char ch;

  while ((ch = getchar()) != EOF) {
    if (trim && !isspace(ch)) {
      trim = false;
    } else if (!trim && ch == '\n') {
      trim = true;
      putchar(ch);
    }

    if (!trim) {
      putchar(ch);
    }
  }

  return 0;
}
