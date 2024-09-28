/*
Modify 05/09.c so that each date entered by the user is stored in a date structure (see exercises/05.c).
Incorporate the compare_dates function of exercises/05.c into your program.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdbool.h>

struct date
{
    int day, month, year;
};

static const int DAYS_IN_MONTH[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap_year(int year)
{
    if (year % 100 == 0)
    {
        return year % 400 == 0;
    }
    return year % 4 == 0;
}

int day_of_year(struct date d)
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

int compare_dates(struct date d1, struct date d2)
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
    struct date d1;
    struct date d2;

    printf("Enter fist date (mm/dd/yy): ");
    scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);

    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);

    switch (compare_dates(d1, d2))
    {
    case -1:
        printf("%d/%d/%d is earlier than %d/%d/%d\n", d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
        break;
    case 1:
        printf("%d/%d/%d is earlier than %d/%d/%d\n", d2.month, d2.day, d2.year, d1.month, d1.day, d1.year);
        break;
    default:
        printf("Dates are the same\n");
    }

    return 0;
}