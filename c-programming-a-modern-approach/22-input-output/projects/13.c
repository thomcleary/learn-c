/*
Modify Programming Project 8 from Chapter 5 so that the program obtains departure
and arrival times from a file named `flights.dat`.
Each line of the file will contain a departure time followed by an arrival time,
with one or more spaces separating the two.
Times will be expressed using the 24-hour clock.
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
           departure_hours > 12 ? departure_hours % 12 : departure_hours, departure_mins, departure_hours > 11 ? 'p' : 'a',
           arrival_hours > 12 ? arrival_hours % 12 : arrival_hours, arrival_mins, arrival_hours > 11 ? 'p' : 'a');

    return 0;
}

struct flight find_closest_flight(int desired_time)
{
    FILE *fp = fopen("flights.dat", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Failed to open flights.dat\n");
        exit(EXIT_FAILURE);
    }

    size_t num_flights = 0;
    struct flight *flights = malloc(sizeof(*flights));
    if (flights == NULL)
    {
        fclose(fp);
        fprintf(stderr, "Failed to malloc flights\n");
        exit(EXIT_FAILURE);
    }

    int departure_hour, departure_min;
    int arrival_hour, arrival_min;
    char buffer[BUFSIZ];

    while (fgets(buffer, BUFSIZ, fp) != NULL)
    {
        if (sscanf(buffer, "%2d:%2d %2d:%2d", &departure_hour, &departure_min, &arrival_hour, &arrival_min) != 4)
        {
            fclose(fp);
            fprintf(stderr, "Failed to read flight %zu from flights.dat\n", num_flights + 1);
            exit(EXIT_FAILURE);
        }

        flights[num_flights++] = (struct flight){
            .departure_time = (departure_hour * 60) + departure_min,
            .arrival_time = (arrival_hour * 60) + arrival_min};

        if (realloc(flights, (sizeof(*flights) * num_flights) + sizeof(*flights)) == NULL)
        {
            fclose(fp);
            fprintf(stderr, "Failed to realloc flights to length %zu\n", num_flights);
            exit(EXIT_FAILURE);
        }
    }

    if (ferror(fp))
    {
        fclose(fp);
        fprintf(stderr, "Failed to read from flights.dat\n");
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    int f = 0;
    int closest_flight = f;
    int smallest_diff = abs(desired_time - flights[f].departure_time);
    f++;

    while (f < num_flights)
    {
        int diff = abs(desired_time - flights[f].departure_time);

        if (diff < smallest_diff)
        {
            closest_flight = f;
            smallest_diff = diff;
        }

        f++;
    }

    struct flight closest = flights[closest_flight];
    free(flights);

    return closest;
}