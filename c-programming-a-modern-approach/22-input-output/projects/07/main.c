#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "rle.h"

#define USAGE "usage: ./main [-d] file"

void exit_failure(char *reason);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        exit_failure(USAGE);
    }

    bool decode = false;

    int opt;
    while ((opt = getopt(argc, argv, "d")) != -1)
    {
        switch (opt)
        {
        case 'd':
            decode = true;
            break;
        default:
            exit_failure(USAGE);
        }
    }

    if (optind >= argc)
    {
        exit_failure(USAGE);
    }

    char *filename = argv[optind];
    char *out_filename = decode ? rldecode(filename) : rlencode(filename);

    if (out_filename == NULL)
    {
        exit_failure(decode ? "Failed to decode file" : "Failed to encode file");
    }

    return 0;
}

void exit_failure(char *reason)
{
    fprintf(stderr, "%s\n", reason);
    exit(EXIT_FAILURE);
}