/*
Modify 06/03.c so that it includes the following function

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);
*/

#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

int main(void)
{
    int numerator, denominator;

    printf("Enter a fraction (n/d): ");
    scanf("%d/%d", &numerator, &denominator);

    int reduced_numerator, reduced_denominator;

    reduce(numerator, denominator, &reduced_numerator, &reduced_denominator);

    printf("In lowest terms: %d/%d\n", reduced_numerator, reduced_denominator);

    return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
    int m = numerator, n = denominator;

    while (n != 0)
    {
        int r = m % n;
        m = n;
        n = r;
    }

    *reduced_numerator = numerator / m;
    *reduced_denominator = denominator / m;
}
