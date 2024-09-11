/*
Write a program that asks the user for a 12-hour time,
then displays the time in 24-hour form
See 08.c for a description of the input format
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int hours, minutes;
    char am_pm;

    printf("Enter a 12-hour time: ");
    scanf("%2d:%2d %c", &hours, &minutes, &am_pm);

    if (toupper(am_pm) == 'P')
    {
        hours += 12;
    }

    printf("Equivalent 24-hour time: %d:%d\n", hours, minutes);

    return 0;
}