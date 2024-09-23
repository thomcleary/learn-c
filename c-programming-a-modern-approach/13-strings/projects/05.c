/*
Write a program that adds up its command line arguments, which are assumed to be integers.
Run the program by typing

sum 8 24 62

should product the following output:

Total: 94
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    long sum = 0;

    for (int i = 1; i < argc; i++)
    {
        // `man atoi` suggests using strtol instead
        sum += strtol(argv[i], NULL, 0);
    }

    printf("Total: %ld\n", sum);

    return 0;
}