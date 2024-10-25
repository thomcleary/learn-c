#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define FAT_BLOCK_SIZE 512
#define SOI_MARKER 0xD8FF

bool is_app0_marker(uint16_t bytes)
{
    bool first_byte = (uint8_t)(bytes) == 0xFF;
    bool second_byte = (uint8_t)(bytes >> 12) == 0xE;

    return first_byte && second_byte;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: ./recover filename\n");
        exit(EXIT_FAILURE);
    }

    char *in_filename = argv[1];

    FILE *in_fp = fopen(in_filename, "rb");

    if (in_fp == NULL)
    {
        fprintf(stderr, "Failed to open %s\n", in_filename);
        exit(EXIT_FAILURE);
    }

    FILE *out_fp;
    uint8_t bytes[FAT_BLOCK_SIZE];
    uint32_t jpegs = 0;

    while (fread(bytes, sizeof(bytes), 1, in_fp) == 1)
    {
        uint16_t soi_marker = *(uint32_t *)bytes;
        uint16_t app0_marker = *(uint32_t *)(bytes + 2);

        if (soi_marker == SOI_MARKER && is_app0_marker(app0_marker))
        {
            if (out_fp != NULL)
            {
                fclose(out_fp);
            }

            char out_filename[8];
            snprintf(out_filename, 8, "%03d.jpg", jpegs);
            printf("outfile: %s\n", out_filename);

            out_fp = fopen(out_filename, "wb");
            if (out_fp == NULL)
            {
                fprintf(stderr, "Failed to open jpeg %d for writing\n", jpegs);
                fclose(in_fp);
                exit(EXIT_FAILURE);
            }

            jpegs++;
        }

        if (out_fp != NULL && fwrite(bytes, FAT_BLOCK_SIZE, 1, out_fp) != 1)
        {
            fprintf(stderr, "Failed to write to jpeg file %d\n", jpegs - 1);
            exit(EXIT_FAILURE);
        }
    }

    bool read_error = ferror(in_fp);
    fclose(in_fp);

    if (read_error)
    {
        fprintf(stderr, "Failed to read from %s\n", in_filename);
        exit(EXIT_FAILURE);
    }

    return 0;
}