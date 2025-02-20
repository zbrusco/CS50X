#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);
void print_grade(float grade);

int main(void)
{
    int words, letters, sentences;
    // repeats prompt until user types at least one word
    do
    {
        // prompt user to write a text and gets the number of words, letters and sentences
        string text = get_string("Text: ");
        words = count_words(text);
        letters = count_letters(text);
        sentences = count_sentences(text);
        if (words == 0)
        {
            printf("Please input a text to be graded.\n");
        }
    }
    while (words == 0);
    // calculates grade according to the Coleman-Liau index
    float L = (letters * 100.0) / words, S = (sentences * 100.0) / words;
    float grade = 0.0588 * L - 0.296 * S - 15.8;
    print_grade(grade);
}

// identify how many letters are in total at the text
int count_letters(string s)
{
    int letters = 0;
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isalpha(s[i]) != 0)
        {
            letters++;
        }
    }
    return letters;
}
// identify how many words are in the text (letters separated by a space)
int count_words(string s)
{
    int words = 0;
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        // counts the beggining of a word
        if (i > 0 && (s[i - 1] == ' ' && s[i] != ' '))
        {
            words++;
        }
        // counts the first word
        else if (i == 0 && s[i] != ' ')
        {
            words++;
        }
    }
    return words;
}
//  identify the number of sentences
int count_sentences(string s)
{
    int sentences = 0;
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        // counts the beggining of a word
        if (s[i] == '?' || s[i] == '!' || s[i] == '.')
        {
            sentences++;
        }
    }
    return sentences;
}
// prints grade rounded to the next integer
void print_grade(float grade)
{
    if (lroundf(grade) < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (lroundf(grade) > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %li\n", lroundf(grade));
    }
}
