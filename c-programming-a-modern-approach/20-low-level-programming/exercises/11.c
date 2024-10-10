#include <stdio.h>

/*
Each of the following macros defines the position of a single bit within an integer:
*/

#define SHIFT_BIT 1
#define CTRL_BIT 2
#define ALT_BIT 4

/*
The following statement is supposed to test whether an of the three bits have been set,
but it never displays the specified message.

if (key_code & (SHIFT_BIT | CTRL_BIT | ALT_BIT) == 0)
{
    printf("No modifier keys pressed\n");
}

Explain why the statement doesn't work and show how to fix it.
Assume the that key_code is an int variable
*/

void test(int key_code)
{
    // '==' has a high precedence than '&' and will be evaluated first
    // The result of '(SHIFT_BIT | CTRL_BIT | ALT_BIT)) == 0' is 0 (false)
    // keycode & 0 will always result in 0(false)
    //
    // Solution: put brackets around (key_code & (a | b |c)) so that '&' is evaluated before '=='
    if ((key_code & (SHIFT_BIT | CTRL_BIT | ALT_BIT)) == 0)
    {
        printf("No modifier keys pressed\n");
    }
    else
    {
        printf("A modifier key is pressed\n");
    }
}

int main(void)
{
    for (int i = 0; i < 9; i++)
    {
        printf("test(%d): ", i);
        test(i);
        printf("\n");
    }

    return 0;
}
