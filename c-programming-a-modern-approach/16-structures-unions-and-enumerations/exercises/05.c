/*
Write the following functions, assuming that the date structure contains three members:
month, day, year (all of type int)

(a) int day_of_year(struct date d);
Returns the day of the year (an integer between 1 and 366) that corresponds to the date d

(b) int compare_dates(struct date d1, struct date d2);
Returns -1 if d1 is an earlier date than d2, +1 if d1 is a later date than d2 and 0 if d1 and d2 are the same
*/

#include <stdbool.h>
#include <stdio.h>

static const int DAYS_IN_MONTH[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef struct Date
{
    int month, day, year;
} Date;

bool is_leap_year(int year)
{
    if (year % 100 == 0)
    {
        return year % 400 == 0;
    }
    return year % 4 == 0;
}

int day_of_year(Date d)
{
    if (d.year < 0 || d.month < 1 || d.month > 12 || d.day < 1 || d.day > DAYS_IN_MONTH[d.month - 1])
    {
        return -1;
    }

    bool leap_year = is_leap_year(d.year);

    // Check February
    if (!leap_year && d.month == 2 && !(d.day < DAYS_IN_MONTH[1]))
    {
        return -1;
    }

    int days = 0;
    for (int month = 0; month < (d.month - 1); month++)
    {
        days += DAYS_IN_MONTH[month];
    }
    days += d.day;

    if (!leap_year && d.month > 2)
    {
        days--;
    }

    return days;
}

int compare_dates(Date d1, Date d2)
{
    if (d1.year != d2.year)
    {
        return d1.year < d2.year ? -1 : 1;
    }

    int d1_day_of_year = day_of_year(d1);
    int d2_day_of_year = day_of_year(d2);

    return d1_day_of_year < d2_day_of_year   ? -1
           : d1_day_of_year > d2_day_of_year ? 1
                                             : 0;
}

int main(void)
{
    Date d1 = {.month = 3, .day = 1, .year = 2001};
    Date d2 = {.month = 2, .day = 29, .year = 2024};
    Date d3 = {.month = 5, .day = 2, .year = 1997};

    printf("d1 (%02d/%02d/%04d): %d\n", d1.day, d1.month, d1.year, day_of_year(d1));
    printf("compare_dates(d1, d1): [%d]\n\n", compare_dates(d1, d1));

    printf("d2 (%02d/%02d/%04d): %d\n", d2.day, d2.month, d2.year, day_of_year(d2));
    printf("compare_dates(d1, d2): [%d]\n\n", compare_dates(d1, d2));

    printf("d3 (%02d/%02d/%04d): %d\n", d3.day, d3.month, d3.year, day_of_year(d3));
    printf("compare_dates(d2, d3): [%d]\n", compare_dates(d2, d3));

    return 0;
}