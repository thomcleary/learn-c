/*
Let shape be the structure tag declared in 13.md.
Write functions that perform the following operations on a shape structure s passed as an argument.

(a) Compute the area of s
(b) Move s by x units in the x direction and y units in the y direction, returning the modified version of s.
(c) Scale s by a factor of c (a double value), returning the modified version of s.
*/

#include <stdio.h>
#include <math.h>

#define RECTANGLE 1
#define CIRCLE 2

struct point
{
    int x, y;
};

struct shape
{
    int shape_kind; /* RECTANGLE or CIRCLE */
    struct point center;
    union
    {
        struct
        {
            int height, width;
        } rectangle;
        struct
        {
            int radius;
        } circle;
    } u;
};

double area(struct shape s)
{
    if (s.shape_kind == RECTANGLE)
    {
        return s.u.rectangle.height * s.u.rectangle.width;
    }

    return M_PI * (s.u.circle.radius * s.u.circle.radius);
}

struct shape move(struct shape s, int dx, int dy)
{
    s.center.x += dx;
    s.center.y += dy;

    return s;
}

struct shape scale(struct shape s, double c)
{
    if (s.shape_kind == RECTANGLE)
    {
        s.u.rectangle.width *= c;
        s.u.rectangle.height *= c;
    }
    else
    {
        s.u.circle.radius *= c;
    }

    return s;
}

int main(void)
{
    struct shape s_rect = {
        .shape_kind = RECTANGLE,
        .center = {.x = 2, .y = 3},
        .u = {.rectangle = {.width = 4, .height = 3}},
    };

    struct shape s_circle = {
        .shape_kind = CIRCLE,
        .center = {.x = 2, .y = 3},
        .u = {.circle = {.radius = 3}},
    };

    printf("area(s_rect): [%.2lf]\n", area(s_rect));
    printf("area(s_circle): [%.2lf]\n", area(s_circle));

    s_rect = move(s_rect, 1, 2);
    printf("move(s_rect, 1, 2): center=(%d,%d)\n", s_rect.center.x, s_rect.center.y);

    s_circle = move(s_circle, -1, -2);
    printf("move(s_circle, -1, -2): center=(%d,%d)\n", s_circle.center.x, s_circle.center.y);

    s_rect = scale(s_rect, 2.5);
    printf("scale(s_rect, 2.5): height=%d, width=%d\n", s_rect.u.rectangle.height, s_rect.u.rectangle.width);

    s_circle = scale(s_circle, 0.5);
    printf("scale(s_circle, 0.5): radius=%d\n", s_circle.u.circle.radius);

    return 0;
}