/*
Write a program that converts all letters in a file to upper case.
(Characters other than letters shouldn't be changed.)
The program should obtain the file name from the command line and write its output to stdout.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "usage: ./02 filename\n");
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Failed to open file: [%s]\n", filename);
        exit(EXIT_FAILURE);
    }

    char ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        putchar(toupper(ch));
    }
    fclose(fp);

    if (ferror(fp))
    {
        fprintf(stderr, "Failed to read from file: [%s]\n", filename);
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}