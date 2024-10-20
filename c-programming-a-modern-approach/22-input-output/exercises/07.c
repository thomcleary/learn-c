/*
Suppose that we call scanf as follows:

n = scanf("%d%f%d", &i, &x, &j);

(i, j and n are int variables and x is a float variable)

Assuming that the input stream contains the characters shown,
give the values of i, j, n and x after the call.
In addition, indicate which characters were consumed by the call.
*/

#include <stdio.h>

int main(void)
{
    const char *format = "%d%f%d";
    const char *a = "10 20 30\n";
    const char *b = "1.0 2.0 3.0\n";
    const char *c = "0.1 0.2 0.2\n";
    const char *d = ".1 .2 .3\n";

    int i, j, n;
    float x;

    n = sscanf(a, format, &i, &x, &j);
    printf("%sn=%d, i=%d, x=%f, j=%d\n\n", a, n, i, x, j);

    n = sscanf(b, format, &i, &x, &j);
    printf("%sn=%d, i=%d, x=%f, j=%d\n\n", b, n, i, x, j);

    n = sscanf(c, format, &i, &x, &j);
    printf("%sn=%d, i=%d, x=%f, j=%d\n\n", c, n, i, x, j);

    n = sscanf(d, format, &i, &x, &j);
    printf("%sn=%d, i=%d, x=%f, j=%d\n\n", d, n, i, x, j);

    return 0;
}