/*
Write a program named fcat that "concatenates" any number of files by writing them to standard output,
one after the other, with no break between files.
For example, the following command will display the files f1.c, f2.c, and f3.c on the screen:

fcat fl.c f2.c f3.c

fcat should issue an error message if any file can't be opened.
Hint: Since it has no more than one file open at a time, fcat needs only a single file pointer variable.
Once it's finished with a file, fcat can use the same variable when it opens the next file.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "usage: ./03 file ...\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 1; i < argc; i++)
    {
        char *filename = argv[i];
        FILE *fp = fopen(filename, "r");

        if (fp == NULL)
        {
            fprintf(stderr, "Failed to open file: %s\n", filename);
            exit(EXIT_FAILURE);
        }

        char buffer[BUFSIZ];
        size_t num_read;
        while ((num_read = fread(buffer, sizeof(char), BUFSIZ, fp)) == BUFSIZ)
        {
            if (fwrite(buffer, sizeof(char), num_read, stdout) < num_read)
            {
                fprintf(stderr, "Failed to write all bytes read from file: %s\n", filename);
                fclose(fp);
                exit(EXIT_FAILURE);
            }
        }

        if (ferror(fp))
        {
            fprintf(stderr, "Failed to read from file: %s\n", filename);
            fclose(fp);
            exit(EXIT_FAILURE);
        }

        if (fwrite(buffer, sizeof(char), num_read, stdout) < num_read)
        {
            fprintf(stderr, "Failed to write all bytes read from file: %s\n", filename);
            fclose(fp);
            exit(EXIT_FAILURE);
        }

        fclose(fp);
    }

    return 0;
}