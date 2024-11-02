/*
Extend the function of Exercise 2 so that it allows two conversion
specifications: %d and %s. Each %d in the format string indicates an int
argument, and each %s indicates a char * (string argument)
*/

#include <assert.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int isprintf(char *format, ...) {
  va_list ap;

  va_start(ap, format);

  int chars_printed = 0;

  while (*format) {
    if (*format == '%') {
      format++;
      if (*format == 'd') {
        int i = va_arg(ap, int);

        if (i < 0) {
          i *= -1;
          putchar('-');
          chars_printed++;
        }

        int num_digits = (int)log10(i) + 1;
        while (num_digits > 0) {
          int magnitude = (int)pow(10, num_digits - 1);
          int most_significant_digit = i / magnitude;

          putchar('0' + most_significant_digit);
          chars_printed++;

          i -= magnitude * most_significant_digit;
          num_digits--;
        }
      } else if (*format == 's') {
        char *str = va_arg(ap, char *);

        while (*str) {
          putchar(*str++);
          chars_printed++;
        }
      }
    } else {
      putchar(*format);
      chars_printed++;
    }
    format++;
  }

  va_end(ap);
  return chars_printed;
}

int main(void) {
  char *line = "This string was printed by isprintf without any conversion "
               "specifiers.\n";
  int chars_printed = isprintf(line);
  assert(chars_printed == strlen(line));

  line = "This %d line has %d integers formatted via isprintf %d.\n";
  int expected_chars_printed = (strlen(line) - (2 * 3) + 3 + 1 + 3);
  chars_printed = isprintf(line, 100, 3, -37);
  assert(chars_printed == expected_chars_printed);

  line = "This line will require an integer at the end, but will not provide "
         "one... %d. (undefined behaviour)\n";
  chars_printed = isprintf(line);

  line = "This line has %d [%s]'s formatted via isprintf: [%s].\n";
  char *first = "string";
  char *second = "deez nuts";
  expected_chars_printed =
      (strlen(line) - (2 * 3) + 1 + strlen(first) + strlen(second));
  chars_printed = isprintf(line, 2, first, second);
  assert(chars_printed == expected_chars_printed);

  return 0;
}
