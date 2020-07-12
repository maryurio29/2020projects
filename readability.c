#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_Letters(string, int);
int count_Words(string, int);
int count_Sentences(string, int);
int index(int, int, int);

int main(void)
{
    string text = get_string("Text: ");
    int length = strlen(text);
    int letters = count_Letters(text, length);
    int words = count_Words(text, length);
    int sentences = count_Sentences(text, length);
    int grade = index(letters, words, sentences);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
        
}
//Function to count letters
//Input will be type string titled after user's input string and int for the length of string, output will be an integer, i.e. number of letters
int count_Letters(string text, int length)
{
    int l = 0;
    for (int i = 0; i < length; i++)//Iteration through the length of the string
    {
        if (isalpha(text[i]))//Will not count blank spaces
        {
            l++;
        }
    }
    return l;
}
//Function to count words
//Input will be type string titled after user's input string and int for the length of string, output will be an integer, i.e. number of words
int count_Words(string text, int length)
{
    int w = 0;
    for (int i = 0; i < length; i++)//Iteration through the length of the string
    {
        //Count the first word and then count every space followed by a letter throughout the string as a word
        if ((i == 0 && isalpha(text[i])) || (i != length - 1 && isblank(text[i]) && isalpha(text[i + 1])))
        {
            w++;
        }
    }
    return w;
}
//Function to count sentences
//Input will be type string titled after user's input string and int for the length of string, output will be an integer, i.e. number of sentences
int count_Sentences(string text, int length)
{
    int s = 0;
    for (int i = 0; i < length; i++)
    {
        //Punctuation considered a sentence
        if (text[i] == '!' || text[i] == '.' || text[i] == '?' || text[i] == ':')
        {
            s++;
    
        }    
    }
    return s;
}
//Function to perform Coleman-Liau index
//Input will be the # of letters, l, words, w, sentences, s. Output will be the Grade index, g.
int index(int l, int w, int s)
{
    float L = (float) l / ((float) w / 100);//Average letters per 100 words
    float S = (float) s / ((float) w / 100);//Average of sentences per 100 words
    float index = (0.0588 * L) - (0.296 * S) - 15.8;//Coleman-Liau formula
    int g = round(index);
    return g;
}