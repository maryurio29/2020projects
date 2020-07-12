#include <stdio.h>
#include <cs50.h>

long get_number(void);

int main(void)
{
    long ccNumber = get_number();
    long ccNumbermod = ccNumber;
    int sum = 0;
    int length = 0;
    long divisor = 10;
    //Adding alternate digits starting from second to last multiplied by 2
    ccNumbermod = ccNumber / 10;
    while (ccNumbermod > 0)
    {
        int lastDigit = ccNumbermod % 10;
        int timesTwo = lastDigit * 2;
        sum = sum + (timesTwo % 10) + (timesTwo / 10);
        ccNumbermod = ccNumbermod / 100; //To move two places
    }
    //Reset to original CC number
    ccNumbermod = ccNumber;
    //Adding alternate digits starting from last digit
    while (ccNumbermod > 0)
    {
        int lastDigit = ccNumbermod % 10;
        sum = sum + lastDigit;
        ccNumbermod = ccNumbermod / 100; //To move two places
    }
    //To get the length of CC number
    ccNumbermod = ccNumber;
    while (ccNumbermod != 0)
    {
        ccNumbermod = ccNumbermod / 10;
        length++; //Length of CC increments by 1
    }
    //To get the first and second digit of card we must divide the CC number a certain amount of times by 10 to move towards the left of the number
    for (int i = 0; i < length - 2; i++)
    {
        divisor = divisor * 10; //The divisor is multiplied by 10 as we iterate through the CC number
    }
    int firstDigit = ccNumber / divisor; //Divide the CC number by the amount of 10s previously calculated
    int firstTwoDigits = ccNumber / (divisor / 10); 
    //Again dividing by the divisor previously calculated except moving one space to the right for first 2 digits
    if (sum % 10 == 0) //Check for luhn's 
    {
        if ((firstTwoDigits == 34 || firstTwoDigits == 37) && length == 15) //AMEX structure starts with 34 or 37 and 15 digits long
        {
            printf("AMEX\n");
        }
        else if ((50 < firstTwoDigits && firstTwoDigits < 56) && length == 16) 
//MASTERCARD structure starts with 51 through 55 and 16 digits long
        {
            printf("MASTERCARD\n");
        }
        else if (firstDigit == 4 && (length == 13 || length == 16)) //VISA structure starts with 4 and 13 or 16 digits long
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n"); //It's not a valid AMEX, MASTERCARD or VISA CC number
        }
    }
    else
    {
        printf("INVALID\n"); //Fails luhn's, it is not a valid CC number
    }
}
//Prompt user for card number
long get_number(void)
{
    long n;
    do
    {
        n = get_long("CC Number: ");
    }
    while (false);
    return n;
}