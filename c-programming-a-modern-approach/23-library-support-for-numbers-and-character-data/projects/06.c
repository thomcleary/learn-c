/*
Write a program that copies a text file from standard input to standard output,
replacing each control character (other than \n) by a question mark.
*/

#include <ctype.h>
#include <stdio.h>

int main(int argc, char **argv) {

  int ch;
  while ((ch = getchar()) != EOF) {
    putchar(iscntrl(ch) && ch != '\n' ? '?' : ch);
  }

  return 0;
}
