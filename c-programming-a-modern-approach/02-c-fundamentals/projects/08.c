/*
Write a program that calculates the remaining balance on a loan after the first, second and third monthly payments
*/

#include <stdio.h>

int main(void)
{
    float balance;
    printf("Enter amount of loan: ");
    scanf("%f", &balance);

    float interest_rate;
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    float monthly_interest_rate = 1 + (interest_rate / 100.0f / 12.0f);

    float monthly_payment;
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    balance = (balance * monthly_interest_rate) - monthly_payment;
    printf("Balance remaining after first payment: $%.2f\n", balance);

    balance = (balance * monthly_interest_rate) - monthly_payment;
    printf("Balance remaining after second payment: $%.2f\n", balance);

    balance = (balance * monthly_interest_rate) - monthly_payment;
    printf("Balance remaining after third payment: $%.2f\n", balance);
}