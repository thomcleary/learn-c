#include <stdio.h>
#include "queue.h"

int main(void)
{
    queue_insert(1);
    queue_insert(2);
    queue_insert(3);
    queue_insert(4);
    queue_insert(5);
    // queue_insert(6);
    queue_remove();
    queue_remove();
    queue_remove();
    queue_remove();
    queue_remove();
    // queue_remove();
    printf("queue_is_empty: [%d]\n", queue_is_empty());
    queue_insert(42);
    queue_insert(37);
    queue_insert(99);
    printf("queue_is_empty: [%d]\n", queue_is_empty());
    printf("queue_peek: [%d]\n", queue_peek());
    printf("queue_peek_tail: [%d]\n", queue_peek_tail());
    return 0;
}