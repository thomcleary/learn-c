/*
Show how each of the following numbers will look if displayed by printf with
%#012.5g
as the conversion specification:

(a) 83.7361
(b) 29748.6607
(c) 1054932234.0
(d) 0.0000235218
*/

#include <stdio.h>

int main(void)
{
    char fstring[] = "(%c): %#012.5g\n";

    printf(fstring, 'a', 83.7361);
    printf(fstring, 'b', 29748.6607);
    printf(fstring, 'c', 1054932234.0);
    printf(fstring, 'd', 0.0000235218);

    return 0;
}