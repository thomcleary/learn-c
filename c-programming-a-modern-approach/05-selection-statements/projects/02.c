/*
Write a program that assk the user for a 24 hour time
then displays the time in 12 hour form
*/

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int hour, minutes;

    printf("Enter a 24-hour time (hh:mm): ");
    scanf("%2d:%2d", &hour, &minutes);

    bool is_pm = hour > 11;

    if (hour == 0)
    {
        hour += 12;
    }
    else if (is_pm && hour != 12)
    {
        hour -= 12;
    }

    printf("Equivalent 12-hour time: %d:%02d %s\n", hour, minutes, is_pm ? "PM" : "AM");

    return 0;
}