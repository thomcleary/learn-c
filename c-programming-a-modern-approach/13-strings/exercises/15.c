#include <stdio.h>

/*
Let f be the following function
*/

int f(char *s, char *t)
{
    char *p1, *p2;

    for (p1 = s; *p1; p1++)
    {
        for (p2 = t; *p2; p2++)
        {
            if (*p1 == *p2)
            {
                break;
            }
        }
        if (*p2 == '\0')
        {
            break;
        }
    }
    return p1 - s;
}

/*
(a) What is the value of f("abcd", "babc")?
(b) What is the value of f("abcd", "bcd")?
(c) In general, what value does f return when passed two string s and t?
*/

int main(void)
{
    printf("(a): %d\n", f("abcd", "babc"));
    printf("(b): %d\n", f("abcd", "bcd"));
    printf("(c): f returns the number of consecutive characters starting at s[0] that appear in t\n");
    return 0;
}