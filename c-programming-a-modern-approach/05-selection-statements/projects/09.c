/*
Write a program that prompts the user to enter two dates
and then indicates which date comes earlier on the calendar
*/

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int month1, day1, year1;
    int month2, day2, year2;

    printf("Enter fist date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month1, &day1, &year1);

    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month2, &day2, &year2);

    bool is_first_earlier = (year1 < year2) ||
                            (year1 == year2 && (month1 < month2 ||
                                                (month1 == month2 && day1 < day2)));

    if (is_first_earlier)
    {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", month1, day1, year1, month2, day2, year2);
    }
    else
    {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", month2, day2, year2, month1, day1, year1);
    }

    return 0;
}