#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#define MAX_QUEUE_SIZE 5

struct queue
{
    int contents[MAX_QUEUE_SIZE];
    int head;
    int tail;
    int size;
};

static struct queue q = {
    .contents = {0},
    .head = 0,
    .tail = 0,
    .size = 0};

static void terminate(char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

static void print_queue()
{
    printf(" ");

    if (queue_is_empty())
    {
        printf("[]\n");
        return;
    }

    int pos = q.head;
    for (int i = 0; i < q.size; i++)
    {
        int curr = pos % MAX_QUEUE_SIZE;

        printf("[%d]", q.contents[curr]);

        if (curr != q.tail)
        {
            printf("->");
        }

        pos += 1;
    }

    printf("\n");
}

void queue_insert(int i)
{
    printf("queue_insert(%d)\n", i);

    if (q.size == MAX_QUEUE_SIZE)
    {
        terminate("insert: Queue is full.\n");
    }

    if (queue_is_empty())
    {
        q.contents[q.head] = i;
        q.tail = q.head;
    }
    else
    {
        q.tail = (q.tail + 1) % MAX_QUEUE_SIZE;
        q.contents[q.tail] = i;
    }

    q.size += 1;

    print_queue();
}

int queue_remove(void)
{
    printf("queue_remove()\n");

    if (queue_is_empty())
    {
        terminate("remove: Queue is empty.\n");
    }

    int removed = q.contents[q.head];

    q.head = (q.head + 1) % MAX_QUEUE_SIZE;
    q.size -= 1;

    print_queue();

    return removed;
}

int queue_peek(void)
{
    if (queue_is_empty())
    {
        terminate("peek: Queue is empty.\n");
    }

    return q.contents[q.head];
}

int queue_peek_tail(void)
{
    if (queue_is_empty())
    {
        terminate("peek_tail: Queue is empty.\n");
    }

    return q.contents[q.tail];
}

bool queue_is_empty(void)
{
    return q.size == 0;
}