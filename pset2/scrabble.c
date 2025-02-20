#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// define the point array provided by the CS50 assignment
int points[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calc_scores(string word);

int main(void)
{
    // get string from user
    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");
    // calculate the scores for each string
    int score1 = calc_scores(p1);
    int score2 = calc_scores(p2);
    // Print out the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
// Calculate the points for each character based on the array position
int calc_scores(string word)
{
    int sum = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isalpha(word[i]) == 0)
        {
            sum += 0;
        }
        else
        {
            sum += points[toupper(word[i]) - 'A'];
        }
    }
    return sum;
}
