/*
Modify the stack example so that it stores characters instead of integers
Next, add a main function that asks the user to enter a series of parantheses and/or braces,
then indicates whether or not theyre properly nested
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void stack_overflow(void);
void stack_underflow(void);
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char ch);
char pop(void);

int main(void)
{
    char ch;

    printf("Enter parentheses and/or braces: ");

    while ((ch = getchar()) != '\n')
    {
        if (ch == '(' || ch == '{')
        {
            push(ch);
        }
        else
        {
            char popped = pop();

            if ((popped == '(' && ch == ')') || (popped == '{' && ch == '}'))
            {
                continue;
            }

            printf("Parentheses/braces are not nested properly\n");
            exit(EXIT_SUCCESS);
        }
    }

    if (is_empty())
    {
        printf("Parentheses/braces are nested properly\n");
    }
    else
    {
        printf("Parentheses/braces are not nested properly\n");
    }

    return 0;
}

void stack_overflow(void)
{
    printf("Stack overflow\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
    printf("Stack underflow\n");
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

void push(char i)
{
    if (is_full())
    {
        stack_overflow();
    }

    contents[top++] = i;
}

char pop(void)
{
    if (is_empty())
    {
        stack_underflow();
    }

    return contents[--top];
}