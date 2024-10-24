/*
Modify Programming Project 15 from Chapter 8 so that the program prompts the user to
enter the name of a file containing the message to be encrypted:

Enter name of file to be encrypted: message.txt
Enter shift amount (1-25): 3

The program then writes the encrypted message to a file with the same name but an added
extension of .enc. In this example, the original file name is message.txt, so the
ecrypted message will be stored in a file named message.txt.enc. There's no limit on
the size of the file to be encrypted or on the length of each line in the file.
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCODE_EXTENSION ".enc"

int main(void)
{
    const size_t encode_extension_length = strlen(ENCODE_EXTENSION);
    const size_t in_filename_size = FILENAME_MAX - encode_extension_length;
    char in_filename[in_filename_size];

    printf("Enter name of file to be encrypted: ");
    if (fgets(in_filename, in_filename_size, stdin) == NULL)
    {
        fprintf(stderr, "Failed to read filename\n");
        exit(EXIT_FAILURE);
    }

    in_filename[strcspn(in_filename, "\n")] = '\0';
    const size_t in_filename_length = strlen(in_filename);

    unsigned char shift_amount;
    printf("Enter shift amount (1-25): ");
    scanf(" %2hhu", &shift_amount);

    FILE *in_fp = fopen(in_filename, "rb");
    if (in_fp == NULL)
    {
        fprintf(stderr, "Failed to open input file: %s\n", in_filename);
        exit(EXIT_FAILURE);
    }

    char out_filename[in_filename_length + encode_extension_length + 1];
    strncpy(out_filename, in_filename, in_filename_length + 1);
    strncat(out_filename, ENCODE_EXTENSION, encode_extension_length);

    FILE *out_fp = fopen(out_filename, "wb");
    if (out_fp == NULL)
    {
        fclose(in_fp);
        fprintf(stderr, "Failed to open output file: %s\n", out_filename);
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(in_fp)) != EOF)
    {
        bool write_error = false;

        if (isalpha(ch))
        {
            char a_ch = isupper(ch) ? 'A' : 'a';
            write_error = fputc((((ch - a_ch) + shift_amount) % 26) + a_ch, out_fp) == EOF;
        }
        else
        {
            write_error = fputc(ch, out_fp) == EOF;
        }

        if (write_error)
        {
            fclose(in_fp);
            fclose(out_fp);
            fprintf(stderr, "Failed to write to output file %s\n", out_filename);

            if (remove(out_filename) != 0)
            {
                fprintf(stderr, "Failed to remove output file: %s\n", out_filename);
            }

            exit(EXIT_FAILURE);
        }
    }

    bool read_error = ferror(in_fp);
    fclose(in_fp);
    fclose(out_fp);

    if (read_error)
    {
        fprintf(stderr, "Failed to read from input file: %s\n", in_filename);

        if (remove(out_filename) != 0)
        {
            fprintf(stderr, "Failed to remove output file: %s\n", out_filename);
        }

        exit(EXIT_FAILURE);
    }

    return 0;
}