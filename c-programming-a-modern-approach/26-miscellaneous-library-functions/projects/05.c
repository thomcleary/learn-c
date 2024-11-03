/*
Write a program that prompts the user to enter two dates, then prints the
difference between them, measured in days.

Hint: Use the mktime and difftime functions.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SECONDS_IN_DAY (60 * 60 * 24)

struct tm date_to_tm(unsigned int day, unsigned int month, unsigned int year) {
  return (struct tm){.tm_year = year - 1900,
                     .tm_mon = month - 1,
                     .tm_mday = day,
                     .tm_hour = 0,
                     .tm_min = 0,
                     .tm_sec = 0,
                     .tm_isdst = -1};
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "usage: ./05 dd/mm/yyyy dd/mm/yyyy\n");
    exit(EXIT_FAILURE);
  }

  unsigned int day, month, year;
  sscanf(argv[1], " %d/%d/%d", &day, &month, &year);

  struct tm date = date_to_tm(day, month, year);
  time_t first_time = mktime(&date);

  sscanf(argv[2], " %d/%d/%d", &day, &month, &year);
  date = date_to_tm(day, month, year);

  double time_diff = difftime(first_time, mktime(&date));

  printf("Time difference (seconds): %lf\n", time_diff);
  printf("Time difference (days): %lf\n", time_diff / SECONDS_IN_DAY);

  return 0;
}
