/*
Modify the queue.h header of Exercise 1 so that it defines a Queue type,
where Queue is a structure containing a fixed-length array (see Exercise 3(a)).
Modify the functions in queue.h to take a Queue * parameter
*/

#ifndef EX05_H
#define EX05_H

#include <stdbool.h>

typedef int Item;

typedef struct queue_t *Queue;

void queue_insert(Queue q, Item i);
Item queue_remove(Queue q);
Item queue_peek(Queue q);
Item queue_peek_tail(Queue q);
bool queue_is_empty(Queue q);

#endif