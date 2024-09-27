/*
The following structures are designed to store information about objects on a graphics screen:

*/

struct point
{
    int x, y;
};

struct rectangle
{
    struct point upper_left, lower_right;
};

/*
A point structure stores the x and y coordinates of a point on the screen.
A rectangle structure stores the coordinates of the upper left and lower right corners of a rectangle.
Write functions that perform the following operations on a rectangle structure r passed as an an argument:

(a) Compute the area of r

(b) Compute the center of r, returning it as a point value.
If either the x or y coordinate of the center isn't an integer, store its truncated value in the point structure.

(c) Move r by x units in the x direction and y units in the y direction, returning the modified version of r.
(x and y are additional arguments to the function)

(d) Determine whether a point p lies within r, returning true or false.
(p is an additional argument of type struct point)
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int area(struct rectangle r)
{
    return abs(r.upper_left.x - r.lower_right.x) * abs(r.upper_left.y - r.lower_right.y);
}

struct point center(struct rectangle r)
{
    return (struct point){
        .x = (r.upper_left.x + r.lower_right.x) / 2,
        .y = (r.upper_left.y + r.lower_right.y) / 2,
    };
}

struct rectangle move(struct rectangle r, int x, int y)
{
    r.upper_left.x += x;
    r.upper_left.y += y;
    r.lower_right.x += x;
    r.lower_right.y += y;

    return r;
}

bool is_within(struct rectangle r, struct point p)
{
    bool x_within = p.x >= r.upper_left.x && p.x <= r.lower_right.x;
    bool y_within = p.y >= r.upper_left.y && p.y <= r.lower_right.y;

    return x_within && y_within;
}

int main(void)
{
    struct rectangle r = {
        .upper_left = (struct point){.x = -1, .y = 0},
        .lower_right = (struct point){.x = 3, .y = 10}};

    printf("r: UL: (%d,%d), LR: (%d,%d)\n",
           r.upper_left.x, r.upper_left.y, r.lower_right.x, r.lower_right.y);

    printf("area(r): %d\n", area(r));

    struct point p = center(r);
    printf("center(r): (%d,%d)\n", p.x, p.y);

    struct rectangle r_moved = move(r, 1, 2);
    printf("move(r, 1, 2): UL: (%d,%d), LR: (%d,%d)\n",
           r_moved.upper_left.x, r_moved.upper_left.y, r_moved.lower_right.x, r_moved.lower_right.y);

    printf("is_within(r, r.upper_left): %d\n", is_within(r, r.upper_left));
    printf("is_within(r, r.lower_right): %d\n", is_within(r, r.lower_right));
    printf("is_within(r, (r.upper_left.x, r.upper_left.y - 1)): %d\n",
           is_within(r, (struct point){.x = r.upper_left.x, .y = r.upper_left.y - 1}));
    printf("is_within(r, (r.upper_left.x + 1, r.upper_left.y + 1)): %d\n",
           is_within(r, (struct point){.x = r.upper_left.x + 1, .y = r.upper_left.y + 1}));

    return 0;
}