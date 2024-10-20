/*
The `fcopy.c` example has one minor flaw:
it doesn't check for errors as it's writing to the destination file.
Errors during writing are rare, but do occaisonally occur
(the disk might become full for example).
Show how to add the missing error check to the program,
assuming that we want to display a message and terminate immediatley if an error occurs.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *source_fp, *dest_fp;
    int ch;

    if (argc != 3)
    {
        fprintf(stderr, "usage: fcopy source dest\n");
        exit(EXIT_FAILURE);
    }

    if ((source_fp = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((dest_fp = fopen(argv[2], "wb")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        fclose(source_fp);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(source_fp)) != EOF)
    {
        // Solution: check return value of putc
        if (putc(ch, dest_fp) == EOF)
        {
            fprintf(stderr, "Error while copying to file %s\n", argv[2]);
            fclose(source_fp);
            fclose(dest_fp);
            exit(EXIT_FAILURE);
        }
    }

    fclose(source_fp);
    fclose(dest_fp);
    return 0;
}