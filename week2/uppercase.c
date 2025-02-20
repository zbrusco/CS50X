#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    for (int i = 0, n = strlen(s); i < n; i++) //loops through the string equals to the number of characters
    {
        printf("%c", toupper(s[i])); // makes each character an uppercase value while also checking if they're already uppercase
        /*
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            // change  s[i] to uppercase
            printf("%c", s[i] - ('a' - 'A'));

        }
        else
        {
            // Just print s[i]
            printf("%c", s[i]);
        }
        */
    }

    printf("\n");
}
