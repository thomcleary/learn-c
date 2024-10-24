/*
Modify the fcopy.c program of Section 22.4 so that it uses fread and fwrite to copy
the file in blocks of 512 bytes.

(The last block may contain fewer than 512 bytes, of course)
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *source_fp, *dest_fp;

    if (argc != 3)
    {
        fprintf(stderr, "usage: fcopy source dest\n");
        exit(EXIT_FAILURE);
    }

    if ((source_fp = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((dest_fp = fopen(argv[2], "wb")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        fclose(source_fp);
        exit(EXIT_FAILURE);
    }

    size_t buffer_size = 512;
    unsigned char buffer[buffer_size];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(unsigned char), buffer_size, source_fp)) > 0)
    {
        if (fwrite(buffer, sizeof(unsigned char), bytes_read, dest_fp) != bytes_read)
        {
            fclose(source_fp);
            fclose(dest_fp);
            fprintf(stderr, "Failed to write to dest: %s\n", argv[2]);
            exit(EXIT_FAILURE);
        }
    }

    bool read_error = ferror(source_fp);
    fclose(dest_fp);
    fclose(source_fp);

    if (read_error)
    {
        fprintf(stderr, "Failed to read from source: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return 0;
}