/*
(a) Write a program that counts the number of characters in a text file
(b) Write a program that counts the number of words in a text file. (A word is any sequence of non-white-space characters)
(c) Write a program that counts the number of lines in a text file.

Have each program obtain the filename from the command line.
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Counts
{
    unsigned int chars, words, lines;
};

void usage(void)
{
    fprintf(stderr, "usage: ./04 -clw file\n");
    exit(EXIT_FAILURE);
}

struct Counts get_counts(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    struct Counts counts = {.chars = 0, .words = 0, .lines = 0};

    bool parsing_word = false;

    int ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        counts.chars++;

        if (isspace(ch))
        {
            if (parsing_word)
            {
                parsing_word = false;
            }

            if (ch == '\n')
            {
                counts.lines++;
            }
        }
        else
        {
            if (!parsing_word)
            {
                parsing_word = true;
                counts.words++;
            }
        }
    }

    if (ferror(fp))
    {
        fprintf(stderr, "Failed to read from file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    return counts;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        usage();
    }

    bool char_count = false, word_count = false, line_count = false;

    int opt;
    while ((opt = getopt(argc, argv, "cwl")) != -1)
    {
        switch (opt)
        {
        case 'c':
            char_count = true;
            break;
        case 'w':
            word_count = true;
            break;
        case 'l':
            line_count = true;
            break;
        default:
            usage();
        }
    }

    if (optind >= argc)
    {
        usage();
    }

    struct Counts counts = get_counts(argv[optind]);

    if (optind == 1 || char_count)
    {
        printf("Char count: %d\n", counts.chars);
    }

    if (word_count)
    {
        printf("Word count: %d\n", counts.words);
    }

    if (line_count)
    {
        printf("Line count: %d\n", counts.lines);
    }

    return 0;
}