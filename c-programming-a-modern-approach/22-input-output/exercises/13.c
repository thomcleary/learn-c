/*
Write the following function:

int line_length(const char *filename, int n);

The function should return the length of line n in the text file whose name is filename.
(assuming that the first line in the file is line 1)
If the line doesn't exist, the function should return 0.
*/

#include <stdio.h>
#include <stdlib.h>

int line_length(const char *filename, int n)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < n; i++)
    {
        int n = fscanf(fp, "%*[^\n]\n");

        if (n == EOF)
        {
            if (feof(fp))
            {
                return 0;
            }
            else
            {
                fprintf(stderr, "Error reading file: %s\n", filename);
                fclose(fp);
                exit(EXIT_FAILURE);
            }
        }
    }

    int count = 0;
    int ch;
    while ((ch = getc(fp)) != '\n' && ch != EOF)
    {
        count++;
    }

    int error = ferror(fp);
    fclose(fp);

    if (error)
    {
        fprintf(stderr, "Error reading file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    return count;
}

int main(void)
{
    const int line = 3;
    const char *valid_filename = "13.valid.txt";
    const char *invalid_filename = "13.invalid.txt";
    const char *dne_filename = "does-not-exist";

    printf("Line %d length (%s): %d\n", line, valid_filename, line_length(valid_filename, line));
    printf("Line %d length (%s): %d\n", line, invalid_filename, line_length(invalid_filename, line));
    printf("Line %d length (%s): %d\n", line, dne_filename, line_length(dne_filename, line));

    return 0;
}
