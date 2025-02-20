#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string strings[] =  {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};
    string s = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        // In order to compare strings, you have to use the strcmp function
        // strings[i] == s is not powerful enough and will result in a BUG
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;

}
