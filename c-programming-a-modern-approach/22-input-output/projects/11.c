/*
Write a program that reads a data from the command line and displays it in the following form:

September 13, 2010

Allow the user to enter the date as either 9-13-2010 or 9/13/2010;
you may assume that there are no spaces in the date.
Print an error message if the date doesn't have one of the specified forms.

Hint: Use sscanf to extract the month, day and year from the command line argument
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static const char *month_names[12] = {"January", "February", "March", "April",
                                      "May", "June", "July", "August",
                                      "September", "October", "November", "December"};

void usage()
{
    fprintf(stderr, "usage: ./11 DATE\n\n");
    fprintf(stderr, "where:\n  DATE - dd-mm-yyyy | dd/mm/yyyy\n");
    exit(EXIT_FAILURE);
}

void validate_year(int year)
{
    if (year < 0)
    {
        fprintf(stderr, "Invalid year\n");
        exit(EXIT_FAILURE);
    }
}

const char *get_month_name(int month)
{
    if (month < 1 || month > 12)
    {
        fprintf(stderr, "Invalid month\n");
        exit(EXIT_FAILURE);
    }

    return month_names[month - 1];
}

bool is_leap_year(int year)
{
    if (year % 100 == 0)
    {
        return year % 400 == 0;
    }
    return year % 4 == 0;
}

void validate_day(int day, int month, int year)
{
    bool valid_day = true;

    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        valid_day = day <= 31;
        break;
    case 2:
        valid_day = day <= (is_leap_year(year) ? 29 : 28);
        break;
    default:
        valid_day = day <= 30;
    }

    if (day < 1)
    {
        valid_day = false;
    }

    if (!valid_day)
    {
        fprintf(stderr, "Invalid day\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        usage();
    }

    char *date = argv[1];
    int day, month, year;

    if (sscanf(date, "%2d-%2d-%d", &day, &month, &year) != 3)
    {
        if (sscanf(date, "%2d/%2d/%d", &day, &month, &year) != 3)
        {
            usage();
        }
    }

    validate_year(year);
    const char *month_name = get_month_name(month);
    validate_day(day, month, year);

    printf("%s %02d, %d\n", month_name, day, year);

    return 0;
}