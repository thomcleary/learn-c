/*
A `queue` is similar to a stack,
except that items are added at one end but removed from the other in a `FIFO` (first in, first-out) fashion.
Operations on a queue might include:

- inserting an item at the end of the queue
- removing an item from the beginning of the queue
- returning the first item in the queue (without changing the queue)
- returning the last item in the queue (qithout changing the queue)
- testing whether the queue is empty

Write an interface for a queue module in the form of a header file named `queue.h`
*/

#ifndef EX01_H
#define EX01_H

#include <stdbool.h>

void insert(void *item);
void *remove(void);
void *peek(void);
void *peek_end(void);
bool is_empty(void);

#endif