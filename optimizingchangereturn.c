#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_change(void);

int main(void)
{
    float change = get_change();
    //Converting dollars into cent value
    int cents = round(change * 100);
    int coins = 0;
    //Determining number of quarters
    if (cents % 25 == 0)
    {
        int q = (cents / 25);
        coins = q;
    }
    else
    {
        int q = round(cents / 25);
        cents = cents - (q * 25);
        //Determining number of dimes
        if (cents % 10 == 0)
        {
            int d = (cents / 10);
            coins = q + d;
        }
        else
        {
            int d = round(cents / 10);
            cents = cents - (d * 10);
            //Determining number of nickels and pennies
            if (cents % 5 == 0)
            {
                int n = (cents / 5);
                coins = q + d + n;
            }
            //Notice that pennies have a 1 value so there's no need to check for remainder since anything divided by 1 will equal itself, i.e 1 cent is 1 coin
            else 
            {
                int n = round(cents / 5);
                cents = cents - (n * 5);
                coins = q + d + n + cents;
            }
        }
    }
    printf("%i\n", coins);
}
//Prompt user for change owed, can't be negative
float get_change(void)
{
    float c;
    do
    {
        c = get_float("Change owed: ");
    }
    while (c < 0.00);
    return c;
}
