/*
Modify 03/06.c so that the user may add, subtract, multiply or divide two fractions
(by entering either +,-,* or / between the fractions)
*/

#include <stdio.h>

int main(void)
{
    int num1, denom1, num2, denom2, result_num, result_denom;
    char operation;

    printf("Enter two fractions separated by (+,-,* or /): ");
    scanf("%d/%d %c %d/%d", &num1, &denom1, &operation, &num2, &denom2);

    if (operation == '+')
    {
        result_num = num1 * denom2 + num2 * denom1;
        result_denom = denom1 * denom2;
    }
    else if (operation == '-')
    {
        result_num = num1 * denom2 - num2 * denom1;
        result_denom = denom1 * denom2;
    }
    else if (operation == '*')
    {
        result_num = num1 * num2;
        result_denom = denom1 * denom2;
    }
    else if (operation == '/')
    {
        result_num = num1 * denom2;
        result_denom = denom1 * num2;
    }
    else
    {
        printf("'%c' is not a valid operation.\n", operation);
        return 0;
    }

    printf("The result is %d/%d\n", result_num, result_denom);

    return 0;
}