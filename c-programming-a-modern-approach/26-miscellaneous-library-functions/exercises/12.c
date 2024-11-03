/*
Write a function that, when passed a year, returns a time_t value representing
12:00am on the first day of that year
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

time_t get_year_start(long int year) {
  return mktime(&(struct tm){.tm_year = year - 1900,
                             .tm_mon = 0,
                             .tm_mday = 1,
                             .tm_sec = 0,
                             .tm_min = 0,
                             .tm_hour = 0,
                             .tm_isdst = -1});
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: ./12 year\n");
    exit(EXIT_FAILURE);
  }

  errno = 0;
  long int year = strtol(argv[1], NULL, 10);
  if (errno != 0) {
    perror("Invalid year");
    exit(EXIT_FAILURE);
  }

  time_t year_start = get_year_start(year);
  if (year_start == -1) {
    fprintf(stderr, "Date not representable\n");
    exit(EXIT_FAILURE);
  }

  printf("%s", ctime(&year_start));

  return 0;
}
