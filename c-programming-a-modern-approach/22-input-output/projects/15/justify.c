#include <stdio.h>
#include <stdlib.h>

#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "usage: ./justify infile outfile\n");
        exit(EXIT_FAILURE);
    }

    char *in_filename = argv[1];
    char *out_filename = argv[2];

    // Just associate the files with the standard streams
    // No need to rewrite the program
    FILE *in_fp = freopen(in_filename, "r", stdin);
    if (in_fp == NULL)
    {
        fprintf(stderr, "Failed to open input file\n");
        exit(EXIT_FAILURE);
    }

    FILE *out_fp = freopen(out_filename, "w", stdout);
    if (out_fp == NULL)
    {
        fclose(in_fp);
        fprintf(stderr, "Failed to open output file\n");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LEN + 2];
    int word_len;

    clear_line();
    for (;;)
    {
        word_len = read_word(word, MAX_WORD_LEN + 1);
        if (word_len == 0)
        {
            flush_line();
            return 0;
        }
        if (word_len > MAX_WORD_LEN)
        {
            word[MAX_WORD_LEN] = '*';
        }
        if (word_len + 1 > space_remaining())
        {
            write_line();
            clear_line();
        }
        add_word(word);
    }

    fclose(in_fp);
    fclose(out_fp);

    return 0;
}