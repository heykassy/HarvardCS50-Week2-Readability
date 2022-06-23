#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    // Prompt the user for text
    string text = get_string("Text: ");

    // Calculate the amount of letters, words and sentences
    float num_letters = count_letters(text);
    float num_words = count_words(text);
    float num_sentences = count_sentences(text);

    // Find the letter average and sentence average
    float L = num_letters / num_words * 100;
    float S = num_sentences / num_words * 100;

    // Calculate and print the grade
    int index = (int) round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// Function that counts the number os letters and returns the sum
int count_letters(string text)
{
    int sum = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            sum++;
        }
    }
    return sum;
}

// Function that counts the number os words and returns the sum
int count_words(string text)
{
    int sum = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            sum++;
        }
    }
    sum++;
    return sum;
}

// Function that counts the number os sentences and returns the sum
int count_sentences(string text)
{
    int sum = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sum++;
        }
    }
    return sum;
}