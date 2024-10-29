/*
Write a program that counts the number of sentences in a text file (obtained
fron stdin).
Assume that each sentence ends with a ., ?, or ! followed by a white-space
character
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  unsigned int sentences = 0;
  int prev = getchar();
  int curr = prev;

  while ((curr = getchar()) != EOF) {
    if (strchr(".?!", prev) != NULL && isspace(curr)) {
      sentences++;
    }

    prev = curr;
  }

  printf("%d sentences\n", sentences);

  return 0;
}
