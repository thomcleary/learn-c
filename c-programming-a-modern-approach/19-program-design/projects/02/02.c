#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

bool is_operator(char ch);
bool is_operand(char c);

int main(void)
{
    char ch;
    Stack stack = create();

    printf("Enter a RPN expression: ");
    scanf(" %c", &ch);

    while (ch != '\n')
    {
        bool ch_is_operand = is_operand(ch);
        bool ch_is_operator = is_operator(ch);

        if (ch_is_operand)
        {
            int ch_value = ch - '0';
            push(stack, ch_value);
        }
        else if (ch_is_operator)
        {
            if (ch == '=')
            {
                printf("Value of expression: %d\n", pop(stack));
                make_empty(stack);
                printf("Enter a RPN expression: ");
            }
            else
            {
                int right_operand = pop(stack);
                int left_operand = pop(stack);

                switch (ch)
                {
                case '+':
                    push(stack, left_operand + right_operand);
                    break;
                case '-':
                    push(stack, left_operand - right_operand);
                    break;
                case '*':
                    push(stack, left_operand * right_operand);
                    break;
                case '/':
                    push(stack, left_operand / right_operand);
                    break;
                }
            }
        }
        else
        {
            exit(EXIT_SUCCESS);
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