#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

struct queue_node
{
    int value;
    struct queue_node *next;
};

struct queue
{
    struct queue_node *head;
    struct queue_node *tail;
};

static struct queue q = {.head = NULL, .tail = NULL};

static void terminate(char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

static void print_queue()
{
    struct queue_node *curr = q.head;

    printf(" ");

    if (curr == NULL)
    {
        printf("[]\n");
        return;
    }

    while (curr != NULL)
    {
        printf("[%d]", curr->value);

        if (curr->next != NULL)
        {
            printf("->");
        }

        curr = curr->next;
    }

    printf("\n");
}

void queue_insert(int i)
{
    printf("queue_insert(%d)\n", i);

    struct queue_node *new_tail = malloc(sizeof(*new_tail));

    if (new_tail == NULL)
    {
        terminate("insert: Queue is full (malloc returned NULL).\n");
    }

    new_tail->value = i;
    new_tail->next = NULL;

    if (queue_is_empty())
    {
        q.head = new_tail;
        q.tail = new_tail;
    }
    else
    {
        q.tail->next = new_tail;
        q.tail = new_tail;
    }

    print_queue();
}

int queue_remove(void)
{
    printf("queue_remove()\n");

    if (queue_is_empty())
    {
        terminate("remove: Queue is empty.\n");
    }

    struct queue_node *removed = q.head;
    int value = removed->value;
    q.head = removed->next;
    free(removed);

    print_queue();

    return value;
}

int queue_peek(void)
{
    if (queue_is_empty())
    {
        terminate("peek: Queue is empty.\n");
    }

    return q.head->value;
}

int queue_peek_tail(void)
{
    if (queue_is_empty())
    {
        terminate("peek_tail: Queue is empty.\n");
    }

    return q.tail->value;
}

bool queue_is_empty(void)
{
    return q.head == NULL;
}