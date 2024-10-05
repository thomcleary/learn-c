#include <stdio.h>
#include <stdlib.h>
#include "stackADT2.h"

struct stack_type
{
    Item *contents;
    int top;
    int size;
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

    s->contents = malloc(sizeof(Item));

    if (s->contents == NULL)
    {
        free(s);
        terminate("Error in create: stack could not be created");
    }

    s->top = 0;
    s->size = 1;
    return s;
}

void destroy(Stack s)
{
    printf("destroy\n");
    free(s->contents);
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
    return s->top == s->size;
}

void push(Stack s, Item i)
{
    if (is_full(s))
    {
        printf("push: stack full, doubling size from [%d] to [%d]\n", s->size, s->size * 2);

        size_t new_size = (s->size * sizeof(*(s->contents))) * 2;
        Item *new_contents = realloc(s->contents, new_size);

        if (new_contents == NULL)
        {
            printf("push: realloc failed, failed to push [%d]\n", i);
            return;
        }

        s->contents = new_contents;
        s->size *= 2;
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