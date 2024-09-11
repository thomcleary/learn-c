/*
Modify 05/08.c so that the user enters a time using the 12-hour clock
The input will have the form hours:minutes
followed by either A, P, AM or PM (either lower or upper case)
White space is allowed (but not required) between the numerical time and the AM/PM indicator

Examples of valid input:
1:15P
1:15PM
1:15p
1:15pm
1:15 P
1:15 PM
1:15 p
1:15 pm
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int hours, minutes;
    char am_pm;

    printf("Enter a 12-hour time (hh:mm am/pm): ");
    scanf("%2d:%2d %c", &hours, &minutes, &am_pm);

    if (toupper(am_pm) == 'P')
    {
        hours += 12;
    }

    int minutes_since_midnight = (hours * 60) + minutes;

    int flight1_departure_diff = abs(minutes_since_midnight - ((8 * 60) + 0));
    int flight2_departure_diff = abs(minutes_since_midnight - ((9 * 60) + 43));
    int flight3_departure_diff = abs(minutes_since_midnight - ((11 * 60) + 19));
    int flight4_departure_diff = abs(minutes_since_midnight - ((12 * 60) + 47));
    int flight5_departure_diff = abs(minutes_since_midnight - ((14 * 60) + 0));
    int flight6_departure_diff = abs(minutes_since_midnight - ((15 * 60) + 45));
    int flight7_departure_diff = abs(minutes_since_midnight - ((19 * 60) + 0));
    int flight8_departure_diff = abs(minutes_since_midnight - ((21 * 60) + 45));

    int flight = 1;
    int smallest_diff = flight1_departure_diff;

    if (flight2_departure_diff < smallest_diff)
    {
        flight = 2;
        smallest_diff = flight2_departure_diff;
    }

    if (flight3_departure_diff < smallest_diff)
    {
        flight = 3;
        smallest_diff = flight3_departure_diff;
    }

    if (flight4_departure_diff < smallest_diff)
    {
        flight = 4;
        smallest_diff = flight4_departure_diff;
    }

    if (flight5_departure_diff < smallest_diff)
    {
        flight = 5;
        smallest_diff = flight5_departure_diff;
    }

    if (flight6_departure_diff < smallest_diff)
    {
        flight = 6;
        smallest_diff = flight6_departure_diff;
    }

    if (flight7_departure_diff < smallest_diff)
    {
        flight = 7;
        smallest_diff = flight7_departure_diff;
    }

    if (flight8_departure_diff < smallest_diff)
    {
        flight = 8;
        smallest_diff = flight8_departure_diff;
    }

    printf("Closest departure time is ");

    switch (flight)
    {
    case 1:
        printf("8:00 a.m., arriving at 10:16 a.m.\n");
        break;
    case 2:
        printf("9:43 a.m., arriving at 11:52 a.m.\n");
        break;
    case 3:
        printf("11:19 a.m., arriving at 1:31 p.m.\n");
        break;
    case 4:
        printf("12:47 p.m., arriving at 3:16 p.m.\n");
        break;
    case 5:
        printf("2:00 p.m., arriving at 4:08 p.m.\n");
        break;
    case 6:
        printf("3:45 p.m., arriving at 5:55 p.m.\n");
        break;
    case 7:
        printf("7:00 p.m., arriving at 9:20 p.m.\n");
        break;
    case 8:
        printf("9:45 p.m., arriving at 11:58 p.m.\n");
        break;
    }

    return 0;
}