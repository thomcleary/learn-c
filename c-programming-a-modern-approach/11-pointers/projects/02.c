/*
Modify 05/08.c so that it includes the following function

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);
*/

#include <stdio.h>
#include <stdlib.h>

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

int main(void)
{
    int hours, minutes;

    printf("Enter a 24-hour time (hh:mm): ");
    scanf("%2d:%2d", &hours, &minutes);

    int minutes_since_midnight = (hours * 60) + minutes;

    int departure_time, arrival_time;

    find_closest_flight(minutes_since_midnight, &departure_time, &arrival_time);

    int departure_hours = departure_time / 60;
    int departure_mins = departure_time % 60;

    int arrival_hours = arrival_time / 60;
    int arrival_mins = arrival_time % 60;

    printf("Closes departure time is %d:%02d %c.m., arriving at %d:%02d %c.m.\n",
           departure_hours % 12, departure_mins, departure_hours > 11 ? 'p' : 'a',
           arrival_hours % 12, arrival_mins, arrival_hours > 11 ? 'p' : 'a');

    return 0;
}

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
    const int departures[] = {
        (8 * 60) + 0,
        (9 * 60) + 43,
        (11 * 60) + 19,
        (12 * 60) + 47,
        (14 * 60) + 0,
        (15 * 60) + 45,
        (19 * 60) + 0,
        (21 * 60) + 45};

    const int arrivals[] = {
        (10 * 60) + 18,
        (11 * 60) + 52,
        (13 * 60) + 31,
        (15 * 60) + 16,
        (16 * 60) + 8,
        (17 * 60) + 55,
        (21 * 60) + 20,
        (23 * 60) + 58};

    int flight = 0;
    int closest_flight = flight;
    int smallest_diff = abs(desired_time - departures[flight]);
    flight++;

    while (flight < (int)(sizeof(departures) / sizeof(departures[0])))
    {
        int diff = abs(desired_time - departures[flight]);

        if (diff < smallest_diff)
        {
            closest_flight = flight;
            smallest_diff = diff;
        }

        flight++;
    }

    *departure_time = departures[closest_flight];
    *arrival_time = arrivals[closest_flight];
}
