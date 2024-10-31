/*
Write a program that tests whether your compiler's "" (native) locale is the
same as it's "C" locale
*/

#include <assert.h>
#include <locale.h>
#include <stdio.h>

int main(void) {

  setlocale(LC_ALL, "C");
  struct lconv *lconv = localeconv();
  char c_thousands_sep = *lconv->thousands_sep;

  setlocale(LC_ALL, "");
  lconv = localeconv();
  char default_thousands_sep = *lconv->thousands_sep;

  printf("locale \"C\"\n");
  printf("thousands_sep: '%c'\n\n", c_thousands_sep);

  printf("locale \"\"\n");
  printf("thousands_sep: '%c'\n", default_thousands_sep);

  assert(c_thousands_sep != default_thousands_sep);

  return 0;
}
