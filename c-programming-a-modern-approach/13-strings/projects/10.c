/*
Modify 07/11.c so that it includes the following function

void reverse_name(char *name);

The function expects name to point to a string containing a first name followed by a last name.
It modifies the string so that the last name comes first,
followed by a comma, a space, the first initial, and a period.
The original string may contain extra spaces before the first name,
between the first and last names, and after the last name
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

void reverse_name(char *name);

#define NAME_MAX_LEN 80

int main(void)
{
    char name[NAME_MAX_LEN + 1];

    printf("Enter a first and last name: ");

    scanf("%s", name);
    strcat(name, " ");
    scanf("%s", name + strlen(name));

    reverse_name(name);

    printf("%s\n", name);

    return 0;
}

void reverse_name(char *name)
{
    char initial = *name;
    char *p = name;

    while (!isspace(*p++))
    {
        ;
    }

    while (*p)
    {
        *name++ = *p++;
    }

    *name++ = ',';
    *name++ = ' ';
    *name++ = initial;
    *name++ = '.';
    *name = '\0';
}
