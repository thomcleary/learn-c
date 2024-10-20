/*
Write calls of fseek that perform the following file positioning operations
on a binary file whose data is arranged in 64-byte "records".
Use `fp` as the file pointer in each case

(a) Move to the beginning of record n. (Assuming that the first record in the file is record 0)
(b) Move to the beginning of the last record in the file
(c) Move forward one record
(d) Move backward two records
*/

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_BYTES 64
#define N NUM_BYTES / sizeof(uint32_t)

struct SixtyFourBytes
{
    uint32_t nums[N];
};

FILE *create_data()
{
    FILE *tmp_fp = tmpfile();
    if (tmp_fp == NULL)
    {
        fprintf(stderr, "Failed to open tmp file for writing\n");
        exit(EXIT_FAILURE);
    }

    for (uint32_t i = 0; i < 10; i++)
    {
        printf("Writing 64B of %d's to tmp file\n", i);
        for (int byte = 0; byte < N; byte++)
        {
            size_t n = fwrite(&i, sizeof(uint32_t), 1, tmp_fp);
            if (n < 1)
            {
                fprintf(stderr, "Failed to write to tmp file\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    return tmp_fp;
}

void read_record(struct SixtyFourBytes *record, FILE *stream)
{
    size_t num_read = fread(record, sizeof(struct SixtyFourBytes), 1, stream);
    if (num_read < 1)
    {
        fprintf(stderr, "fread failed to read record.");
        exit(EXIT_FAILURE);
    }
}

void print_record(struct SixtyFourBytes record)
{
    printf("record: ");
    for (size_t i = 0; i < N; i++)
    {
        printf("%d", record.nums[i]);
        if (i + 1 < N)
        {
            printf(",");
        }
        else
        {
            printf("\n");
        }
    }
}

int main(void)
{
    assert(sizeof(struct SixtyFourBytes) == NUM_BYTES);

    struct SixtyFourBytes record;

    FILE *fp = create_data();

    // (b)
    printf("\n(b) Move to the beginning of the last record in the file\n");
    int seek_result = fseek(fp, -(sizeof(struct SixtyFourBytes)), SEEK_END);
    if (seek_result != 0)
    {
        fprintf(stderr, "(b): fseek returned non zero value.");
        exit(EXIT_FAILURE);
    }
    read_record(&record, fp);
    print_record(record);

    // (a)
    printf("\n(a) Move to the beginning of record n. (Assume that the first record in the file is record 0)\n");
    size_t n = 3;
    printf("n: %lu\n", n);

    seek_result = fseek(fp, n * (sizeof(struct SixtyFourBytes)), SEEK_SET);
    if (seek_result != 0)
    {
        fprintf(stderr, "(a): fseek returned non zero value.");
        exit(EXIT_FAILURE);
    }
    read_record(&record, fp);
    print_record(record);

    // (c)
    printf("\n(c) Move forward one record\n");
    seek_result = fseek(fp, (sizeof(struct SixtyFourBytes)), SEEK_CUR);
    if (seek_result != 0)
    {
        fprintf(stderr, "(c): fseek returned non zero value.");
        exit(EXIT_FAILURE);
    }
    read_record(&record, fp);
    print_record(record);

    // (d)
    printf("\n(d) Move backward two records\n");
    seek_result = fseek(fp, 2 * -(sizeof(struct SixtyFourBytes)), SEEK_CUR);
    if (seek_result != 0)
    {
        fprintf(stderr, "(d): fseek returned non zero value.");
        exit(EXIT_FAILURE);
    }
    read_record(&record, fp);
    print_record(record);

    fclose(fp);

    return 0;
}