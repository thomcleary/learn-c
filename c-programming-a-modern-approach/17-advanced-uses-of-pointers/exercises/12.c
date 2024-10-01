/*
Write the following function:

struct node *find_last(struct node *list, int n);

The list parameter points to a linked list.
The function should return a pointer to the last node that contains n;
it should return NULL if n doesn't appear in the list.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

struct node *find_last(struct node *list, int n)
{
    struct node *last = NULL;

    while (list != NULL)
    {
        if (list->value == n)
        {
            last = list;
        }
        list = list->next;
    }

    return last;
}

struct node *new_node(int value)
{
    struct node *n = malloc(sizeof(struct node));

    if (n == NULL)
    {
        printf("malloc failed\n");
        exit(EXIT_FAILURE);
    }

    n->value = value;
    n->next = NULL;

    return n;
}

int main(void)
{
    struct node ll = {.value = 1, .next = NULL};
    ll.next = new_node(2);
    ll.next->next = new_node(2);
    ll.next->next->next = new_node(3);
    ll.next->next->next->next = new_node(3);
    ll.next->next->next->next->next = new_node(2);

    printf("Address of last 1: [%p]\n", &ll);
    printf("find_last(1):      [%p]\n", find_last(&ll, 1));

    printf("Address of last 2: [%p]\n", ll.next->next->next->next->next);
    printf("find_last(2):      [%p]\n", find_last(&ll, 2));

    printf("Address of last 3: [%p]\n", ll.next->next->next->next);
    printf("find_last(3):      [%p]\n", find_last(&ll, 3));

    return 0;
}