#include <cs50.h>
#include <stdio.h>

void pyramid(int height);

int main(void)
{
    int i;
    do
    {
        i = get_int("Height? ");
    }
    while (i <= 0 || i > 8); // repeats infinitely until user types value within range
                             // defined by the scope of the mario-less CS50 exercise

    for (int row = 0; row < i; row++) // creates rows according to user input value
    {
        for (int j = 0; j < i - row - 1; j++)
        {
            printf(" ");
        }
        pyramid(row);
        printf("\n");
    }
}

void pyramid(int height)
{
    for (int col = 0; col <= height; col++) // Prints a pound '#' according to the row number.
    {                                       // If on the first row, it'll print one character
        printf("#");
    }
}
