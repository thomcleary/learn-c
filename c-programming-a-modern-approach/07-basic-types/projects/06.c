/*
Write a program that prints the values of
sizeof(int), sizeof(short), sizeof(long), sizeof(float)
sizeof(double), sizeof(long double)
*/

#include <stdio.h>

int main(void)
{
    char ch;
    short sh;
    int i;
    long lng;
    long llng;
    float flt;
    double dbl;
    long double ldbl;

    printf("sizeof(char): %zu\n", sizeof ch);
    printf("sizeof(short): %zu\n", sizeof sh);
    printf("sizeof(int): %zu\n", sizeof i);
    printf("sizeof(long): %zu\n", sizeof lng);
    printf("sizeof(long long): %zu\n", sizeof llng);
    printf("sizeof(flt): %zu\n", sizeof flt);
    printf("sizeof(double): %zu\n", sizeof dbl);
    printf("sizeof(long double): %zu\n", sizeof ldbl);

    return 0;
}