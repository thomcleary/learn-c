/*
Modify 07/sum2.c to sum a series of double values
*/

#include <stdio.h>

int main(void)
{
    double n, sum = 0;

    printf("This program sus a series of doubles.\n");
    printf("Enter doubles (0 to terminate): ");

    scanf("%lf", &n);
    while (n != 0)
    {
        sum += n;
        scanf("%lf", &n);
    }
    printf("The sum is: %lf\n", sum);

    return 0;
}