/*
(a) Show how to declare a tag named complex for a structure with two members, real and imaginary,
of type double.

(b) Use the complex tag to declare variables named c1, c2 and c3.

(c) Write a function named make_complex that stores its two arguments (both of type double)
in a complex structure, then returns the structure.

(d) Write a function named add_complex that adds the corresponding members of its arguments
(both complex structures), then returns the result (another complex structure)
*/

#include <stdio.h>

struct complex
{
    double real;
    double imaginary;
};

struct complex make_complex(double real, double imaginary)
{
    return (struct complex){.real = real, .imaginary = imaginary};
}

struct complex add_complex(struct complex i, struct complex j)
{
    return (struct complex){.real = i.real + j.real, .imaginary = i.imaginary + j.imaginary};
}

int main(void)
{
    struct complex c1, c2, c3;

    c1 = make_complex(1.0, 2.0);
    c2 = make_complex(3.0, 4.0);
    c3 = make_complex(0.0, -5.0);

    c1 = add_complex(c1, add_complex(c2, c3));

    printf("Sum: { real = %.2f, imaginary = %.2f }\n", c1.real, c1.imaginary);

    return 0;
}