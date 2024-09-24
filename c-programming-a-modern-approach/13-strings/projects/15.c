/*
Modify 10/06.c so that it includes the following function

int evaluate_RPN_expression(const char *expression);

The function returns the value of the RPN expression pointed to by expression
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 128

int contents[STACK_SIZE];
int top = 0;

int evaluate_RPN_expression(const char *expression);
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
    char expression[256];

    while (true)
    {
        printf("Enter a RPN expression: ");
        fgets(expression, sizeof(expression), stdin);
        printf("Value of expression: %d\n", evaluate_RPN_expression(expression));
    };

    return 0;
}

int evaluate_RPN_expression(const char *expression)
{
    while (*expression != '\n')
    {
        char ch = *expression;
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
                int value = pop();
                make_empty();
                return value;
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
        else if (!isspace(ch))
        {
            exit(EXIT_SUCCESS);
        }

        expression++;
    }

    printf("Expression must end with '='\n");
    exit(EXIT_FAILURE);
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
