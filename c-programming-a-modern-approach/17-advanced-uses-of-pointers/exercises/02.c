/*
Write a function named duplicate that uses dynamic storage allocation to create a copy of a a string.

For example the call:
p = duplicate(str);

would allocate space for a string of the same length as str,
copy the contents of str into the new string, and return a pointer to it.

Have duplicate return a null pointer if the memory allocation fails.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

char *duplicate(const char *str)
{
    char *dup = malloc(strlen(str) + 1);

    if (dup == NULL)
    {
        return dup;
    }

    strcpy(dup, str);
    return dup;
}

int main(void)
{
    const char *s = "dupe deez nuts";

    char *s_dupe = duplicate(s);

    if (s_dupe == NULL)
    {
        printf("s_dupe: NULL\n");
    }
    else
    {
        printf("s_dupe: [%s]\n", s_dupe);
    }

    free(s_dupe);

    return 0;
}