/*
Write the following function:

char *max_pair(int num_pairs, ...);

The arguments of max_pair are assumed to be "pairs" of integers and strings;
the value of num_pairs indicates how many pairs will follow.
(A pair consists of an int argument followed by a char * argument).

The function searches the integers to find the largest one;
it the returns the string argument that follows it.
*/

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

char *max_pair(int num_pairs, ...) {
  if (num_pairs < 1) {
    return NULL;
  }

  va_list ap;
  va_start(ap, num_pairs);

  int max_int = va_arg(ap, int);
  char *max_str = va_arg(ap, char *);

  for (int i = 1; i < num_pairs; i++) {
    int curr_int = va_arg(ap, int);
    char *curr_str = va_arg(ap, char *);

    if (curr_int > max_int) {
      max_int = curr_int;
      max_str = curr_str;
    }
  }

  va_end(ap);
  return max_str;
}

int main(void) {
  char *max_str =
      max_pair(5, 180, "Seinfeld", 180, "I Love Lucy", 39, "The Honeymooners",
               210, "All in the Family", 86, "The Sopranos");

  printf("%s\n", max_str);
}
