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
    while (i <= 0 || i > 8);                        // repeats infinitely until user types value within range

    for (int row = 0; row < i; row++)               // starts row loop until user defined value
    {
        for (int j = 0; j < i - row - 1; j++)
        {
            printf(" ");
        }
        pyramid(row);
        printf("  ");
        pyramid(row);
        printf("\n");
    }
}

void pyramid(int height)
{
    for (int col = 0; col <= height; col++)        // Similar logic to the space loop, except that it prints the character exactly to the number of rows
    {                                              // that the program is running, If on the first row, it'll print one character
        printf("#");
    }
}
