/*
Write a program that prompts the user for a date (month, day, and year) and an
integer n, then prints the date that's n days later
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
  if (argc != 5) {
    fprintf(stderr, "usage: ./04 n day month year\n");
    exit(EXIT_FAILURE);
  }

  errno = 0;
  long int n = strtol(argv[1], NULL, 10);
  if (errno != 0) {
    perror("Failed to read n");
    exit(EXIT_FAILURE);
  }

  errno = 0;
  long int day = strtol(argv[2], NULL, 10);
  if (errno != 0) {
    perror("Failed to read day");
    exit(EXIT_FAILURE);
  }

  errno = 0;
  long int month = strtol(argv[3], NULL, 10);
  if (errno != 0) {
    perror("Failed to read month");
    exit(EXIT_FAILURE);
  }

  errno = 0;
  long int year = strtol(argv[4], NULL, 10);
  if (errno != 0) {
    perror("Failed to read year");
    exit(EXIT_FAILURE);
  }

  struct tm date = {.tm_year = year - 1900,
                    .tm_mon = month - 1,
                    .tm_mday = day,
                    .tm_hour = 0,
                    .tm_min = 0,
                    .tm_sec = 0,
                    .tm_isdst = -1};

  date.tm_mday += n;
  mktime(&date);

  printf("%s\n", asctime(&date));

  return 0;
}
