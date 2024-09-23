/*
Write a program that echoes its command-line arguments in reverse order.
Run the program by typing

./program void and null

should product the following output

null and void
*/

#include <stdio.h>

int main(int argc, char **argv)
{
    for (int i = argc - 1; i > 0; i--)
    {
        printf("%s ", argv[i]);
    }
    printf("\n");

    return 0;
}