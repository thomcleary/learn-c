/*
Modify the delete_from_list function (Section 17.5) so that its first parameter has type

struct node **

(a pointer to a pointer to the first node in the list)

and its return type is void.

delete_from_list must modify its first argument to point to the list after the desired node has been deleted.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

void delete_from_list(struct node **list, int n)
{
    struct node *curr, *prev;

    for (curr = *list, prev = NULL;
         curr != NULL && curr->value != n;
         prev = curr, curr = curr->next)
    {
        ;
    }

    if (curr == NULL)
    {
        return;
    }
    if (prev == NULL)
    {
        *list = (*list)->next;
    }
    else
    {
        prev->next = curr->next;
    }

    free(curr);
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

void print_list(struct node *list)
{
    while (list != NULL)
    {
        printf("[%d]", list->value);

        if (list->next != NULL)
        {
            printf("->");
        }

        list = list->next;
    }
    printf("\n");
}

int main(void)
{
    struct node *ll = new_node(1);

    ll->next = new_node(2);
    ll->next->next = new_node(2);
    ll->next->next->next = new_node(3);
    ll->next->next->next->next = new_node(3);
    ll->next->next->next->next->next = new_node(2);

    print_list(ll);
    printf("delete_from_list(1)\n");
    delete_from_list(&ll, 1);
    print_list(ll);

    return 0;
}