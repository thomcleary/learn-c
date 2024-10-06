#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queueADT.h"

struct node
{
    void *item;
    struct node *next;
};

struct queue_type
{
    struct node *head;
    struct node *tail;
};

Queue queue_create(void)
{
    Queue q = malloc(sizeof(struct queue_type));
    assert(q != NULL);

    q->tail = NULL;

    return q;
}

void queue_destroy(Queue q)
{
    while (!queue_is_empty(q))
    {
        queue_remove(q);
    }

    free(q);
}

void *queue_insert(Queue q, void *item)
{
    struct node *new_item = malloc(sizeof(struct node));

    if (new_item == NULL)
    {
        return NULL;
    }

    new_item->item = item;
    new_item->next = NULL;

    if (queue_is_empty(q))
    {
        q->head = new_item;
        q->tail = new_item;
        return item;
    }

    q->tail->next = new_item;
    q->tail = new_item;

    return item;
}

void *queue_remove(Queue q)
{
    if (queue_is_empty(q))
    {
        return NULL;
    }

    struct node *removed = q->head;
    void *item = removed->item;
    q->head = removed->next;

    if (q->head == NULL)
    {
        q->tail = NULL;
    }

    free(removed);

    return item;
}

void *queue_peek(Queue q)
{
    if (queue_is_empty(q))
    {
        return NULL;
    }

    return q->head->item;
}

void *queue_peek_tail(Queue q)
{
    if (queue_is_empty(q))
    {
        return NULL;
    }

    return q->tail->item;
}

bool queue_is_empty(Queue q)
{
    return q->head == NULL;
}