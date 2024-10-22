#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rle.h"

#define RLE_EXTENSION ".rle"

char *rlencode(char *filename)
{
    FILE *in_fp = fopen(filename, "rb");
    if (in_fp == NULL)
    {
        fprintf(stderr, "Failed to open input file: %s\n", filename);
        return NULL;
    }

    char *out_filename = malloc(strlen(filename) + strlen(".rle") + 1);
    if (out_filename == NULL)
    {
        fclose(in_fp);
        fprintf(stderr, "Failed to malloc output filename\n");
        return NULL;
    }

    strcpy(out_filename, filename);
    strcat(out_filename, ".rle");

    FILE *out_fp = fopen(out_filename, "wb");
    if (out_fp == NULL)
    {
        fclose(in_fp);
        fprintf(stderr, "Failed to open output file: %s\n", out_filename);
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
        fprintf(stderr, "Failed to read from input file: %s\n", filename);
        return NULL;
    }

    return out_filename;
}

/**
 * @returns the original filename of a filename with the '.rle' extension,
 * otherwise NULL
 */
static char *get_original_filename(char *rle_filename)
{
    size_t rle_filename_len = strlen(rle_filename);
    size_t rle_extension_len = strlen(RLE_EXTENSION);

    if (rle_filename_len < rle_extension_len + 1)
    {
        return NULL;
    }

    int rle_extension_index = rle_filename_len - rle_extension_len;

    if (strcmp(rle_filename + rle_extension_index, RLE_EXTENSION) != 0)
    {
        return NULL;
    }

    return strndup(rle_filename, rle_extension_index);
}

char *rldecode(char *filename)
{
    char *out_filename = get_original_filename(filename);
    if (out_filename == NULL)
    {
        fprintf(stderr, "File must have extension .rle\n");
        return NULL;
    }

    FILE *in_fp = fopen(filename, "rb");
    if (in_fp == NULL)
    {
        fprintf(stderr, "Failed to open input file: %s\n", filename);
        return NULL;
    }

    FILE *out_fp = fopen(out_filename, "wb");
    if (out_fp == NULL)
    {
        fclose(in_fp);
        fprintf(stderr, "Failed to open output file: %s\n", out_filename);
        return NULL;
    }

    int run_length, byte;
    while ((run_length = fgetc(in_fp)) != EOF && (byte = fgetc(in_fp)) != EOF)
    {
        unsigned char bytes[run_length];
        for (size_t i = 0; i < run_length; i++)
        {
            bytes[i] = byte;
        }

        if (fwrite(bytes, sizeof(unsigned char), run_length, out_fp) < run_length)
        {
            fclose(in_fp);
            fclose(out_fp);
            fprintf(stderr, "Failed to write all bytes to output file: %s\n", out_filename);
            return NULL;
        }
    }

    bool read_error = ferror(in_fp);
    fclose(in_fp);
    fclose(out_fp);

    if (read_error)
    {
        fprintf(stderr, "Failed to read from input file: %s\n", filename);
        return NULL;
    }

    return out_filename;
}