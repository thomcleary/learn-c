/* Maintains a parts database (array version) */

#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25

struct part
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

int compare_parts(const void *part_a, const void *part_b)
{
    return ((struct part *)part_a)->number - ((struct part *)part_b)->number;
}

struct inventory
{
    int max_parts;
    int num_parts;
    struct part *parts;
} inventory;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

/**
 * Prompts the user to enter an operation code,
 * then calls a function to perform the requested action.
 * Repeats until the user enters the the command `'q'`.
 * Prints an error message if the user enters an illegal code.
 */
int main(void)
{
    inventory = (struct inventory){.max_parts = 10, .num_parts = 0, .parts = NULL};

    struct part *parts = malloc(inventory.max_parts * sizeof(*parts));
    if (parts == NULL)
    {
        printf("malloc failed\n");
        exit(EXIT_FAILURE);
    }
    inventory.parts = parts;

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

    for (i = 0; i < inventory.num_parts; i++)
    {
        if (inventory.parts[i].number == number)
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

    if (inventory.num_parts == inventory.max_parts)
    {
        printf("Database is full; doubling size.\n");

        inventory.max_parts *= 2;
        struct part *temp = realloc(inventory.parts, sizeof(*(inventory.parts)) * inventory.max_parts);
        if (inventory.parts == NULL)
        {
            printf("Insufficient memory, can't add more parts\n");
            return;
        }
        inventory.parts = temp;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(part_number) >= 0)
    {
        printf("Part already exists.\n");
        return;
    }

    inventory.parts[inventory.num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory.parts[inventory.num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory.parts[inventory.num_parts].on_hand);
    inventory.num_parts++;
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
        printf("Part name: %s\n", inventory.parts[i].name);
        printf("Quantity on hand: %d\n", inventory.parts[i].on_hand);
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
        inventory.parts[i].on_hand += change;
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

    qsort(inventory.parts, inventory.num_parts, sizeof(*inventory.parts), compare_parts);

    for (i = 0; i < inventory.num_parts; i++)
    {
        printf("%7d       %-25s%11d\n", inventory.parts[i].number, inventory.parts[i].name, inventory.parts[i].on_hand);
    }
}