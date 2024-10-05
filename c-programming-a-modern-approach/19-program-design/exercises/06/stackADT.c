#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

#define STACK_SIZE 100

struct stack_type
{
    Item contents[STACK_SIZE];
    int top;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack create(void)
{
    printf("create\n");

    Stack s = malloc(sizeof(struct stack_type));

    if (s == NULL)
    {
        terminate("Error in create: stack could not be created.");
    }

    s->top = 0;
    return s;
}

void destroy(Stack s)
{
    printf("destroy\n");
    free(s);
}

void make_empty(Stack s)
{
    printf("make_empty\n");
    s->top = 0;
}

bool is_empty(Stack s)
{
    return s->top == 0;
}

bool is_full(Stack s)
{
    return s->top == STACK_SIZE;
}

void push(Stack s, Item i)
{
    if (is_full(s))
    {
        terminate("Error in push: stack is full.");
    }

    printf("push: [%d]\n", i);

    s->contents[s->top++] = i;
}

Item pop(Stack s)
{
    if (is_empty(s))
    {
        terminate("Error in pop: stack is empty.");
    }

    Item popped = s->contents[--s->top];

    printf("pop: [%d]\n", popped);

    return popped;
}

Item peek(Stack s)
{
    if (is_empty(s))
    {
        terminate("Error in peek: stack is empty.");
    }

    Item peeked = s->contents[s->top - 1];

    printf("peek: [%d]\n", peeked);

    return peeked;
}