/*
Maintains a parts database (array version)

Project 2: Modify the inventory.c program so that the p (print) operation displays the parts by part number

Project 3: Modify the inventory.c program by making inventory and num_parts local to the main function

Project 4: Modify the inventory.c program by adding a price member to the part structure.
The insert function should ask the user for the price of a new item.
The search and print functions should display the price.
Add a new command that allows the user to change the price of a part.
*/

#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    double price;
};

int compare_part(const void *a, const void *b)
{
    return ((struct part *)a)->number - ((struct part *)b)->number;
}

int find_part(int number, struct part inventory[], int num_parts);
void insert(struct part inventory[], int *num_parts);
void search(struct part inventory[], int num_parts);
void update_quantity(struct part inventory[], int num_parts);
void update_price(struct part inventory[], int num_parts);
void print(struct part inventory[], int num_parts);

/**
 * Prompts the user to enter an operation code,
 * then calls a function to perform the requested action.
 * Repeats until the user enters the the command `'q'`.
 * Prints an error message if the user enters an illegal code.
 */
int main(void)
{
    struct part inventory[MAX_PARTS];
    int num_parts = 0;

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
            insert(inventory, &num_parts);
            break;
        case 's':
            search(inventory, num_parts);
            break;
        case 'u':
            update_quantity(inventory, num_parts);
            break;
        case '$':
            update_price(inventory, num_parts);
            break;
        case 'p':
            print(inventory, num_parts);
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
int find_part(int number, struct part inventory[], int num_parts)
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
void insert(struct part inventory[], int *num_parts)
{
    int part_number;

    if (*num_parts == MAX_PARTS)
    {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(part_number, inventory, *num_parts) >= 0)
    {
        printf("Part already exists.\n");
        return;
    }

    inventory[*num_parts].number = part_number;

    printf("Enter part name: ");
    read_line(inventory[*num_parts].name, NAME_LEN);

    printf("Enter price: $");
    scanf(" %lf", &inventory[*num_parts].price);

    printf("Enter quantity on hand: ");
    scanf(" %d", &inventory[*num_parts].on_hand);

    *num_parts += 1;
}

/**
 * Prompts the user to enter a part number,
 * then looks up the part in the database.
 * If the part exists, prints the name and quantity on hand;
 * if not, prints an error message.
 */
void search(struct part inventory[], int num_parts)
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, inventory, num_parts);

    if (i >= 0)
    {
        printf("Part name: %s\n", inventory[i].name);
        printf("Price: $%.2lf\n", inventory[i].price);
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
void update_quantity(struct part inventory[], int num_parts)
{
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, inventory, num_parts);

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

void update_price(struct part inventory[], int num_parts)
{
    int i, number;
    double new_price;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, inventory, num_parts);

    if (i >= 0)
    {
        printf("Enter new price: $");
        scanf("%lf", &new_price);
        inventory[i].price = new_price;
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
void print(struct part inventory[], int num_parts)
{
    int i;
    struct part sorted_inventory[num_parts];

    for (i = 0; i < num_parts; i++)
    {
        sorted_inventory[i] = inventory[i];
    }

    qsort(sorted_inventory, num_parts, sizeof(struct part), compare_part);

    printf("Part Number   Part Name                "
           "Price       Quantity on Hand\n");

    for (i = 0; i < num_parts; i++)
    {
        printf("%7d       %-25s$%.2lf%11d\n",
               sorted_inventory[i].number, sorted_inventory[i].name,
               sorted_inventory[i].price, sorted_inventory[i].on_hand);
    }
}