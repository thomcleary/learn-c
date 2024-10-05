#include <stdio.h>
#include "stackADT2.h"

int main(void)
{
    Stack s = create(10);

    push(s, 1);
    push(s, 2);
    peek(s);
    printf("\n");

    pop(s);
    peek(s);
    printf("\n");

    push(s, 3);
    push(s, 42);
    peek(s);
    printf("\n");

    make_empty(s);
    push(s, 37);
    peek(s);
    printf("\n");

    pop(s);
    peek(s);
    printf("\n");

    destroy(s);

    return 0;
}