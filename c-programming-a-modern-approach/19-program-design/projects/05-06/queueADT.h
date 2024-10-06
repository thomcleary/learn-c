#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef struct queue_type *Queue;

Queue queue_create(int size);
void queue_destroy(Queue q);
void *queue_insert(Queue q, void *item);
void *queue_remove(Queue q);
void *queue_peek(Queue q);
void *queue_peek_tail(Queue q);
bool queue_is_empty(Queue q);
bool queue_is_full(Queue q);

#endif