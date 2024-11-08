/*
Use the techniques of Section 13.6 to condense the count_spaces function of Section 13.4
In particular, replace the for statement by a while loop
*/

int count_spaces(const char s[])
{
    int count = 0, i;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
        {
            count++;
        }
    }

    return count;
}

int count_spaces_condensed(const char s[])
{
    int count = 0;

    while (*s)
    {
        if (*s++ == ' ')
        {
            count++;
        }
    }

    return count;
}