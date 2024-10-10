/*
(a) Write the following function

int count_ones(unsigned char ch);

count_ones should return the number of 1 bits in ch

(b) Write the function in part (a) without using a loop
*/

#include <stdio.h>
#include <assert.h>

int count_ones_a(unsigned char ch)
{
    int ones = 0;

    while (ch > 0)
    {
        if (ch & 1)
        {
            ones++;
        }

        ch >>= 1;
    }

    return ones;
}

int count_ones_b(unsigned char ch)
{
    return (ch & 1) +
           ((ch & 2) >> 1) +
           ((ch & 4) >> 2) +
           ((ch & 8) >> 3) +
           ((ch & 16) >> 4) +
           ((ch & 32) >> 5) +
           ((ch & 64) >> 6) +
           ((ch & 128) >> 7);
}

int main(void)
{
    int n = 47;
    // 0010_1111

    printf("count_ones_a(%d): %d\n", n, count_ones_a(n));
    assert(count_ones_a(n) == 5);

    printf("count_ones_b(%d): %d\n", n, count_ones_b(n));
    assert(count_ones_b(n) == 5);

    return 0;
}