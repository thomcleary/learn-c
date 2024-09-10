/*
Write a program that finds the largest in a series of numbers entered by the user
*/

#include <stdio.h>

int main(void)
{
    float n, largest = 0.00f;

    do
    {
        printf("Enter a number: ");
        scanf("%f", &n);

        if (largest < n)
        {
            largest = n;
        }
    } while (n != 0);

    printf("\nThe largest number entered was %.2f\n", largest);

    return 0;
}