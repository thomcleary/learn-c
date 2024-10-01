/*
Section 15.2 describes a file, stack.c, that provides functions for storing integers in a stack.
In that section, the stack was implemented as an array.
Modify stack.c so that a stack is now stored as a linked list.
Replace the contents and top variables by a single variable that points to the first node in the list
(the "top" of the stack).
Write the functions in stack.c so that they us this pointer.
Remove the is_full function, instead having push return either true (if memory was available to create a node)
or false (if not)
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void make_empty(void);
bool is_empty(void);
bool push(int i);
int pop(void);
void print_stack(void);

struct node
{
    int value;
    struct node *next;
};

struct node *top = NULL;

int main(void)
{
    print_stack();

    push(1);

    print_stack();

    pop();

    print_stack();

    is_empty();

    push(1);
    push(2);
    push(3);

    print_stack();

    make_empty();
    is_empty();

    print_stack();

    return 0;
}

void free_item(struct node *item)
{
    if (item->next != NULL)
    {
        free_item(item->next);
    }

    printf("- freeing item: [%d]\n", item->value);
    free(item);
}

void make_empty(void)
{
    printf("make_empty:\n");

    if (top == NULL)
    {
        return;
    }

    free_item(top);

    top = NULL;
}

bool is_empty(void)
{
    printf("is_empty: [%s]\n", top == NULL ? "true" : "false");
    return top == NULL;
}

bool push(int i)
{
    printf("push: [%d]\n", i);
    struct node *new_top = malloc(sizeof(struct node));

    if (new_top == NULL)
    {
        printf("is_full: [true]\n");
        return true;
    }

    *new_top = (struct node){.value = i, .next = top};
    top = new_top;

    printf("is_full: [false]\n");
    return false;
}

int pop(void)
{
    if (top == NULL)
    {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }

    int value = top->value;

    struct node *new_top = top->next;
    free(top);
    top = new_top;

    printf("pop: [%d]\n", value);
    return value;
}

void print_stack(void)
{
    struct node *p = top;

    printf("stack: [");
    while (p != NULL)
    {
        printf("%d", p->value);

        if (p->next != NULL)
        {
            printf("->");
        }

        p = p->next;
    }
    printf("]\n");
}