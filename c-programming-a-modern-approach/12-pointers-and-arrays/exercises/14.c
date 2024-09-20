/*
Assume that the following array contains a week's worth of hourly temperature readings,
with each row containing the readings for one day:

int temperatures[7][24];

Write a statement that uses the search function from 07.c to search the entire temperatures array for the value 32
*/

#include <stdbool.h>
#include <stdio.h>

bool search(const int a[], int n, int key);

int main(void)
{
    const int temperatures[7][24] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24},
        {32, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24},
    };

    bool contains_32 = search(&temperatures[0][0], 7 * 24, 32);

    printf("temperatures contains 32? %s\n", contains_32 ? "true" : "false");

    return 0;
}

// From 07.c
bool search(const int a[], int n, int key)
{
    for (const int *p = a; p <= a + (n - 1); p++)
    {
        if (*p == key)
        {
            return true;
        }
    }

    return false;
}