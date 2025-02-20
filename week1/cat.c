#include <cs50.h>
#include <stdio.h>

int get_positive_int(void); // function outputs an integer
void meow(int times);       // function doesn't have an output, but has input 'times'

int main(void)
{
    /*    int i = 0;
        while (i < n)
        {
            meow();
            i++;
        }
    */
    int n = get_positive_int();
    meow(n);
}

int get_positive_int(void) // loop that gets the integer from user input. Will keep asking for a
                           // number until a value greater than 1 is provided.
{
    int n;
    do
    {
        n = get_int("Number: ");
    }
    while (n < 1);
    return n;
}

void meow(int times) // function for meow, has a loop that will print the message "meow" a 'times' amount
{
    for (int j = 0; j < times; j++) // for loop that will execute what's within the curly braces
                                    // until the value of j is less than 'times'.
    {
        printf("meow\n");
    }
}
