#include <stdio.h>
#include <assert.h>
#include "queueADT.h"

int main(void)
{
    Queue q = queue_create(3);
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("queue_is_empty(q): [%d]\n", queue_is_empty(q));
    printf("queue_is_full(q): [%d]\n", queue_is_full(q));

    for (int i = 0; i < 3; i++)
    {

        int *num = nums + i;
        printf("queue_insert(q, %d)\n", *num);
        queue_insert(q, num);
    }

    printf("queue_is_empty(q): [%d]\n", queue_is_empty(q));
    printf("queue_is_full(q): [%d]\n", queue_is_full(q));

    int *full_insert = queue_insert(q, nums + 3);
    assert(full_insert == NULL);
    printf("queue_insert(nums + 3): [NULL]\n");

    printf("queue_peek(q): [%d]\n", *((int *)queue_peek(q)));

    printf("queue_peek_tail(q): [%d]\n", *((int *)queue_peek_tail(q)));

    printf("queue_remove(q): [%d]\n", *((int *)queue_remove(q)));

    printf("queue_is_empty(q): [%d]\n", queue_is_empty(q));
    printf("queue_is_full(q): [%d]\n", queue_is_full(q));

    printf("queue_peek(q): [%d]\n", *((int *)queue_peek(q)));
    printf("queue_peek_tail(q): [%d]\n", *((int *)queue_peek_tail(q)));

    printf("queue_remove(q): [%d]\n", *((int *)queue_remove(q)));

    printf("queue_is_empty(q): [%d]\n", queue_is_empty(q));
    printf("queue_is_full(q): [%d]\n", queue_is_full(q));

    printf("queue_remove(q): [%d]\n", *((int *)queue_remove(q)));

    printf("queue_is_empty(q): [%d]\n", queue_is_empty(q));
    printf("queue_is_full(q): [%d]\n", queue_is_full(q));

    int *empty_peek = queue_peek(q);
    assert(empty_peek == NULL);
    printf("queue_peek(q): [NULL]\n");

    int *empty_peek_tail = queue_peek_tail(q);
    assert(empty_peek_tail == NULL);
    printf("queue_peek_tail(q): [NULL]\n");

    queue_destroy(q);

    return 0;
}