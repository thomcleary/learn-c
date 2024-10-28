/*
Use strtok to write the following function

int count_words(char *sentence);

count_words returns the number of words in the string sentence, where a "word"
is any sequence of non-whitespace characters.

count_words is allowed to modify the string.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_words(char *sentence) {
  if (sentence == NULL) {
    return 0;
  }

  const char *sep = " \t\n\v\f\r";

  if (strtok(sentence, sep) == NULL) {
    return 0;
  }

  int words = 1;
  while (strtok(NULL, sep) != NULL) {
    words++;
  }

  return words;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: ./13 sentence\n");
    exit(EXIT_FAILURE);
  }

  printf("%d\n", count_words(argv[1]));

  return 0;
}
