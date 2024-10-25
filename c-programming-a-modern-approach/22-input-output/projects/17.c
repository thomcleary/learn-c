/*
Write a program that reads a series of phone numbers from a file and displays them in a
standard format.

Each line of the file will contain a single phone number, but the numbers
may be in a variety of formats.

You may assume that each line contains 10 digits, possibly
mixed with other characters (which should be ignored).

For example, suppose that the file contains the following lines:

404.817.6900
(215) 686-1776
312-746-6000
877 275 5273
6173434200

The output of the program should have the following appearance:

(404) 817-6900
(215) 686-1776
(312) 746-6000
(877) 275-5273
(617) 343-4200

Have the program obtain the file name from the command line
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_DIGITS 10

void print_phonenumber(char digits[NUM_DIGITS])
{
    putchar('(');
    for (size_t i = 0; i < 3; i++)
    {
        putchar(digits[i]);
    }
    putchar(')');
    putchar(' ');
    for (size_t i = 3; i < 6; i++)
    {
        putchar(digits[i]);
    }
    putchar('-');
    for (size_t i = 6; i < NUM_DIGITS; i++)
    {
        putchar(digits[i]);
    }
    putchar('\n');
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "usage: ./17 filename\n");
        exit(EXIT_FAILURE);
    }

    char *in_filename = argv[1];
    FILE *fp = fopen(in_filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Failed to open input file: %s\n", in_filename);
        exit(EXIT_FAILURE);
    }

    char digits[NUM_DIGITS];
    unsigned int num_digits = 0;

    int ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        if (isdigit(ch))
        {
            if (num_digits == NUM_DIGITS)
            {
                fprintf(stderr, "Invalid phone number\n");
                exit(EXIT_FAILURE);
            }

            digits[num_digits++] = ch;
        }

        if (ch == '\n')
        {
            print_phonenumber(digits);
            num_digits = 0;
        }
    }

    bool read_error = ferror(fp);
    fclose(fp);

    if (read_error)
    {
        fprintf(stderr, "Failed to read from input file: %s", in_filename);
        exit(EXIT_FAILURE);
    }

    if (num_digits == NUM_DIGITS)
    {
        print_phonenumber(digits);
    }
    else if (num_digits != 0)
    {
        fprintf(stderr, "Final phone number is invalid\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}