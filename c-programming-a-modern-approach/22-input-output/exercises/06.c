/*
Write a call to printf that prints
'1 widget'
if the widget variable (of type int) has the value 1, and
'n widgets'
otherwise, where n is the value of widget.

You are not allowed to use the if statement or any other statement;
the answer must be a single call of printf.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("usage: ./06 num_widgets\n");
        exit(EXIT_FAILURE);
    }

    int num_widgets;
    sscanf(argv[1], "%d", &num_widgets);

    printf("%d %s\n", num_widgets, num_widgets == 1 ? "widget" : "widgets");

    return 0;
}