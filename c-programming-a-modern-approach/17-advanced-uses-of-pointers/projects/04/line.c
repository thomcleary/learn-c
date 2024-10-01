#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct line
{
    int length;
    int word_count;
    char **words;
} line = {.length = 0, .word_count = 0, .words = NULL};

void clear_line(void)
{
    for (int i = 0; i < line.word_count; i++)
    {
        char *word_to_free = line.words[i];
        free(word_to_free);
    }

    free(line.words);

    line.words = NULL;
    line.length = 0;
    line.word_count = 0;
}

void add_word(const char *word)
{
    if (line.words == NULL)
    {
        line.words = malloc(sizeof(word));
        if (line.words == NULL)
        {
            printf("add_word: line.words malloc failed\n");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        line.words = realloc(line.words, sizeof(word) * (line.word_count + 1));
        if (line.words == NULL)
        {
            printf("add_word: line.words realloc failed\n");
            exit(EXIT_FAILURE);
        }
    }

    int word_len = strlen(word);
    char *word_copy = malloc((word_len + 1) * sizeof(*word));
    if (word_copy == NULL)
    {
        printf("add_word: word_copy malloc failed\n");
        exit(EXIT_FAILURE);
    }

    strcpy(word_copy, word);
    line.words[line.word_count] = word_copy;

    line.length += word_len;
    if (line.word_count > 0)
    {
        line.length += 1; // +1 for ' ' between words
    }

    line.word_count++;
}

int space_remaining(void)
{
    return MAX_LINE_LEN - line.length;
}

void write_line(void)
{
    int extra_spaces = MAX_LINE_LEN - line.length;

    for (int i = 0; i < line.word_count; i++)
    {
        printf("%s", line.words[i]);

        int num_spaces = line.word_count - 1 - i;

        if (num_spaces > 0)
        {
            printf(" ");

            int spaces_to_insert = (extra_spaces / num_spaces);
            for (int j = 0; j < spaces_to_insert; j++)
            {
                printf(" ");
            }
            extra_spaces -= spaces_to_insert;
        }
    }
    printf("\n");
}

void flush_line(void)
{
    for (int i = 0; i < line.word_count; i++)
    {
        printf("%s", line.words[i]);
        if (i + 1 < line.word_count)
        {
            printf(" ");
        }
    }
    printf("\n");
}