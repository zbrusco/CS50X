#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int n)
{
    if (n <= 0)
    {
        return;
    }

    draw(n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}

// Piramide decrescente
/*
void draw(int n = 4)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");

    // Prints four hashes since nothing is stopping printf from executing
    // Draw(n-1) is called within the function, so it prints n-1 hashes
    // so on and so forth until n = 0

    draw(3) > draw(2) > draw(1) > draw(0) ;
}


// Piramide crescente

void draw(int n = 4)
{
    // Function starts, stumbles accross draw(n-1) recursion, can't runt printf.
    // It repeats until n = 0 and then it starts printing from the inside out
    // To draw(4), I must draw(3), which in turn I must draw(2), for which I have
    // to draw(1), but first I have to draw(0).
    // Effectively the function executes draw from the smallest N possible
    // and stops at the desired N chosen by the user.
    draw(3) > draw(2) > draw(1) > draw(0) ;
        for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
*/
