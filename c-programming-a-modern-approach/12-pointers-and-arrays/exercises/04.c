/*
Rewrite the make_empty, is_empty and is_full functions from 10/projects/01.c
to use the variable top_ptr instead of the integer variable top
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
char *top_ptr = contents;

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
    top_ptr = contents;
}

bool is_empty(void)
{
    return top_ptr == contents;
}

bool is_full(void)
{
    return top_ptr == &contents[STACK_SIZE - 1];
}

void push(char i)
{
    if (is_full())
    {
        stack_overflow();
    }

    *top_ptr++ = i;
}

char pop(void)
{
    if (is_empty())
    {
        stack_underflow();
    }

    return *(--top_ptr);
}