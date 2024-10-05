#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
    char ch;
    Stack stack = create();

    printf("Enter parentheses and/or braces: ");

    while ((ch = getchar()) != '\n')
    {
        if (ch == '(' || ch == '{')
        {
            push(stack, ch);
        }
        else
        {
            char popped = pop(stack);

            if ((popped == '(' && ch == ')') || (popped == '{' && ch == '}'))
            {
                continue;
            }

            printf("Parentheses/braces are not nested properly\n");
            exit(EXIT_SUCCESS);
        }
    }

    if (is_empty(stack))
    {
        printf("Parentheses/braces are nested properly\n");
    }
    else
    {
        printf("Parentheses/braces are not nested properly\n");
    }

    return 0;
}