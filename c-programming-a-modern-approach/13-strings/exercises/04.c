/*
Modify the read_line function from Chapter 13 in each of the following ways:

(a) Have it skip white space before beginning to store input characters
(b) Have it stop reading at the first white-space character (Hint: isspace)
(c) Have it stop reading at the first new-line character, then store the new-line character in the string
(d) Have it leave behind characters that it doesn't have room to store
*/

#include <stdio.h>
#include <ctype.h>

#define STR_LEN 8

int read_line(char str[], int n);
int read_line_a(char str[], int n);
int read_line_b(char str[], int n);
int read_line_c(char str[], int n);
int read_line_d(char str[], int n);

int main(int argc, char **argv)
{
    char str[STR_LEN];

    printf("read_line: ");
    read_line(str, STR_LEN);
    printf("%s\n\n", str);

    printf("read_line (a): ");
    read_line_a(str, STR_LEN);
    printf("%s\n\n", str);

    printf("read_line (b): ");
    read_line_b(str, STR_LEN);
    printf("%s\n\n", str);

    printf("read_line (c): ");
    read_line_c(str, STR_LEN);
    printf("%s\n\n", str);

    printf("read_line (d): ");
    read_line_c(str, STR_LEN);
    printf("%s\n\n", str);
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
    {
        if (i < n) // This will not leave room for the null byte (see (d))
        {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}

int read_line_a(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
    {
        if (i == 0 && isspace(ch))
        {
            continue;
        }

        if (i < n)
        {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}

int read_line_b(char str[], int n)
{
    int ch, i = 0;

    while (!isspace((ch = getchar())))
    {
        if (i < n)
        {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}

int read_line_c(char str[], int n)
{
    int ch, i = 0;

    do
    {
        ch = getchar();
        if (i < n)
        {
            str[i++] = ch;
        }
    } while (ch != '\n');
    str[i] = '\0';
    return i;
}

int read_line_d(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
    {
        if (i < (n - 1))
        {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}
