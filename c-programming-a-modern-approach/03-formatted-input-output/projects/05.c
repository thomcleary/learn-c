/*
Write a program that asks the user to enter the numbers from 1 to 16 (in any order)
and then displays the numbers in a 4 by 4 arrangement,
followed by the sums of the rows, columns, and diagonals
*/

#include <stdio.h>

int main(void)
{
       int a, b, c, d;
       int e, f, g, h;
       int i, j, k, l;
       int m, n, o, p;

       printf("Enter the numbers from 1 to 16 in any order:\n");
       scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &o, &p);

       printf("\n");
       printf("%3d%3d%3d%3d\n", a, b, c, d);
       printf("%3d%3d%3d%3d\n", e, f, g, h);
       printf("%3d%3d%3d%3d\n", i, j, k, l);
       printf("%3d%3d%3d%3d\n", m, n, o, p);
       printf("\n");

       printf("Row sums: %d %d %d %d\n",
              a + b + c + d,
              e + f + g + h,
              i + j + k + l,
              m + n + o + p);

       printf("Column sums: %d %d %d %d\n",
              a + e + i + m,
              b + f + j + n,
              c + g + k + o,
              d + h + l + p);

       printf("Diagonal sums: %d %d\n",
              a + f + k + p,
              d + g + j + m);

       return 0;
}