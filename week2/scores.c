#include <cs50.h>
#include <stdio.h>

const int N = 3;

//prototype
float average(int length, int array[]);

int main (void)
{
    // get scores
    int scores[N];
    for  (int i = 0; i < 3;  i++)
    {
        scores[i] = get_int("Score: ");
    }

    // Print averages
    printf("Average: %f\n", average(N, scores));
}

float average(int length, int array[])
{
    // Calculate average
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}
