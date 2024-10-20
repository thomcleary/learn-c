/*
Extend the canopen.c program of Section 22.2 so that the user may put any number of file names on the command line:
`$ canopen foo bar baz`
The program should print a separate "can be opened" or "can't be opened" message for each file.
Have the program terminate with status EXIT_FAILURE if one or more of the files can't be opened.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;

    if (argc < 2)
    {
        fprintf(stderr, "usage: ./01 file1 file2 ...\n");
        exit(EXIT_FAILURE);
    }

    bool error = false;

    for (size_t i = 1; i < argc; i++)
    {
        char *filename = argv[i];

        if ((fp = fopen(filename, "r")) == NULL)
        {
            printf("%s can't be opened\n", filename);
            error = true;
        }
        else
        {
            printf("%s can be opened\n", filename);
        }

        fclose(fp);
    }

    exit(error ? EXIT_FAILURE : EXIT_SUCCESS);
}