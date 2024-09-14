/*
Modify the repdigit.c example so that it prints a table showing how many times each digit appears in the number
*/

#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int digit_count[10] = {0};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0)
    {
        digit = n % 10;
        digit_count[digit]++;
        n /= 10;
    }

    printf("Digit:      ");
    for (int i = 0; i < sizeof(digit_count) / sizeof(digit_count[0]); i++)
    {
        printf("%3d ", i);
    }
    printf("\n");

    printf("Occurences: ");
    for (int i = 0; i < sizeof(digit_count) / sizeof(digit_count[0]); i++)
    {
        printf("%3d ", digit_count[i]);
    }
    printf("\n");

    return 0;
}