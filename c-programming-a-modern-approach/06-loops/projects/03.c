/*
Write a program that asks the user to enter a fraction
then reduces the fraction to lowest terms
*/

#include <stdio.h>

int main(void)
{
    int numerator, denominator;

    printf("Enter a fraction (n/d): ");
    scanf("%d/%d", &numerator, &denominator);

    int m = numerator, n = denominator;

    while (n != 0)
    {
        int r = m % n;
        m = n;
        n = r;
    }

    printf("In lowest terms: %d/%d\n", numerator / m, denominator / m);

    return 0;
}