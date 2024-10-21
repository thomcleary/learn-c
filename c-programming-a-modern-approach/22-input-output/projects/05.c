/*
The xor.c program of Section 20.1 refuses to encrypt bytes that,
in original or encrypted form, are control characters.
We can now remove this restriction.
Modify the program so that the names of the input and output files are command line arguments.
Open both files in binary mode, and remove the test that checks whether the original and encrypted characters are printing characters.
*/

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

void exit_failure(char *reason)
{
    fprintf(stderr, "%s\n", reason);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        exit_failure("usage: ./05 infile outfile");
    }

    FILE *in_fp = fopen(argv[1], "rb");
    if (in_fp == NULL)
    {
        exit_failure("Failed to open infile");
    }

    FILE *out_fp = fopen(argv[2], "wb");
    if (out_fp == NULL)
    {
        fclose(in_fp);
        exit_failure("Failed to open outfile");
    }

    int orig_char;

    while ((orig_char = fgetc(in_fp)) != EOF)
    {
        int new_char = orig_char ^ KEY;

        if (fputc(new_char, out_fp) == EOF)
        {
            fclose(in_fp);
            fclose(out_fp);
            exit_failure("Failed to write to outfile");
        }
    }

    bool read_error = ferror(in_fp);
    fclose(in_fp);
    fclose(out_fp);

    if (read_error)
    {
        exit_failure("Failed to read from infile");
    }

    return 0;
}