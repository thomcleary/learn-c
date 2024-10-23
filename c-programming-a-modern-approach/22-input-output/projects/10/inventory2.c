/* Maintains a parts database (linked list version) */

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "readline.h"

#define NAME_LEN 25

struct part
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part *next;
};

static const size_t part_io_size = offsetof(struct part, on_hand) + sizeof((struct part){}.on_hand);

struct part *inventory = NULL; /* points to first part */

static void free_inventory()
{
    struct part *part = inventory;
    while (part != NULL)
    {
        struct part *next = part->next;
        free(part);
        part = next;
    }
}

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(void);
void restore(void);

/**
 * Prompts the user to enter an operation code,
 * then calls a function to perform the requested action.
 * Repeats until the user enters the command 'q'.
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
 * Looks up a part number in the inventory list.
 * Returns a pointer to the node containing the part number;
 * if the part number is not found, returns NULL
 */
struct part *find_part(int number)
{
    struct part *p;

    for (p = inventory; p != NULL && number > p->number; p = p->next)
    {
        ;
    }

    if (p != NULL && number == p->number)
    {
        return p;
    }

    return NULL;
}

/**
 * Prompts the user for information about a new part and then inserts the part into the inventory list;
 * the list remains sorted by part number.
 * Prints an error message and returns prematurely if the part already exists
 * or space could not be allocated for the part.
 */
void insert(void)
{
    struct part *cur, *prev, *new_node;

    new_node = malloc(sizeof(struct part));
    if (new_node == NULL)
    {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);

    for (cur = inventory, prev = NULL; cur != NULL && new_node->number > cur->number; prev = cur, cur = cur->next)
    {
        ;
    }

    if (cur != NULL && new_node->number == cur->number)
    {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);

    new_node->next = cur;

    if (prev == NULL)
    {
        inventory = new_node;
    }
    else
    {
        prev->next = new_node;
    }
}

/**
 * Prompts the user to enter a part number,
 * then looks up the part in the database.
 * If the part exists, prints the name and quantity on hand;
 * if not, prints an error message.
 */
void search(void)
{
    int number;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL)
    {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
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
    int number, change;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL)
    {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        p->on_hand += change;
    }
    else
    {
        printf("Part not found.\n");
    }
}

/**
 * Prints a listing of all parts in the database,
 * showing the part number, part name, and quantity on hand.
 * Part numbers will appear in ascending order.
 */
void print(void)
{
    struct part *p;

    printf("Part Number   Part Name                  "
           "Quantity on Hand\n");
    for (p = inventory; p != NULL; p = p->next)
    {
        printf("%7d       %-25s%11d\n", p->number, p->name,
               p->on_hand);
    }
}

/**
 * Save the database in a specified file.
 */
void dump(void)
{
    if (inventory == NULL)
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
    struct part *part = inventory;

    while (part != NULL)
    {
        if (fwrite(part, part_io_size, 1, fp) != 1)
        {
            write_error = true;
            fprintf(stderr, "Failed writing part to output file: %s\n", out_filename);
            break;
        }

        part = part->next;
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

    struct part *new_inventory = NULL;
    struct part *previous_part = NULL;
    struct part read_part;

    while (fread(&read_part, part_io_size, 1, fp) == 1)
    {
        struct part *new_part = malloc(sizeof(*new_part));
        if (new_part == NULL)
        {
            fprintf(stderr, "Failed to malloc new part\n");
            free_inventory();
            return;
        }

        *new_part = read_part;
        new_part->next = NULL;

        if (previous_part == NULL)
        {
            new_inventory = new_part;
            previous_part = new_part;
        }
        else
        {
            previous_part->next = new_part;
            previous_part = new_part;
        }
    }

    if (ferror(fp))
    {
        fprintf(stderr, "Failed to restore inventory from input file: %s\n", in_filename);
    }
    else
    {
        free_inventory();
        inventory = new_inventory;
    }

    fclose(fp);
}