/*
Write a program that prints a one-month calendar.
The user specifies the number of days in the month and the day of the week on which the month begins
*/

#include <stdio.h>

int main(void)
{
    int days, start_day;

    printf("Enter number of days in month: ");
    scanf("%d", &days);

    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &start_day);

    for (int space = 1, day = 1; day <= days; space++)
    {
        if (space < start_day)
        {
            printf("   ");
            continue;
        }

        printf("%2d ", day);

        if (space % 7 == 0)
        {
            printf("\n");
        }

        day++;
    }

    printf("\n\n");

    return 0;
}