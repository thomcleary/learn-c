/*
Modify 02/08.c so that is also asks the user to enter the number of payments
and then displays the balance remaining after each of these payments
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

    int num_payments;
    printf("Enter number of payments: ");
    scanf("%d", &num_payments);

    printf("\n");

    for (int i = 1; i <= num_payments; i++)
    {
        balance = (balance * monthly_interest_rate) - monthly_payment;
        printf("Balance remaining after payment %d: $%.2f\n", i, balance);
    }

    return 0;
}