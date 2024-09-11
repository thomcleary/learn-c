/*
Write a program that evaluates an expression
Example: 1+2.5*3 = 10.5

The operands in the expression are floating point numbers
The operators are +, -, * or /
The expression is evaluated from left to right
*/

#include <stdio.h>

int main(void)
{
    float value, operand;
    char operator;

    printf("Enter and expression: ");
    scanf(" %f", &value);

    scanf(" %c", &operator);

    while (operator!= '\n')
    {
        scanf(" %f", &operand);

        switch (operator)
        {
        case '+':
            value += operand;
            break;
        case '-':
            value -= operand;
            break;
        case '*':
            value *= operand;
            break;
        case '/':
            value /= operand;
            break;
        default:
            printf("'%c' is not a valid operator\n", operator);
            return 0;
        }

        while ((operator= getchar()) == ' ')
        {
            ;
        }
    }

    printf("Value of expression: %f\n", value);

    return 0;
}