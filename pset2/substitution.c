#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

void encoder(string text, string cipher);
int key_check(string key);

int main(int argc, string argv[])
{
    // checks if user inputs an argument
    if (argc == 2)
    {
        if (strlen(argv[1]) == 26)
        {
            // checks for key validity
            int key = key_check(argv[1]);
            // if key is valid
            if (key == 0)
            {
                // prompt user to provide text to be encrypted
                string text = get_string("plaintext: ");
                // converts and prints text
                encoder(text, argv[1]);
            }
            else
            {
                printf("Key must contain 26 unique alphabetical characters\n");
                return 1;
            }
        }
        else
        {
            printf("Key must contain 26 characters\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

// converts text character to cipher
void encoder(string text, string cipher)
{
    printf("ciphertext: ");
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            char adjusted_key;
            if (isupper(text[i]) != 0)
            {
                adjusted_key = toupper(cipher[text[i] - 'A']);
            }
            else
            {
                adjusted_key = tolower(cipher[text[i] - 'a']);
            }
            printf("%c", adjusted_key);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}

// Checks for key validity
int key_check(string key)
{
    int check[ALPHABET_SIZE] = {0};
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        // if non alphabetic char found, exit the function
        if (isalpha(key[i]) == 0)
        {
            return 1;
        }
        // if char already exists in key array, exit the function
        else if (check[toupper(key[i]) - 'A'] == 1)
        {
            return 1;
        }
        // otherwise, store the value 1 to the respective char
        // position on the array
        else
        {
            check[toupper(key[i]) - 'A'] = 1;
        }
    }
    return 0;
}
