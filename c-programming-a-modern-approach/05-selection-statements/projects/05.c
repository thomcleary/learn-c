/*
Write a program that asks the user to enter the amount of taxable income
then displays the tax due
*/

#include <stdio.h>

int main(void)
{
    float taxable_income, tax_due;
    float base, percentage;

    printf("Enter taxable income: $");
    scanf("%f", &taxable_income);

    if (taxable_income < 750.00f)
    {
        base = 0.00f;
        percentage = 0.01f;
    }
    else if (taxable_income < 2250.00f)
    {
        base = 7.50f;
        percentage = 0.02f;
    }
    else if (taxable_income < 3750.00f)
    {
        base = 37.50f;
        percentage = 0.03f;
    }
    else if (taxable_income < 5250.00f)
    {
        base = 82.50f;
        percentage = 0.04f;
    }
    else if (taxable_income < 7000.00f)
    {
        base = 142.50f;
        percentage = 0.05f;
    }
    else
    {
        base = 230.00f;
        percentage = 0.06f;
    }

    tax_due = base + (taxable_income * percentage);

    printf("Tax due: $%.2f\n", tax_due);

    return 0;
}