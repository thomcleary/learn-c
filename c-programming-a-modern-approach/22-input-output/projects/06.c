/*
Write a program that displays the contents of a file as bytes and as characters.
Have the user specify the file name on the command line.
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OFFSET "Offset"
#define BYTES "Bytes"
#define CHARACTERS "Characters"

void exit_failure(char *reason);
void print_underline(int length);
void print_heading(void);
void print_buffer(unsigned char buffer[], size_t buffer_size, size_t num_read, unsigned int offset);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        exit_failure("usage: ./06 file");
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL)
    {
        exit_failure("Failed to open input file");
    }

    print_heading();

    unsigned int offset = 0;
    const size_t buffer_size = 10;
    unsigned char buffer[buffer_size];
    size_t num_read;

    while ((num_read = fread(buffer, sizeof(char), buffer_size, fp)) == buffer_size)
    {
        print_buffer(buffer, buffer_size, num_read, offset);
        offset += 10;
    }

    bool read_error = ferror(fp);
    fclose(fp);

    if (read_error)
    {
        exit_failure("Failed to read from input file");
    }

    if (num_read > 0)
    {
        print_buffer(buffer, buffer_size, num_read, offset);
    }

    return 0;
}

void exit_failure(char *reason)
{
    fprintf(stderr, "%s\n", reason);
    exit(EXIT_FAILURE);
}

void print_underline(int length)
{
    for (int i = 0; i < length; i++)
    {
        putchar('-');
    }
}

void print_heading(void)
{
    putchar('\n');

    printf("%s  ", OFFSET);
    printf("%12s%s%12s  ", "", BYTES, "");
    printf("%s\n", CHARACTERS);

    print_underline(strlen(OFFSET));
    printf("  ");
    print_underline(12 + strlen(BYTES) + 12);
    printf("  ");
    print_underline(strlen(CHARACTERS));

    putchar('\n');
}

void print_buffer(unsigned char buffer[], size_t buffer_size, size_t num_read, unsigned int offset)
{
    printf("%*d", (int)strlen(OFFSET), offset);
    printf(" ");

    for (size_t i = 0; i < num_read; i++)
    {
        printf(" %02X", buffer[i]);
    }
    for (int i = 0; i < (buffer_size - num_read); i++)
    {
        printf("   ");
    }

    printf("  ");

    for (size_t i = 0; i < num_read; i++)
    {
        char ch = isprint(buffer[i]) ? buffer[i] : '.';
        printf("%c", ch);
    }

    putchar('\n');
}