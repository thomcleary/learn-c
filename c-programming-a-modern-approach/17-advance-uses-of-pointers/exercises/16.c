/*
Write the following function.
The call

sum(g, i, j)

should return g(i) + ... + g(j)

int sum(int (*f)(int), int start, int end);
*/

#include <stdio.h>

int sum(int (*f)(int), int start, int end)
{
    int total = 0;

    for (int i = start; i <= end; i++)
    {
        total += f(i);
    }

    return total;
}

int add_one(int i)
{
    return i + 1;
}

int square(int i)
{
    return i * i;
}

int cube(int i)
{
    return i * i * i;
}

int main(void)
{
    printf("sum(square, 1, 5): [%d]\n", sum(square, 1, 5));
    printf("sum(cube, 1, 5): [%d]\n", sum(cube, 1, 5));
    printf("sum(add_one, 1, 5): [%d]\n", sum(add_one, 1, 5));

    return 0;
}