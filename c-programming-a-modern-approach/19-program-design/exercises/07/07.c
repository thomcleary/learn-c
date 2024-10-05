#include <stdio.h>
#include "stackADT2.h"

int main(void)
{
    Stack s = create();

    for (int i = 0; i < 10; i++)
    {
        push(s, i);
    }

    make_empty(s);

    for (int i = 0; i < 20; i++)
    {
        push(s, i);
    }

    destroy(s);

    return 0;
}