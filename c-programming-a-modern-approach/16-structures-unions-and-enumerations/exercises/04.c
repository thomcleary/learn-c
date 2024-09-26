/*
Repeat 03.c, but this time using a type named Complex
*/

#include <stdio.h>

typedef struct
{
    double real;
    double imaginary;
} Complex;

Complex make_complex(double real, double imaginary)
{
    return (Complex){.real = real, .imaginary = imaginary};
}

Complex add_complex(Complex i, Complex j)
{
    return (Complex){.real = i.real + j.real, .imaginary = i.imaginary + j.imaginary};
}

int main(void)
{
    Complex c1, c2, c3;

    c1 = make_complex(1.0, 2.0);
    c2 = make_complex(3.0, 4.0);
    c3 = make_complex(0.0, -5.0);

    c1 = add_complex(c1, add_complex(c2, c3));

    printf("Sum: { real = %.2f, imaginary = %.2f }\n", c1.real, c1.imaginary);

    return 0;
}