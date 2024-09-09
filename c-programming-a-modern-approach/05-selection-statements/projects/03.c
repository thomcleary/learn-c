/*
Modify the broker.c example by making the following changes:
a) Ask the user to enter the number of shares and price per share instead of the value of the trade
b) Compute and display the commission of a rival broker
- $33 plus 3 cents per share for fewer than 2000 shares
- $33 plus 2 cents per share for 2000 shares or more
*/

#include <stdio.h>

int main(void)
{
    int shares;
    float share_value, commission, rival_commission;

    printf("Enter number of shares: ");
    scanf("%d", &shares);

    printf("Enter share value: ");
    scanf("%f", &share_value);

    float value = shares * share_value;

    // Broker's commission
    if (value < 2500.00f)
    {
        commission = 30.00f + .017f * value;
    }
    else if (value < 6250.00f)
    {
        commission = 56.00f + .0066f * value;
    }
    else if (value < 20000.00f)
    {
        commission = 76.00f + .0034f * value;
    }
    else if (value < 50000.00f)
    {
        commission = 100.00f + .0022f * value;
    }
    else
    {
        commission = 255.00f + .0009f * value;
    }

    if (commission < 39.00f)
    {
        commission = 39.00f;
    }

    // Rival broker's commission
    rival_commission = 33.00f + (shares < 2000 ? .03f : .02f) * shares;

    printf("Commision: $%.2f\n", commission);
    printf("Rival commission: $%.2f\n", rival_commission);

    return 0;
}