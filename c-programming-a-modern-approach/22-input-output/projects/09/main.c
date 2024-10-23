#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25

struct part
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

struct inventory
{
    struct part *parts;
    size_t num_parts;
    size_t size;
};

struct inventory *get_inventory(char *filename);
struct inventory *merge_inventories(struct inventory *a, struct inventory *b);
void dump_inventory(struct inventory *inventory, char *filename);

static int compare_parts(const void *a, const void *b)
{
    return ((struct part *)a)->number - ((struct part *)b)->number;
}

// static void print_inventory(struct inventory *inventory)
// {
//     printf("\nInventory:\n");
//     for (size_t i = 0; i < inventory->num_parts; i++)
//     {
//         struct part part = inventory->parts[i];
//         printf("#%d %s - %d\n", part.number, part.name, part.on_hand);
//     }
// }

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        fprintf(stderr, "usage: ./main infile infile outfile\n");
        exit(EXIT_FAILURE);
    }

    struct inventory *inventory1 = get_inventory(argv[1]);
    struct inventory *inventory2 = get_inventory(argv[2]);

    struct inventory *merged_inventory = merge_inventories(inventory1, inventory2);

    free(inventory1->parts);
    free(inventory1);
    free(inventory2->parts);
    free(inventory2);

    dump_inventory(merged_inventory, argv[3]);

    free(merged_inventory->parts);
    free(merged_inventory);

    return 0;
}

struct inventory *get_inventory(char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        fprintf(stderr, "Failed to open infile: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    struct inventory *inventory = malloc(sizeof(*inventory));
    if (inventory == NULL)
    {
        fprintf(stderr, "Failed to malloc inventory for infile: %s", filename);
        exit(EXIT_FAILURE);
    }

    size_t initial_size = 1; // Keep low for testing behaviour
    struct part *parts = malloc(sizeof(*parts) * initial_size);
    if (parts == NULL)
    {
        fprintf(stderr, "Failed to malloc inventory->parts for infile: %s", filename);
        exit(EXIT_FAILURE);
    }

    inventory->parts = parts;
    inventory->size = initial_size;
    inventory->num_parts = 0;

    size_t parts_read;
    size_t inventory_space = inventory->size - inventory->num_parts;

    while ((parts_read = fread(parts, sizeof(*parts), inventory_space, fp)) == inventory_space)
    {
        inventory->parts = realloc(inventory->parts, sizeof(*(inventory->parts)) * inventory->size * 2);
        if (inventory->parts == NULL)
        {
            fprintf(stderr, "Failed to realloc inventory->parts for infile: %s", filename);
            exit(EXIT_FAILURE);
        }
        inventory->size *= 2;
        inventory->num_parts += parts_read;
        inventory_space = inventory->size - inventory->num_parts;

        parts = inventory->parts + inventory->num_parts;
    }

    inventory->num_parts += parts_read;

    bool read_error = ferror(fp);
    fclose(fp);

    if (read_error)
    {
        fprintf(stderr, "Failed to read parts from  infile: %s", filename);
        exit(EXIT_FAILURE);
    }

    return inventory;
}

struct inventory *merge_inventories(struct inventory *a, struct inventory *b)
{
    size_t merged_inventory_size = a->num_parts;
    size_t size_remaining = SIZE_MAX - merged_inventory_size;

    if (b->num_parts > size_remaining)
    {
        // obviously could actually do it, just cbf
        fprintf(stderr, "Inventories are too large to merge.\n");
        exit(EXIT_FAILURE);
    }

    merged_inventory_size += b->num_parts;

    struct inventory *merged_inventory = malloc(sizeof(*merged_inventory));
    if (merged_inventory == NULL)
    {
        fprintf(stderr, "Failed to malloc inventory for merged inventory.");
        exit(EXIT_FAILURE);
    }

    struct part *merged_parts = malloc(sizeof(*merged_parts) * merged_inventory_size);
    if (merged_parts == NULL)
    {
        fprintf(stderr, "Failed to malloc parts for merged inventory.");
        exit(EXIT_FAILURE);
    }

    merged_inventory->parts = merged_parts;
    merged_inventory->num_parts = 0;
    merged_inventory->size = merged_inventory_size;

    for (size_t i = 0; i < a->num_parts; i++)
    {
        merged_inventory->parts[i] = a->parts[i];
    }
    merged_inventory->num_parts = a->num_parts;

    for (size_t b_part_num = 0; b_part_num < b->num_parts; b_part_num++)
    {
        struct part b_part = b->parts[b_part_num];

        bool match_found = false;
        for (size_t merged_part_num = 0; merged_part_num < a->num_parts; merged_part_num++)
        {
            // Could binary search this instead of linear search, but cbf
            struct part *merged_part = &(merged_inventory->parts[merged_part_num]);

            if (b_part.number == merged_part->number)
            {
                if (strcmp(b_part.name, merged_part->name) != 0)
                {
                    fprintf(stderr, "Error: found part name conflict\n");
                    fprintf(stderr, "Part #%d - [%s]\n", merged_part->number, merged_part->name);
                    fprintf(stderr, "Part #%d - [%s]\n", b_part.number, b_part.name);
                    exit(EXIT_FAILURE);
                }

                merged_part->on_hand += b_part.on_hand;

                match_found = true;
                break;
            }
        }

        if (!match_found)
        {
            merged_inventory->parts[merged_inventory->num_parts++] = b_part;
        }
    }

    qsort(merged_inventory->parts, merged_inventory->num_parts, sizeof(*(merged_inventory->parts)), compare_parts);

    return merged_inventory;
}

void dump_inventory(struct inventory *inventory, char *filename)
{
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        fprintf(stderr, "Failed to open output file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    bool write_error = false;

    if (fwrite(inventory->parts, sizeof(*(inventory->parts)), inventory->num_parts, fp) != inventory->num_parts)
    {
        write_error = true;
        fprintf(stderr, "Failed writing merged inventory to output file: %s\n", filename);
    }

    fclose(fp);

    if (write_error)
    {
        int result = remove(filename);
        if (result != 0)
        {
            fprintf(stderr, "Failed to remove outfile: %s\n", filename);
        }
    }
}
