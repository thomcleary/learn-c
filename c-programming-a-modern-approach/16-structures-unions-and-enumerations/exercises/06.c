/*
Write the following function, assuming that the time structure contains three members:
hours, minutes and seconds (all of type int)

struct time split_time(long total_seconds);

total_seconds is a time represented as the number of seconds since midnight.
The function returns a structure containing the equivalent time in hours (0-23), minutes (0-59), and seconds (0-59)
*/

#include <stdio.h>
#include <time.h>

struct time
{
    int hours, minutes, seconds;
};

struct time split_time(long total_seconds)
{
    int hours = total_seconds / 3600;
    total_seconds %= 3600;

    int minutes = total_seconds / 60;
    total_seconds %= 60;

    return (struct time){.hours = hours, .minutes = minutes, .seconds = total_seconds};
}

int main(void)
{
    time_t current_epoch_time = time(NULL);
    struct tm *local_time = localtime(&current_epoch_time);
    int seconds_since_midnight = local_time->tm_sec +
                                 local_time->tm_min * 60 +
                                 local_time->tm_hour * 3600;

    struct time current_time = split_time(seconds_since_midnight);

    printf("Current time: %02d:%02d:%02d\n", current_time.hours, current_time.minutes, current_time.seconds);

    return 0;
}