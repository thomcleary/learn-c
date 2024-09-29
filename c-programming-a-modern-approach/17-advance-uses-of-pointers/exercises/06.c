/*
Modify the delete_from_list function so that it uses only one pointer variable instead of two (cur and prev)
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

struct node *delete_from_list(struct node *list, int n)
{
    struct node *curr = list;

    if (curr == NULL)
    {
        return NULL;
    }

    if (curr->value == n)
    {
        struct node *head = curr->next;
        free(curr);
        return head;
    }

    while (curr->next != NULL && curr->next->value != n)
    {
        curr = curr->next;
    }

    if (curr->next != NULL)
    {
        struct node *to_delete = curr->next;
        curr->next = to_delete->next;
        free(to_delete);
    }

    return list;
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
    ll->next->next = new_node(3);

    print_list(ll);

    printf("\nDelete [2]\n\n");
    ll = delete_from_list(ll, 2);

    print_list(ll);

    return 0;
}