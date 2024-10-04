#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

void queue_insert(int item);
int queue_remove(void);
int queue_peek(void);
int queue_peek_tail(void);
bool queue_is_empty(void);

#endif