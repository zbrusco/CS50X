#include <cs50.h>
#include <stdio.h>

int string_length(string s);

int main(void)
{
    string name = get_string("Name: ");
    int length = string_length(name); // alternatively just use  the srtlen() function on the string.h library
    printf("%i\n!", length);
}




// Recreation of the strlen function
int string_length(string word)
{
    int n = 0;
    while (word[n] != '\0') // counts characters within a string up until the character is equal to \0
    {
        n++;
    }
    return n;
}
