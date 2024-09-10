/*
Write a program that approximates e by computing the value of
1 + 1/1! + 1/2! + 1/3! + ... + 1/n!
where n is an integer entered by the user
*/

#include <stdio.h>

int main(void)
{
    int precision;

    printf("Approximate e\n");
    printf("Enter a level of precision (integer): ");
    scanf("%d", &precision);

    float e = 1.00f;
    int factor = 1;

    for (int i = 1; i <= precision; i++)
    {
        factor *= i;
        e += 1.00f / (factor);
    }

    printf("e: %.5f\n", e);

    return 0;
}