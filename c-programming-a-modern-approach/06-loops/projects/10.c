/*
Generalize 05/09.c so that the user may enter any number of dates
The user will enter 0/0/0 to indicate that no more dates will be entered
*/

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int month, day, year;
    int earliest_month, earliest_day, earliest_year;

    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    earliest_month = month;
    earliest_day = day;
    earliest_year = year;

    while (month != 0 && day != 0 && year != 0)
    {
        bool is_new_date_earlier = (year < earliest_year) ||
                                   (year == earliest_year && (month < earliest_month ||
                                                              (month == earliest_month && day < earliest_day)));

        if (is_new_date_earlier)
        {
            earliest_month = month;
            earliest_day = day;
            earliest_year = year;
        }

        printf("Enter a date (mm/dd/yy): ");
        scanf("%d/%d/%d", &month, &day, &year);
    }

    printf("%02d/%02d/%02d is the earliest date\n", earliest_month, earliest_day, earliest_year);

    return 0;
}