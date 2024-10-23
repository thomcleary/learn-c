/*
Modify Programming Project 2 from Chapter 3 so that the program reads a series of items from a file
and displays the data in columns.
Each line of the file will have the following form:

item,price,dd/mm/yyyy

Have the program obtain the file name from the command line.
*/

#include <stdio.h>
#include <stdlib.h>

struct PurchaseDate
{
    short day, month;
    short year;
};

struct Item
{
    int id;
    float price;
    struct PurchaseDate purchase_date;
};

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "usage: ./12 filename\n");
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    printf("\n%-16s%-16s%-16s\n", "Item", "Unit", "Purchase");
    printf("%-16s%-16s%-16s\n", "", "Price", "Date");

    struct Item item;

    char buffer[BUFSIZ];
    while (fgets(buffer, BUFSIZ, fp) != NULL)
    {
        sscanf(buffer, "%d,%f,%2hu/%2hu/%hu", &item.id, &item.price,
               &item.purchase_date.day, &item.purchase_date.month, &item.purchase_date.year);

        printf("%-16d$ %-14.2f%02hu/%02hu/%04hu\n", item.id, item.price,
               item.purchase_date.day, item.purchase_date.month, item.purchase_date.year);
    }

    if (ferror(fp))
    {
        fprintf(stderr, "Failed reading from input file: %s\n", filename);
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    return 0;
}