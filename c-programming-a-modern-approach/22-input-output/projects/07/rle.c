#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rle.h"

char *rlencode(char *filename)
{
    FILE *in_fp = fopen(filename, "rb");
    if (in_fp == NULL)
    {
        fprintf(stderr, "Failed to open input file: %s", filename);
        return NULL;
    }

    char *out_filename = malloc(strlen(filename) + strlen(".rle") + 1);
    if (out_filename == NULL)
    {
        fclose(in_fp);
        fprintf(stderr, "Failed to malloc output filename");
        return NULL;
    }

    strcpy(out_filename, filename);
    strcat(out_filename, ".rle");

    FILE *out_fp = fopen(out_filename, "wb");
    if (out_fp == NULL)
    {
        fclose(in_fp);
        fprintf(stderr, "Failed to open output file: %s", out_filename);
        return NULL;
    }

    unsigned int run_length = 1;
    int prev_byte = fgetc(in_fp);
    int byte;

    while ((byte = fgetc(in_fp)) != EOF)
    {
        if (byte == prev_byte)
        {
            run_length++;
        }
        else
        {
            if (fputc(run_length, out_fp) == EOF || fputc(prev_byte, out_fp) == EOF)
            {
                fclose(in_fp);
                fclose(out_fp);
                fprintf(stderr, "Failed to write to output file: %s\n", out_filename);
                return NULL;
            }

            run_length = 1;
        }

        prev_byte = byte;
    }

    if (fputc(run_length, out_fp) == EOF || fputc(prev_byte, out_fp) == EOF)
    {
        fclose(in_fp);
        fclose(out_fp);
        fprintf(stderr, "Failed to write to output file: %s\n", out_filename);
        return NULL;
    }

    bool read_error = ferror(in_fp);
    fclose(in_fp);
    fclose(out_fp);

    if (read_error)
    {
        fprintf(stderr, "Failed to read from input file: %s", filename);
        return NULL;
    }

    return out_filename;
}

char *rldecode(char *filename)
{
    // TODO: validate filename ends in .rle
    // show error message and return NULL if it does not
    return NULL;
}