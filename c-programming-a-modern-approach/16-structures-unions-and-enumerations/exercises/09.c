/*
Write the following functions. (The color structure is defined in 08.c)

(a) struct color make_color(int red, int green, int blue);
Returns a color structure containing the specified reg,green and blue values.
If any arguments are less than zero, the corresponding member of the struct will contain zero instead.
If any argument is greater than 255, the corresponding member of the struct will contain 255.

(b) int getRed(struct color c);
Returns the value of c's red member

(c) bool equal_color(struct color color1, struct color color2);
Returns true i the corresponding members of color1 and color2 are equal

(d) struct color brighter(struct color c);
Returns a color structure that represents a brighter version of the color c.
The structure is identical to c, except that each member has been divided by 0.7 (with the result truncated to an integer)
However, there are three special cases
(1) If all the members of c are zero, the function returns a color whose members all have the value 3
(2) If any member of c is greater than 0 but less than 3, it is replaced by 3 before division by 0.7
(3) If dividing by 0.7 causes a member to exceed 255, it is reduced to 255

(e) struct color darker(struct color c);
Returns a color structure that represents a darker version of color c. The structure is identical to c,
except that each member has been multiplied by 0.7 (with the result truncated to an integer)
*/

#include <stdbool.h>
#include <stdio.h>

#define BRIGHTNESS_FACTOR 0.7

struct color
{
    int red;
    int green;
    int blue;
};

int limit_channel(int channel)
{
    return channel < 0     ? 0
           : channel > 255 ? 255
                           : channel;
}

struct color make_color(int red, int green, int blue)
{
    return (struct color){limit_channel(red), limit_channel(green), limit_channel(blue)};
}

int getRed(struct color c)
{
    return c.red;
}

bool equal_color(struct color a, struct color b)
{
    return a.red == b.red && a.green == b.green && a.blue == b.blue;
}

struct color brighter(struct color c)
{
    if (!c.red && !c.green && !c.blue)
    {
        return (struct color){3, 3, 3};
    }

    if (c.red > 0 && c.red < 3)
    {
        c.red = 3;
    }
    if (c.green > 0 && c.green < 3)
    {
        c.green = 3;
    }
    if (c.blue > 0 && c.blue < 3)
    {
        c.blue = 3;
    }

    return (struct color){
        limit_channel(c.red / BRIGHTNESS_FACTOR),
        limit_channel(c.green / BRIGHTNESS_FACTOR),
        limit_channel(c.blue / BRIGHTNESS_FACTOR)};
}

struct color darker(struct color c)
{
    return (struct color){c.red * BRIGHTNESS_FACTOR, c.green * BRIGHTNESS_FACTOR, c.blue * BRIGHTNESS_FACTOR};
}

int main(void)
{
    struct color c = make_color(37, 300, -42);

    printf("c (r,g,b): (%d, %d, %d)\n", c.red, c.green, c.blue);
    printf("getRed(c): %d\n", getRed(c));
    printf("equal_color(c, c): %d\n", equal_color(c, c));
    printf("equal_color(c, (0,0,0)): %d\n", equal_color(c, make_color(0, 0, 0)));

    c = brighter(c);
    printf("brighter(c): (%d,%d,%d)\n", c.red, c.green, c.blue);

    struct color rule_1_c = brighter(make_color(0, 0, 0));
    printf("Rule 1 Test - brighter((0,0,0)): (%d,%d,%d)\n", rule_1_c.red, rule_1_c.green, rule_1_c.blue);

    struct color rule_2_c = brighter(make_color(0, 1, 2));
    printf("Rule 2 Test - brighter((0,1,2)): (%d,%d,%d)\n", rule_2_c.red, rule_2_c.green, rule_2_c.blue);

    struct color rule_3_c = brighter(make_color(180, 200, 255));
    printf("Rule 3 Test - brighter((180,200,255)): (%d,%d,%d)\n", rule_3_c.red, rule_3_c.green, rule_3_c.blue);

    c = darker(c);
    printf("darker(c): (%d,%d,%d)\n", c.red, c.green, c.blue);

    return 0;
}
