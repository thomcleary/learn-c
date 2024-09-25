#include <stdbool.h>
#include <stdio.h>
#include "stack.h"

bool is_operator(char ch);
bool is_operand(char c);

int main(void)
{
    char ch;

    printf("Enter a RPN expression: ");
    scanf(" %c", &ch);

    while (ch != '\n')
    {
        bool ch_is_operand = is_operand(ch);
        bool ch_is_operator = is_operator(ch);

        if (ch_is_operand)
        {
            int ch_value = ch - '0';
            push(ch_value);
        }
        else if (ch_is_operator)
        {
            if (ch == '=')
            {
                printf("Value of expression: %d\n", pop());
                make_empty();
                printf("Enter a RPN expression: ");
            }
            else
            {
                int right_operand = pop();
                int left_operand = pop();

                switch (ch)
                {
                case '+':
                    push(left_operand + right_operand);
                    break;
                case '-':
                    push(left_operand - right_operand);
                    break;
                case '*':
                    push(left_operand * right_operand);
                    break;
                case '/':
                    push(left_operand / right_operand);
                    break;
                }
            }
        }
        else
        {
            return 0;
        }

        scanf(" %c", &ch);
    }

    return 0;
}

bool is_operator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=';
}

bool is_operand(char ch)
{
    return ch >= '0' && ch <= '9';
}