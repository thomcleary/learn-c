#include <stdio.h>
#include "stackADT.h"

void print_length(Stack s, char *stack_name)
{
    printf("%s length: %d\n", stack_name, length(s));
}

int main(void)
{
    Stack s1, s2;
    int n;

    s1 = create();
    s2 = create();

    push(s1, 1);
    printf("push(s1, 1)\n");
    print_length(s1, "s1");
    push(s1, 2);
    printf("push(s1, 2)\n");
    print_length(s1, "s1");

    n = pop(s1);
    printf("n = pop(s1)\n");
    printf("Popped %d from s1\n", n);
    print_length(s1, "s1");

    push(s2, n);
    printf("push(s2, n)\n");
    print_length(s2, "s2");
    n = pop(s1);
    printf("n = pop(s1)\n");
    printf("Popped %d from s1\n", n);
    print_length(s1, "s1");

    push(s2, n);
    printf("push(s2, n)\n");
    print_length(s2, "s2");

    destroy(s1);

    while (!is_empty(s2))
    {
        printf("Popped %d from s2\n", pop(s2));
        print_length(s2, "s2");
    }

    push(s2, 3);
    printf("push(s2, 3)\n");
    print_length(s2, "s2");
    make_empty(s2);
    printf("make_empty(s2)\n");
    print_length(s2, "s2");

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