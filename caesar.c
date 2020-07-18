#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int check_Key(string);
string get_Cipher(int, string);

int main(int argc, string argv[])
{
    int arg = argc;//To store number of arguments in command-line
    if (arg != 2)//To handle lack of key/ too many arguments
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int c = check_Key(argv[1]);//To check key only has digits
    if (argc == 2 && c == 0)// There is a key and it is only digits
    {
        int k = atoi(argv[1]);//Convert key from string to int
        string plaintext = get_string("plaintext: ");//Prompt user for plaintext
        string ciphertext = get_Cipher(k, plaintext);//Returns ciphertext
        printf("ciphertext: %s\n", ciphertext);
    }
    else//If key is non-numeric
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
//Function to check if key is digits only
int check_Key(string key)
{
    int s = 0;
    for (int i = 0, l = strlen(key); i < l; i++)//Iterates through length of key
    {
        if (!isdigit(key[i]))//Checks every char in string key if it is non-numeric s will increase, i.e. s != 0
        {
            s++;
        }
    }
    return s;
}
//Function for cipher
string get_Cipher(int key, string plain)//Takes key and plaintext as input and returns ciphertext string
{
    int l = strlen(plain);
    string c = plain;
    for (int i = 0; i < l; i++)//Iterates through length of plain text
    {
        if (isalpha(plain[i]))//Checks only for alpha char, i.e. not punctuation
        {
            int d = (int) plain[i];//Converts char into ASCII value
            if (d > 64 && d < 91)//For uppercase
            {
//In order to use c0 = (p0 + key) % 26 formula we have to reference ASCII value back to 0, i.e. subtract 65 from 65 to get 0, and reference back at the end                
                d = (((d - 65) + key) % 26) + 65;
            }
            else if (d > 96 && d < 123)//For lowercase
            {
                d = (((d - 97) + key) % 26) + 97;
            }
            c[i] = d;
        }
    }
    return c;
}