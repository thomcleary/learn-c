/*
Write a program that asks the user to enter a U.S dollar amount
and then shows how to pay that amount using the smallest number of
$20, $20, $5, and $1 dollar bills
*/

#include <stdio.h>

int main(void)
{
    int amount;
    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    int twenties = amount / 20;

    amount -= twenties * 20;

    int tens = amount / 10;

    amount -= tens * 10;

    int fives = amount / 5;

    amount -= fives * 5;

    int ones = amount;

    printf("$20 dollar bills: %d\n", twenties);
    printf("$10 dollar bills: %d\n", tens);
    printf("$5 dollar bills: %d\n", fives);
    printf("$1 dollar bills: %d\n", ones);

    return 0;
}