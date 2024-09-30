/*
Show the output of the following program and explain what it does
*/

/*
Output: "Answer: 3"

Finds the value, n, for which the function passed to f1, returns 0

In this case the function passed to f1, f2, returns 0 when n is 3
3 * 3 + 3 - 12 == 0
*/

#include <stdio.h>

int f1(int (*f)(int));
int f2(int i);

int main(void)
{
    printf("Answer: %d\n", f1(f2));
    return 0;
}

int f1(int (*f)(int))
{
    int n = 0;

    while ((*f)(n))
        n++;
    return n;
}

int f2(int i)
{
    return i * i + i - 12;
}