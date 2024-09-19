/*
Write a program that evaluates reverse polish notation expressions.
The operands will be single digit integers.
The operators are +,-,*,/ and =
The = operator causes the top stack item to be displayed,
afterwards the stack is cleared and the user is prompted to enter another expression
The process continues until the user enters a character that is not an operator or operand

If the stack overflows the program will display the message
Expression is too complex
and terminate

If the stack underflows (because of expressions like (1 2 + +))
the program will display the message
Not enough operands in expression
and terminate
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 128

int contents[STACK_SIZE];
int top = 0;

bool is_operator(char ch);
bool is_operand(char c);
void stack_overflow(void);
void stack_underflow(void);
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int n);
int pop(void);

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

void stack_overflow(void)
{
    printf("Expression is too complex\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
    printf("Not enough operands in expression\n");
    exit(EXIT_FAILURE);
}

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(int n)
{
    if (is_full())
    {
        stack_overflow();
    }

    contents[top++] = n;
}

int pop(void)
{
    if (is_empty())
    {
        stack_underflow();
    }

    return contents[--top];
}