/*
Many versions of <string.h> provide additional (nonstandard) functions, such as
those listed below. Write each function using only the features of the C
standard.

(a) strdup(s) - Returns a pointer to a copy of s stored in memory obtained by
calling malloc. Returns a null pointer if enough memory couldn't be allocated.

(b) stricmp(s1, s2) - Similar to strcmp, but ignores case of letters

(c) strlwr(s) - Converts upper-case letters in s to lower case, leaving other
characters unchanged; returns s

(d) strrev(s) - Reverses the characters in s (except the null character);
returns s

(e) strset(s, ch) - Fills s with copies of the character ch;
returns s.
*/

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strdup(const char *str) {
  if (str == NULL) {
    return NULL;
  }

  size_t str_len = strlen(str);

  char *dup = malloc(str_len + 1);
  if (dup == NULL) {
    return NULL;
  }

  return memcpy(dup, str, str_len + 1);
}

int my_stricmp(const char *str1, const char *str2) {
  if (str1 == NULL || str2 == NULL) {
    return (str1 == str2) ? 0 : (str1 == NULL ? -1 : 1);
  }

  while (*str1 && *str2) {
    int diff = tolower(*str1) - tolower(*str2);
    if (diff != 0) {
      return diff;
    }

    str1++;
    str2++;
  }

  return *str1 - *str2;
}

char *my_strlwr(char *str) {
  if (str == NULL) {
    return NULL;
  }

  char *str_p = str;
  while (*str_p) {
    *str_p = tolower(*str_p);
    str_p++;
  }

  return str;
}

char *my_strrev(char *str) {
  if (str == NULL) {
    return NULL;
  }

  size_t right = strlen(str) - 1;
  size_t left = 0;

  while (left < right) {
    char tmp = str[left];
    str[left] = str[right];
    str[right] = tmp;

    left++;
    right--;
  }

  return str;
}

char *my_strset(char *str, char ch) {
  if (str == NULL) {
    return NULL;
  }

  return memset(str, ch, strlen(str));
}

int main(void) {
  const char *deez_nuts = "deez nuts";

  char *dupe_deez_nuts = my_strdup(deez_nuts);
  assert(dupe_deez_nuts != NULL);
  assert(strcmp(dupe_deez_nuts, deez_nuts) == 0);
  printf("my_strdup passed\n");

  assert(my_stricmp(deez_nuts, "DeEz NuTs") == 0);
  assert(my_stricmp(dupe_deez_nuts, "dEeZ nUtS") == 0);
  assert(my_stricmp(deez_nuts, "NuTs DeEz") < 0);
  assert(my_stricmp(deez_nuts, "a") > 0);
  assert(my_stricmp(deez_nuts, "z") < 0);
  assert(my_stricmp(deez_nuts, "d") > 0);
  printf("my_stricmp passed\n");

  char deez_upper_nuts[] = "DEEZ NUTS";
  assert(strcmp(my_strlwr(deez_upper_nuts), deez_nuts) == 0);
  printf("my_strlwr passed\n");

  char deez_reversed_nuts[] = "DEEZ NUTS";
  assert(strcmp(my_strrev(deez_reversed_nuts), "STUN ZEED") == 0);
  assert(strcmp(my_strrev(deez_reversed_nuts), "DEEZ NUTS") == 0);
  printf("my_strrev passed\n");

  char deez_set_nuts[] = "deez nuts";
  assert(strcmp(my_strset(deez_set_nuts, '?'), "?????????") == 0);
  printf("my_strset passed\n");

  return 0;
}
