/*
Write a program that obtains the name of a locale, for example "fi_FI"
(Finland), from the command line and then displays the values stored in the
corresponding lconv structure.

For readability the characters in grouping and mon_grouping should be displayed
as decimal numbers
*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: ./02 locale\n");
    exit(EXIT_FAILURE);
  }

  char *locale = argv[1];
  if (setlocale(LC_ALL, locale) == NULL) {
    fprintf(stderr, "Invalid locale\n");
    exit(EXIT_FAILURE);
  }

  struct lconv *lconv = localeconv();

  printf("decimal_point = '%s'\n", lconv->decimal_point);
  printf("thousands_sep = '%s'\n", lconv->thousands_sep);
  printf("grouping = '%s'\n", lconv->grouping);
  printf("int_curr_symbol = '%s'\n", lconv->int_curr_symbol);
  printf("currency_symbol = '%s'\n", lconv->currency_symbol);
  printf("mon_decimal_point = '%s'\n", lconv->mon_decimal_point);
  printf("mon_thousands_sep = '%s'\n", lconv->mon_thousands_sep);
  printf("mon_grouping = '%d'\n", *lconv->mon_grouping);
  printf("positive_sign = '%s'\n", lconv->positive_sign);
  printf("negative_sign = '%s'\n", lconv->negative_sign);
  printf("int_frac_digits = '%c'\n", lconv->int_frac_digits);
  printf("frac_digits = '%c'\n", lconv->frac_digits);
  printf("p_cs_precedes = '%c'\n", lconv->p_cs_precedes);
  printf("p_sep_by_space = '%c'\n", lconv->p_sep_by_space);
  printf("n_cs_precedes = '%c'\n", lconv->n_cs_precedes);
  printf("n_sep_by_space = '%c'\n", lconv->n_sep_by_space);
  printf("p_sign_posn = '%c'\n", lconv->p_sign_posn);
  printf("n_sign_posn = '%c'\n", lconv->n_sign_posn);
  printf("int_p_cs_precedes = '%c'\n", lconv->int_p_cs_precedes);
  printf("int_p_sep_by_space = '%c'\n", lconv->int_p_sep_by_space);
  printf("int_n_cs_precedes = '%c'\n", lconv->int_n_cs_precedes);
  printf("int_n_sep_by_space = '%c'\n", lconv->int_n_sep_by_space);
  printf("int_p_sign_posn = '%c'\n", lconv->int_p_sign_posn);
  printf("int_n_sign_posn = '%c'\n", lconv->int_n_sign_posn);

  return 0;
}
