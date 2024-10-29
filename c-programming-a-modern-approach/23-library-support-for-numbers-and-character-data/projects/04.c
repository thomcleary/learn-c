/*
Write a program that prompts the user to enter a series of words separated by
single spaces, then prints the words in reverse order. Read the input as a
string, and then use strtok to break it into words
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  printf("Enter words separated by a single space: ");

  char line[BUFSIZ];
  if (fgets(line, sizeof(line), stdin) == NULL) {
    fprintf(stderr, "Failed to read words\n");
    exit(EXIT_FAILURE);
  }
  line[strcspn(line, "\n")] = '\0';

  char *words[BUFSIZ];
  size_t word_count = 0;

  if ((words[word_count++] = strtok(line, " ")) == NULL) {
    fprintf(stderr, "Failed to read first words in line [%s]\n", line);
    exit(EXIT_FAILURE);
  }

  char *word;
  while (word_count < BUFSIZ && (word = strtok(NULL, " ")) != NULL) {
    words[word_count++] = word;
  }

  for (int i = word_count - 1; i >= 0; i--) {
    printf("%s ", words[i]);
  }
  printf("\n");

  return 0;
}
