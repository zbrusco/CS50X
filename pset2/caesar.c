#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

int validate_key(string arg);
void encoder(string text, int key);
void print_error();

int main(int argc, string argv[])
{
    // checks for number of args
    if (argc == 2)
    {
        // checks for key validity
        int is_key_valid = validate_key(argv[1]);
        if (is_key_valid == 0)
        {
            // converts argument string to an int
            int key = atoi(argv[1]);
            // prompt user to provide text to be encrypted
            string text = get_string("plaintext:  ");
            // converts and prints text
            encoder(text, key);
            return 0;
        }
        else
        {
            print_error();
            return 1;
        }
    }
    else
    {
        print_error();
        return 1;
    }
}

// checks for key validity
int validate_key(string arg)
{
    for (int i = 0, len = strlen(arg); i < len; i++)
    {
        // if non decimal digit found, exit the function
        if (isdigit(arg[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

// converts text character to cipher
void encoder(string text, int key)
{
    printf("ciphertext: ");
    char adjusted_key;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            if (isupper(text[i]) != 0)
            {
                adjusted_key = ((text[i] - 'A' + key) % ALPHABET_SIZE) + 'A';
            }
            else
            {
                adjusted_key = ((text[i] - 'a' + key) % ALPHABET_SIZE) + 'a';
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

// prints error message as per CS50 assignment
void print_error(void)
{
    printf("./caesar key\n");
}
