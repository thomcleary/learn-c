/*
Write a program that declares the s structure (see section 21.4)
and prints the sizes and offsets of a, b and c members.
(Use sizeof to find sizes; use offsetof to find offsets).
Have the program print the size of the entire structure as well.
From this information, determine whether or not the structure has any holes.
If it does, describe the location and size of each.
*/

#include <stddef.h>
#include <stdio.h>

struct s
{
    char a;
    int b[2];
    float c;
};

int main(void)
{
    struct s s_instance;

    printf("struct s\n");
    printf("size  : %02luB\n\n", sizeof(struct s));

    printf("s.a\n");
    printf("size  : %02luB\n", sizeof(s_instance.a));
    printf("offset: %02luB\n\n", offsetof(struct s, a));

    printf("s.b\n");
    printf("size  : %02luB\n", sizeof(s_instance.b));
    printf("offset: %02luB\n\n", offsetof(struct s, b));

    printf("s.c\n");
    printf("size  : %02luB\n", sizeof(s_instance.c));
    printf("offset: %02luB\n", offsetof(struct s, c));

    return 0;
}

/*
Output
```
struct s
size  : 16B

s.a
size  : 01B
offset: 00B

s.b
size  : 08B
offset: 04B

s.c
size  : 04B
offset: 12B
```

From the above we can see that yes the structure does have holes.
The total sum of bytes from the size of the member is 13B.
Where as the size of the structure is 16B.
This means there are 3B of hole.

There is a single hole between a and b of size 3B:

B
00 a
01 HOLE
02 HOLE
03 HOLE
04 b[0]
05 b[0]
06 b[0]
07 b[0]
08 b[1]
09 b[1]
10 b[1]
11 b[1]
12 c
13 c
14 c
15 c
*/