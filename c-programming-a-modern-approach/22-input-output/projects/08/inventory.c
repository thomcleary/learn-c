/* Maintains a parts database (array version) */

#include <stdbool.h>
#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} inventory[MAX_PARTS];

/**
 * Number of parts currently stored
 */
int num_parts = 0;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(void);
void restore(void);

/**
 * Prompts the user to enter an operation code,
 * then calls a function to perform the requested action.
 * Repeats until the user enters the the command `'q'`.
 * Prints an error message if the user enters an illegal code.
 */
int main(void)
{
    char code;

    for (;;)
    {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')
        {
            ; // Skips to end of line
        }

        switch (code)
        {
        case 'i':
            insert();
            break;
        case 's':
            search();
            break;
        case 'u':
            update();
            break;
        case 'p':
            print();
            break;
        case 'd':
            dump();
            break;
        case 'r':
            restore();
            break;
        case 'q':
            return 0;
        default:
            printf("Illegal code\n");
        }
        printf("\n");
    }
}

/**
 * Looks up a part number in the inventory array.
 * Returns the array index if the part number is found;
 * otherwise, returns -1.
 */
int find_part(int number)
{
    int i;

    for (i = 0; i < num_parts; i++)
    {
        if (inventory[i].number == number)
        {
            return i;
        }
    }

    return -1;
}

/**
 * Prompts the user for information about a new part and then inserts the part into the database.
 * Prints an error message and returns prematurely if the part already exists or the database is full.
 */
void insert(void)
{
    int part_number;

    if (num_parts == MAX_PARTS)
    {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(part_number) >= 0)
    {
        printf("Part already exists.\n");
        return;
    }

    inventory[num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
    num_parts++;
}

/**
 * Prompts the user to enter a part number,
 * then looks up the part in the database.
 * If the part exists, prints the name and quantity on hand;
 * if not, prints an error message.
 */
void search(void)
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);

    if (i >= 0)
    {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    }
    else
    {
        printf("Part not found.\n");
    }
}

/**
 * Prompts the user to enter a part number.
 * Prints an error message if the part doesn't exist;
 * otherwise, prompts the user to enter change in quantity on hand and updates the database.
 */
void update(void)
{
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);

    if (i >= 0)
    {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    }
    else
    {
        printf("Part not found.\n");
    }
}

/**
 * Prints a listing of all parts in the database,
 * showing the part number, part name, and quantity on hand.
 * Parts are printed n the order in which they were entered
 */
void print(void)
{
    int i;

    printf("Part Number   Part Name                  "
           "Quantity on Hand\n");

    for (i = 0; i < num_parts; i++)
    {
        printf("%7d       %-25s%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
    }
}

/**
 * Save the database in a specified file.
 */
void dump(void)
{
    if (num_parts < 1)
    {
        printf("Inventory is empty.\n");
        return;
    }

    printf("Enter name of output file: ");

    char format[BUFSIZ];
    char out_filename[BUFSIZ];

    snprintf(format, sizeof(format), "%%%zus", sizeof(out_filename) - 1);
    scanf(format, out_filename);

    FILE *fp = fopen(out_filename, "wb");
    if (fp == NULL)
    {
        fprintf(stderr, "Failed to open output file: %s\n", out_filename);
        return;
    }

    bool write_error = false;

    if (fwrite(inventory, sizeof(*inventory), num_parts, fp) != num_parts)
    {
        write_error = true;
        fprintf(stderr, "Failed writing inventory to output file: %s\n", out_filename);
    }

    fclose(fp);

    if (write_error)
    {
        int result = remove(out_filename);
        if (result != 0)
        {
            fprintf(stderr, "Failed to remove outfile: %s\n", out_filename);
        }
    }
}

/**
 * Load the database from a specified file.
 */
void restore(void)
{
    printf("Enter name of input file: ");

    char format[BUFSIZ];
    char in_filename[BUFSIZ];

    snprintf(format, sizeof(format), "%%%zus", sizeof(in_filename) - 1);
    scanf(format, in_filename);

    FILE *fp = fopen(in_filename, "rb");
    if (fp == NULL)
    {
        fprintf(stderr, "Failed to open input file: %s\n", in_filename);
        return;
    }

    struct part restored_inventory[MAX_PARTS];
    size_t num_read = fread(restored_inventory, sizeof(*inventory), MAX_PARTS, fp);

    if (num_read < MAX_PARTS && ferror(fp))
    {
        fprintf(stderr, "Failed to restore inventory from input file: %s\n", in_filename);
    }
    else
    {
        for (size_t i = 0; i < num_read; i++)
        {
            inventory[i] = restored_inventory[i];
        }
        num_parts = num_read;
    }

    fclose(fp);
}
