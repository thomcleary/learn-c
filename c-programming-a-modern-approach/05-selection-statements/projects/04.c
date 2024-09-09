/*
Write a program that asks the user to enter a wind speed (in knots)
then displays the corresponding description from the Beaufort scale
*/

#include <stdio.h>

int main(void)
{
    int knots;

    printf("Enter speed (knots): ");
    scanf("%d", &knots);

    if (knots < 1)
    {
        printf("Calm\n");
    }
    else if (knots < 4)
    {
        printf("Light air\n");
    }
    else if (knots < 28)
    {
        printf("Breeze\n");
    }
    else if (knots < 48)
    {
        printf("Gale\n");
    }
    else if (knots < 64)
    {
        printf("Storm\n");
    }
    else
    {
        printf("Hurricane\n");
    }

    return 0;
}