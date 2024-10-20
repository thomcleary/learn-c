/*
(a) Write your own version of the fgets function.
Make it behave as much like the real fgets functions as possible;
in particular, make sure that it has the proper return value.

(b) Write your own version of fputs, following the same rules as part (a)
*/

#include <stdio.h>

/**
 * `man fgets`
 *
 * The fgets() function reads at most one less than the number of characters specified by size from the given stream and stores them in the string str.
 * Reading stops when a newline character is found, at end-of-file or error.
 * The newline, if any, is retained.
 * If any characters are read and there is no error, a ‘\0’ character is appended to end the string.
 *
 * @returns
 * Upon successful completion, fgets() and gets() return a pointer to the string.
 * If end-of-file occurs before any characters are read, they return NULL and the buffer contents remain unchanged.
 * If an error occurs, they return NULL and the buffer contents are indeterminate.
 * The fgets() and gets() functions do not distinguish between end-of-file and error, and callers must use feof(3) and ferror(3) to determine which occurred.
 */
char *my_fgets(char *line, int length, FILE *stream)
{
    size_t i = 0;
    while (i < (length - 1))
    {
        int ch = getc(stream);

        if (ch == EOF)
        {
            if (i == 0 || ferror(stream))
            {
                return NULL;
            }
            break;
        }

        line[i++] = ch;

        if (ch == '\n')
        {
            break;
        }
    }

    line[i] = '\0';

    return line;
}

/**
 * `man fputs`
 *
 * The function fputs() writes the string pointed to by s to the stream pointed to by stream.
 *
 * @returns
 * The functions fputs() and puts() return a nonnegative integer on success and EOF on error.
 */
int my_fputs(const char *str, FILE *stream)
{
    while (*str)
    {
        int result = putc(*str, stream);

        if (result == EOF)
        {
            return EOF;
        }

        str++;
    }

    return 0;
}

int main(void)
{
    char buffer[BUFSIZ];

    const char *in_filename = "14.c";
    FILE *in_fp = fopen(in_filename, "r");

    printf("in_fp: [%s]\n", in_filename);
    printf("my_fgets(buffer, 10, in_fp): %s", my_fgets(buffer, 10, in_fp));
    printf("my_fgets(buffer, BUFSIZ, in_fp): %s", my_fgets(buffer, BUFSIZ, in_fp));
    fclose(in_fp);

    const char *out_filename = "14.txt";
    FILE *out_fp = fopen(out_filename, "w");
    printf("\nout_fp: [%s]\n", out_filename);
    my_fputs("line 1\n", out_fp);
    my_fputs("line ", out_fp);
    my_fputs("2\n", out_fp);
    my_fputs("line 3\nline 4", out_fp);
    fclose(out_fp);

    return 0;
}