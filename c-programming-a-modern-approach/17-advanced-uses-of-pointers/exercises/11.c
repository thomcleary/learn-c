/*
Write the following function:

int count_occurences(struct node *list, int n);

The list parameter points to a linked list;
the function should return the number of times that n appears in this list.
Assume that the node structure is the one defined in Section 17.5
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

int count_occurences(struct node *list, int n)
{
    int count = 0;

    while (list != NULL)
    {
        if (list->value == n)
        {
            count++;
        }
        list = list->next;
    }

    return count;
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

    printf("count_occurences(1): [%d]\n", count_occurences(&ll, 1));
    printf("count_occurences(2): [%d]\n", count_occurences(&ll, 2));
    printf("count_occurences(3): [%d]\n", count_occurences(&ll, 3));

    return 0;
}