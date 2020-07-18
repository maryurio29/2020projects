#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int check_Key(string);
string get_Cipher(string, string);

int main(int argc, string argv[])
{
    int arg = argc;//To store number of arguments in command-line
    if (arg != 2)//To handle lack of key/ too many arguments
    {
        printf("Usage: ./substitution KEY\n");
        exit(1);
    }
    int c = check_Key(argv[1]);//To check key only has digits, 26 characters long and does not repeat
    if (argc == 2 && c == 0)// There is a key and it is only digits
    {
        string key = argv[1];
        string plaintext = get_string("plaintext: ");//Prompt user for plaintext
        string ciphertext = get_Cipher(key, plaintext);//Returns ciphertext
        printf("ciphertext: %s\n", ciphertext);
        exit(0);
    }
    else if (argc == 2 && c == 1)//If key is not long enough, i.e. 26 chars
    {
        printf("Key must contain 26 characters.\n");
        exit(1);
    }
    else if (argc == 2 && c == 2)//If key has digits
    {
        printf("Key must only contain alphabetic characters.\n");
        exit(1);
    }
    else if (argc == 2 && c == 3)//If key has repeated chars
    {
        printf("Key must not contain repeated characters.\n");
        exit(1);
    }
    exit(0);
}
//Function to check if key is digits only
int check_Key(string key)
{
    int s = 0;
    int d = 0;
    int l = strlen(key);
    if (l != 26)
    {
        s = 1;//Condition 1 not met, i.e. not 26 chars long
    }
    else if (l == 26)
    {
        int k = 0;
        for (int i = 0; i < l; i++)//Iterates through length of key
        {
            if (!isalpha(key[i]))//Checks that every char in the string is a letter
            {
                d++;//Condition 2 not met, i.e. includes digit(s)
            }
            else if (isalpha(key[i]))
            {
                for (int j = 1; j < l - i; j++)//Iterates through-out key
                {
                    char a = toupper(key[i]);
                    char b = toupper(key[i + j]);
                    if (a == b)
                    {
                        k++;
                    }
                }
            }
        }
        if (k > 0)
        {
            s = 3;//Condition 3 not met, i.e. contains repeated letter
        }
        else
        {
            s = 0;//All conditions met, valid key
        }
    }
    if (d > 0)
    {
        s = 2;//Condition 2 not met, i.e. not all letters inside key
    }
    return s;
}
//Function for cipher
string get_Cipher(string key, string plain)//Takes key and plaintext as input and returns ciphertext string
{
    int l = strlen(plain);
    string a = "abcdefghijklmnopqrstuvwxyz";
    string c = plain;
    for (int i = 0; i < l; i++)//Iterates through-out the plaintext
    {
        char d = plain [i];
        if (isalpha(plain[i]))//Checks only for alpha char, i.e. not punctuation
        {
            for (int j = 0; j < 26; j++)//Iterates through-out string a, i.e. regular alphabet has 26 chars
            {
                if (tolower(plain[i]) == a[j])//Checks to see which char in the alphabet it is
                {
                    if (isupper(plain[i]))//Check for capitalization
                    {
                        d = toupper(key[j]);//If it is capitalized in the plaintext, it will capitilized in the ciphertext too
                    }
                    else
                    {
                        d = tolower(key[j]);//Sets the ciphertext char equal to the char in the key that matches the alphabet char position
                    }
                }
            }
        }
        c[i] = d;
    }
    return c;
}