/*
The square2/c example from /06 will fail if (i * i) exceeds the maximum int value
Determine the smallest value of n that causes failure
Change i to a short and determine the smallest value that causes failure
Change i to a long and determine the smallest value that causes failure
What can you conclude about the number of bits used to store integer types on your machine?
*/

#include <stdio.h>
#include <limits.h>

int main(void)
{
    short i_short = 1;

    while ((short)(i_short * i_short) > 0)
    {
        i_short++;
    }

    printf("i_short overflowed at %d when squared\n", i_short);
    printf("__SHRT_MAX__ %d\n", __SHRT_MAX__);
    printf("int value of %d squared: %d\n\n", i_short, (int)i_short * i_short);

    int i_int = i_short;

    while (i_int * i_int > 0)
    {
        i_int++;
    }

    printf("i_int overflowed at %d when squared\n", i_int);
    printf("__INT_MAX__ %d\n", __INT_MAX__);
    printf("long value of %d squared: %ld\n\n", i_int, (long)i_int * i_int);

    long i_long = i_int;

    while (i_long * i_long > 0l)
    {
        i_long++;
    }

    printf("i_long overflowed at %ld when squared\n", i_long);
    printf("__LONG_MAX__ %ld\n", __LONG_MAX__);
    printf("long long value of %ld squared: %lld\n\n", i_long, (long long)i_long * i_long);

    return 0;
}