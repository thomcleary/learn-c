#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queueADT.h"

struct queue_type
{
    void **contents;
    int size;
    int length;
    int head;
    int tail;
};

Queue queue_create(int size)
{
    Queue q = malloc(sizeof(struct queue_type));
    assert(q != NULL);

    q->contents = malloc(sizeof(*(q->contents)) * size);
    assert(q->contents != NULL);

    q->size = size;
    q->length = 0;
    q->head = 0;
    q->tail = 0;

    return q;
}

void queue_destroy(Queue q)
{
    free(q->contents);
    free(q);
}

void *queue_insert(Queue q, void *item)
{
    if (queue_is_full(q))
    {
        return NULL;
    }

    if (queue_is_empty(q))
    {
        q->contents[q->head] = item;
        q->length = 1;
        return item;
    }

    int next_tail = (q->tail + 1) % q->size;

    q->contents[next_tail] = item;
    q->tail = next_tail;
    q->length += 1;

    return item;
}

void *queue_remove(Queue q)
{
    if (queue_is_empty(q))
    {
        return NULL;
    }

    void *removed = q->contents[q->head];

    if (q->length > 1)
    {
        q->head = (q->head + 1) % q->size;
    }

    q->length -= 1;

    return removed;
}

void *queue_peek(Queue q)
{
    if (queue_is_empty(q))
    {
        return NULL;
    }

    return q->contents[q->head];
}

void *queue_peek_tail(Queue q)
{
    if (queue_is_empty(q))
    {
        return NULL;
    }

    return q->contents[q->tail];
}

bool queue_is_empty(Queue q)
{
    return q->length == 0;
}

bool queue_is_full(Queue q)
{
    return q->size == q->length;
}