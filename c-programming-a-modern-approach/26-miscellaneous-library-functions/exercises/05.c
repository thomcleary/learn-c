/*
Write the following function

char *vstrcat(const char *first, ...);

All arguments of vstrcat are assumed to be strings, except for the last
argument, which must be a null pointer (cast to char * type). The function
returns a pointer to a dynamically allocated string containing the concatenation
of the arguments. vstrcat should return a null pointer if not enough memory is
available.

Hint: Have vstrcat go through the arguments twice: once to determine the amount
of memory required for the returned string and once to copy the arguments into
the string.
*/

#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *vstrcat(const char *first, ...) {
  if (first == NULL) {
    return NULL;
  }

  va_list ap;
  va_start(ap, first);

  size_t catstr_size = strlen(first);
  char *str;
  while ((str = va_arg(ap, char *)) != NULL) {
    catstr_size += strlen(str);
  }

  va_end(ap);

  char *catstr = malloc(catstr_size + 1);
  if (catstr == NULL) {
    return NULL;
  }
  strcpy(catstr, first);

  va_start(ap, first);

  while ((str = va_arg(ap, char *)) != NULL) {
    strcat(catstr, str);
  }

  return catstr;
}

int main(void) {
  char *result = vstrcat("Special ", "Agent ", "Dale ", "Cooper", NULL);
  assert(result != NULL);

  printf("%s\n", result);

  free(result);
  return 0;
}
