/*
Modify 05/08.c so that the times are stored in a single array.
The elements of the array will be structures,
each containing a departure time and the corresponding arrival time.
(Each time will be an integer, representing the number of minutes since midnight)
The program will use a loop to search the array for the departure time closest to the time entered by the user.
*/

#include <stdio.h>
#include <stdlib.h>

struct flight
{
    int departure_time, arrival_time;
};

struct flight find_closest_flight(int desired_time);

int main(void)
{
    int hours, minutes;

    printf("Enter a 24-hour time (hh:mm): ");
    scanf("%2d:%2d", &hours, &minutes);

    int minutes_since_midnight = (hours * 60) + minutes;

    struct flight closest_flight = find_closest_flight(minutes_since_midnight);

    int departure_hours = closest_flight.departure_time / 60;
    int departure_mins = closest_flight.departure_time % 60;

    int arrival_hours = closest_flight.arrival_time / 60;
    int arrival_mins = closest_flight.arrival_time % 60;

    printf("Closes departure time is %d:%02d %c.m., arriving at %d:%02d %c.m.\n",
           departure_hours % 12, departure_mins, departure_hours > 11 ? 'p' : 'a',
           arrival_hours % 12, arrival_mins, arrival_hours > 11 ? 'p' : 'a');

    return 0;
}

struct flight find_closest_flight(int desired_time)
{
    const struct flight flights[] = {
        {.departure_time = (8 * 60) + 0, .arrival_time = (10 * 60) + 18},
        {.departure_time = (9 * 60) + 43, .arrival_time = (11 * 60) + 52},
        {.departure_time = (11 * 60) + 19, .arrival_time = (13 * 60) + 31},
        {.departure_time = (12 * 60) + 47, .arrival_time = (15 * 60) + 16},
        {.departure_time = (14 * 60) + 0, .arrival_time = (16 * 60) + 8},
        {.departure_time = (15 * 60) + 45, .arrival_time = (17 * 60) + 55},
        {.departure_time = (19 * 60) + 0, .arrival_time = (21 * 60) + 20},
        {.departure_time = (21 * 60) + 45, .arrival_time = (23 * 60) + 58},
    };

    int f = 0;
    int closest_flight = f;
    int smallest_diff = abs(desired_time - flights[f].departure_time);
    f++;

    while (f < (int)(sizeof(flights) / sizeof(flights[0])))
    {
        int diff = abs(desired_time - flights[f].departure_time);

        if (diff < smallest_diff)
        {
            closest_flight = f;
            smallest_diff = diff;
        }

        f++;
    }

    return flights[closest_flight];
}