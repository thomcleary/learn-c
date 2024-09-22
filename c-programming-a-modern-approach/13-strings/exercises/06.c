/*
Write a function named censor that modifies a string by replacing every occurence of foo by xxx
For example, the string "food fool" would become "xxxd xxxl".
Make the function as short as possible withouit sacrificing clarity
*/

#include <stdio.h>
#include <string.h>

char *censor(char *str);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Censor string required");
        return 0;
    }

    char *str = argv[1];

    censor(str);

    printf("%s\n", str);

    return 0;
}

char *censor(char *str)
{
    const char *foo = "foo";
    int foo_len = strlen(foo);

    char *foo_in_str = strstr(str, foo);

    if (foo_in_str == NULL)
    {
        return str;
    }

    strncpy(foo_in_str, "xxx", foo_len);
    censor(str + foo_len);

    return str;
}
