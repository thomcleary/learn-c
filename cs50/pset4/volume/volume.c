// Modifies the volume of an audio file
// https://github.com/cs50/problems/tree/2024/x/volume

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

void cleanup(FILE *in_fp, FILE *out_fp, char *out_filename)
{
    fclose(in_fp);
    fclose(out_fp);
    if (remove(out_filename) != 0)
    {
        fprintf(stderr, "Failed to remove output file [%s]\n", out_filename);
    }
}

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    char *in_filename = argv[1];
    char *out_filename = argv[2];

    // Open files and determine scaling factor
    FILE *input = fopen(in_filename, "r");
    if (input == NULL)
    {
        printf("Could not open input file [%s]\n", in_filename);
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen(out_filename, "w");
    if (output == NULL)
    {
        printf("Could not open output file [%s]\n", out_filename);
        fclose(input);
        exit(EXIT_FAILURE);
    }

    double factor = atof(argv[3]);

    // Copy header from input file to output file
    uint8_t header[HEADER_SIZE];
    if (fread(header, sizeof(header), 1, input) != 1)
    {
        fprintf(stderr, "Failed to read input file [%s]'s header\n", in_filename);
        cleanup(input, output, out_filename);
        exit(EXIT_FAILURE);
    }

    if (fwrite(header, sizeof(*header), HEADER_SIZE, output) != HEADER_SIZE)
    {
        fprintf(stderr, "Failed to write header to output file [%s]\n", out_filename);
        cleanup(input, output, out_filename);
        exit(EXIT_FAILURE);
    }

    // Read samples from input file and write updated data to output file
    int16_t sample;
    while (fread(&sample, sizeof(sample), 1, input) == 1)
    {
        int16_t new_sample = sample * factor;
        if (fwrite(&new_sample, sizeof(new_sample), 1, output) != 1)
        {
            fprintf(stderr, "Failed to write sample to output file [%s]\n", out_filename);
            cleanup(input, output, out_filename);
            exit(EXIT_FAILURE);
        }
    }

    if (ferror(input))
    {
        fprintf(stderr, "Failed to read from input file [%s]\n", in_filename);
        cleanup(input, output, out_filename);
        exit(EXIT_FAILURE);
    }

    // Close files
    fclose(input);
    fclose(output);

    return 0;
}
