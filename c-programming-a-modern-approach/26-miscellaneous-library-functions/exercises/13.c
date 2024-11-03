/*
Section 26.3 described some of the ISO 8601 date and time formats. Here are a
few more:

(a) Year followed by day of year: YYYY-DDD, where DDD is a number between 001
and 366

(b) Year, week and day of week: YYYY-Www-D, where ww is a number between 01 and
53, and D is a digit between 1 through 7, beginning with Monday and ending with
Sunday.

(c) Combined date and time: YYYY-MM-DDThh:mm:ss

Give strftime strings that correspond to each of these formats
*/

#include <stdio.h>
#include <time.h>

int main(void) {
  const char a_format[] = "%Y-%j";
  const char b_format[] = "%Y-W%V-%u";
  const char c_format[] = "%Y-%m-%dT%H:%M:%S";

  char buf[BUFSIZ];
  time_t current_time = time(NULL);
  struct tm *local_tm = localtime(&current_time);

  strftime(buf, sizeof(buf), a_format, local_tm);
  printf("(a): %s\n", buf);

  strftime(buf, sizeof(buf), b_format, local_tm);
  printf("(b): %s\n", buf);

  strftime(buf, sizeof(buf), c_format, local_tm);
  printf("(c): %s\n", buf);

  return 0;
}
