/*
Improve the remind.c example in the following ways

(a) Have the program print an error message and ignore a reminder if the corresponding day is negative or larger than 31
(b) Allow the user to enter a day, a 25-hour time, and a reminder.
    The printed reminder list should be sorted first by day, then by time.
(c) Have the program print a one-year reminder list.
    Require the user to enter days in the form month/year
*/

/* Prints a one-month reminder list */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN + 3];
    char day_str[6], time_str[7], msg_str[MSG_LEN + 1];
    int month, day, hour, minute, i, j, num_remind = 0;

    for (;;)
    {
        if (num_remind == MAX_REMIND)
        {
            printf("-- No more space left --\n");
            break;
        }

        printf("Enter reminder (month/day hh:mm reminder): ");

        scanf("%2d", &month);
        if (month == 0)
        {
            break;
        }
        scanf("/%2d", &day);
        if (day == 0)
        {
            break;
        }

        sprintf(day_str, "%02d/%02d", month, day);

        scanf("%d:%2d", &hour, &minute);
        sprintf(time_str, " %02d:%02d", hour, minute);

        read_line(msg_str, MSG_LEN);

        if (month < 1 || month > 12 || day < 1 || day > 31)
        {
            printf("Invalid date: Must be between 01/01-12/31\n");
            continue;
        }

        if (hour < 0 || hour > 23 || minute < 0 || minute > 59)
        {
            printf("Invalid time: Must be between 00:00-23:59\n");
            continue;
        }

        for (i = 0; i < num_remind; i++)
        {
            int day_str_len = strlen(day_str);
            int day_compare = strncmp(day_str, reminders[i], day_str_len);
            bool time_earlier = strcmp(time_str, reminders[i] + day_str_len) < 0;

            if (day_compare < 0 || (day_compare == 0 && time_earlier))
            {
                break;
            }
        }
        for (j = num_remind; j > i; j--)
        {
            strcpy(reminders[j], reminders[j - 1]);
        }

        strcpy(reminders[i], day_str);
        strcat(reminders[i], time_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\n Day Reminder\n");
    for (i = 0; i < num_remind; i++)
    {
        printf(" %s\n", reminders[i]);
    }

    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
    {
        if (i < n)
        {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}
