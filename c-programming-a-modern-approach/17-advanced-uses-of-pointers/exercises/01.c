/*
Having to check the return values of malloc (or any other memory allocation function)
each time we call it can be an annoyance.
Write a function my_malloc that serves as a wrapper for malloc.
When we call my_malloc and ask it to allocate n bytes, it in turn calls malloc,
tests to make sure that malloc doesn't return a null pointer,
and then returns the pointer from malloc.
Have my_malloc print an error message and terminate the program if malloc returns a null pointer.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *my_malloc(size_t size)
{
    void *p = malloc(size);

    if (p == NULL)
    {
        printf("malloc returned NULL\n");
        exit(EXIT_FAILURE);
    }

    return p;
}

int main(void)
{
    const char *s = "my_malloc'd";

    char *my_mallocd_s = my_malloc(strlen(s) + 1);

    strcpy(my_mallocd_s, s);

    printf("my_mallcd_s: [%s]\n", my_mallocd_s);

    free(my_mallocd_s);

    return 0;
}