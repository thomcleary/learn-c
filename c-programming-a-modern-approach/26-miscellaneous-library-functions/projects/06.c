/*
Write programs that display the current date and time in each of the following
formats.

Use strftime to do all or most of the formatting.

(a) Sunday, June 3, 2007 05:48p
(b) Sun, 3 Jun 07 17:48
(c) 06/03/07 5:48:34 PM
*/

#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void) {
  time_t current_time = time(NULL);
  struct tm *current_local_time = localtime(&current_time);

  char date_str[BUFSIZ];
  char buf[BUFSIZ];

  // (a)
  strftime(date_str, sizeof(date_str), "%A, %B ", current_local_time);

  // No conversion specifier to have the day take up less than 2 spaces when it
  // is one digit %d - Day of month (01-31)
  // %e - Day of month (1-31): a single digit is preceded by a space
  snprintf(buf, sizeof(buf), "%d, ", current_local_time->tm_mday + 1);
  strcat(date_str, buf);

  strftime(buf, sizeof(buf), "%Y %I:%M", current_local_time);
  strcat(date_str, buf);

  // No conversion specifier for just 'p' or 'a'
  // %p - AM/PM designator (AM or PM)
  strcat(date_str, current_local_time->tm_hour > 11 ? "p" : "a");

  printf("(a): %s\n", date_str);

  // (b)
  // (I don't care about the day having a leading zero for single digits)
  strftime(date_str, sizeof(date_str), "%a, %d %b %y %R", current_local_time);
  printf("(b): %s\n", date_str);

  // (c)
  strftime(date_str, sizeof(date_str), "%x %r", current_local_time);
  printf("(c): %s\n", date_str);

  return 0;
}
