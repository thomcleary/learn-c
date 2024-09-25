#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

#define STACK_SIZE 128

static void stack_overflow(void);
static void stack_underflow(void);

static int contents[STACK_SIZE];
static int top = 0;

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

static void stack_overflow(void)
{
    printf("Expression is too complex\n");
    exit(EXIT_FAILURE);
}

static void stack_underflow(void)
{
    printf("Not enough operands in expression\n");
    exit(EXIT_FAILURE);
}