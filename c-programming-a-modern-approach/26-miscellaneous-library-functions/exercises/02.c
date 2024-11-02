/*
Write a simplified version of printf in which the only conversion specifier is
%d, and all arguments after the first are assumed to be int type.

If the function encounters a % character that's not immediately followed by a d
character, it should ignore both characters.

The function should use calls of putchar to produce all output. You may assume
that the format string doesn't contain escape sequences.
*/

#include <assert.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int iprintf(char *format, ...) {
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
  char *line = "This string was printed by isprintf.\n";
  int chars_printed = iprintf(line);
  assert(chars_printed == strlen(line));

  line = "This %d line has %d integers formatted via isprintf %d.\n";
  int expected_chars_printed = (strlen(line) - (2 * 3) + 3 + 1 + 3);
  chars_printed = iprintf(line, 100, 3, -37);
  assert(chars_printed == expected_chars_printed);

  line = "This line will require an integer at the end, but will not provide "
         "one... %d. (undefined behaviour)\n";
  chars_printed = iprintf(line);

  return 0;
}
