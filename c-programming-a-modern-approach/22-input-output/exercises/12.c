/*
Find the error in the following function and show how to fix it
*/

#include <stdio.h>

int count_periods(const char *filename)
{
    FILE *fp;
    int n = 0;

    if ((fp = fopen(filename, "r")) != NULL)
    {
        // This call to fgetc may read '.' and never put back
        // (skips counting periods)
        while (fgetc(fp) != EOF)
        {
            if (fgetc(fp) == '.')
            {
                n++;
            }
        }
        fclose(fp);
    }
    return n;
}

int count_periods_fixed(const char *filename)
{
    FILE *fp;
    int n = 0;

    if ((fp = fopen(filename, "r")) != NULL)
    {
        char ch;
        while ((ch = fgetc(fp)) != EOF)
        {
            if (ch == '.')
            {
                n++;
            }
        }
        fclose(fp);
    }
    return n;
}

int main(void)
{
    const char *filename = "12.txt";

    printf("Periods in %s: %d\n", filename, count_periods(filename));
    printf("Periods in %s: %d (fixed)\n", filename, count_periods_fixed(filename));

    return 0;
}