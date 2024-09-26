/*
Assume that the fraction structure contains two members: numerator and denominator (both of type int).
Write functions that perform the following operations on fractions:

(a): Reduce the fraction to lowest terms
(b) Add the fractions f1 and f2
(c) Subtract the fraction f2 from f1
(d) Multiply the fractions f1 and f2
(e) Divide the fraction f1 by the fraction f2
*/

#include <stdio.h>

struct fraction
{
    int numerator, denominator;
};

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

struct fraction reduce(struct fraction f)
{
    int common_divisor = gcd(f.numerator, f.denominator);

    return (struct fraction){
        .numerator = f.numerator / common_divisor,
        .denominator = f.denominator / common_divisor};
}

struct fraction add(struct fraction a, struct fraction b)
{
    return reduce((struct fraction){
        .numerator = (a.numerator * b.denominator) + (b.numerator * a.denominator),
        .denominator = (a.denominator * b.denominator)});
}

struct fraction subtract(struct fraction a, struct fraction b)
{
    b.numerator *= -1;
    return reduce(add(a, b));
}

struct fraction multiply(struct fraction a, struct fraction b)
{
    return reduce((struct fraction){
        .numerator = a.numerator * b.numerator,
        .denominator = a.denominator * b.denominator,
    });
}

struct fraction divide(struct fraction a, struct fraction b)
{
    struct fraction b_flipped = {.numerator = b.denominator, .denominator = b.numerator};
    return multiply(a, b_flipped);
}

int main(void)
{
    struct fraction f1 = {.numerator = 9, .denominator = 27};
    printf("f1: %d/%d\n", f1.numerator, f1.denominator);

    f1 = reduce(f1);
    printf("f1 reduced: %d/%d\n", f1.numerator, f1.denominator);

    struct fraction f2 = {.numerator = 14, .denominator = 38};
    printf("f2: %d/%d\n", f2.numerator, f2.denominator);

    f2 = add(f1, f2);
    printf("f1+f2: %d/%d\n", f2.numerator, f2.denominator);

    f1 = subtract(f2, f1);
    printf("f2-f1: %d/%d\n", f1.numerator, f1.denominator);

    struct fraction f3 = {.numerator = 3, .denominator = 2};
    printf("f3: %d/%d\n", f3.numerator, f3.denominator);

    f1 = multiply(f1, f3);
    printf("f1*f3: %d/%d\n", f1.numerator, f1.denominator);

    f1 = divide(f1, f3);
    printf("f1/f3: %d/%d\n", f1.numerator, f1.denominator);

    return 0;
}
