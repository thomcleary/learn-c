#include <stdio.h>
#include "stackADT.h"

int main(void)
{
    Stack s1, s2;
    char *str;

    s1 = create();
    s2 = create();

    push(s1, "one");
    push(s1, "two");

    str = pop(s1);
    printf("Popped [%s] from s1\n", str);

    push(s2, str);
    str = pop(s1);
    printf("Popped [%s] from s1\n", str);

    push(s2, str);

    destroy(s1);

    while (!is_empty(s2))
    {
        printf("Popped [%s] from s2\n", (char *)pop(s2));
    }

    push(s2, "three");
    make_empty(s2);

    if (is_empty(s2))
    {
        printf("s2 is empty\n");
    }
    else
    {
        printf("s2 is not empty\n");
    }

    destroy(s2);

    return 0;
}