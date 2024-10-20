/*
Assume that str is a string that contains a "sales rank" immediately preceded by the # symbol
(other characters may precede the # and/or folow the sales rank).
A sales rank is a series of decimal digits possibly containing commas, such as the following examples:

989
24,675
1,162,620

Write a call of scanf that extracts the sales rank (but not the # symbol)
and stores it in a string variable named sales_rank.
*/

#include <stdio.h>

int main(void)
{
    char extract[BUFSIZ];
    char *rank;

    const char *rank_fstring = "%*[^#]#%[,0123456789]";

    rank = "abc#989cba";
    printf("Rank: %s\n", rank);
    sscanf(rank, rank_fstring, extract);
    printf("Extract: %s\n\n", extract);

    rank = "abc#24,675cba";
    printf("Rank: %s\n", rank);
    sscanf(rank, rank_fstring, extract);
    printf("Extract: %s\n\n", extract);

    rank = "abc#1,162,620cba";
    printf("Rank: %s\n", rank);
    sscanf(rank, rank_fstring, extract);
    printf("Extract: %s\n", extract);

    return 0;
}