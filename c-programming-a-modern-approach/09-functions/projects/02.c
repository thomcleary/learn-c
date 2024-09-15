/*
Modify 05/05.c so that it uses a function to compute the amount of income tax.
When passed an amount of taxable income, the function will return the tax due.
*/

#include <stdio.h>

double tax_due(double taxable_income);

int main(void)
{
    double taxable_income;

    printf("Enter taxable income: $");
    scanf("%lf", &taxable_income);

    printf("Tax due: $%.2f\n", tax_due(taxable_income));

    return 0;
}

double tax_due(double taxable_income)
{
    double base, percentage;

    if (taxable_income < 750.00)
    {
        base = 0.00;
        percentage = 0.01;
    }
    else if (taxable_income < 2250.00)
    {
        base = 7.50;
        percentage = 0.02;
    }
    else if (taxable_income < 3750.00)
    {
        base = 37.50;
        percentage = 0.03;
    }
    else if (taxable_income < 5250.00)
    {
        base = 82.50;
        percentage = 0.04;
    }
    else if (taxable_income < 7000.00)
    {
        base = 142.50;
        percentage = 0.05;
    }
    else
    {
        base = 230.00;
        percentage = 0.06;
    }

    return base + (taxable_income * percentage);
}