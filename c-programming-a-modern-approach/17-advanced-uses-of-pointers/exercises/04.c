/*
Suppose that the following declarations are in effect:
*/

struct point
{
    int x, y;
};

struct rectangle
{
    struct point upper_left, lower_right;
};

struct rectangle *p;

/*
Assume that we want p to point to a rectangle structure whose upper left corner is at (10, 25)
and whose lower right corner is at (20, 15).
Write a series of statements that allocate such a structure and initialize it as indicated.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    p = malloc(sizeof(struct rectangle));

    if (p == NULL)
    {
        printf("malloc failed\n");
        exit(EXIT_FAILURE);
    }

    p->upper_left = (struct point){.x = 10, .y = 25};
    p->lower_right = (struct point){.x = 20, .y = 15};

    printf("UL: (%d, %d)\n", p->upper_left.x, p->upper_left.y);
    printf("LR: (%d, %d)\n", p->lower_right.x, p->lower_right.y);

    free(p);

    return 0;
}