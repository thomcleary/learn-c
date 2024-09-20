/*
Modify 02/07.c so that it includes the following function

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);
*/

#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void)
{
    int amount;
    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    int twenties, tens, fives, ones;

    pay_amount(amount, &twenties, &tens, &fives, &ones);

    printf("$20 dollar bills: %d\n", twenties);
    printf("$10 dollar bills: %d\n", tens);
    printf("$5 dollar bills: %d\n", fives);
    printf("$1 dollar bills: %d\n", ones);

    return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
    *twenties = dollars / 20;

    dollars -= *twenties * 20;

    *tens = dollars / 10;

    dollars -= *tens * 10;

    *fives = dollars / 5;

    dollars -= *fives * 5;

    *ones = dollars;
}
