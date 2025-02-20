#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("What's your name? \n> ");
    int age = get_int("How old are you? \n>");
    printf("Hello, %s!\nWow, you are %i years old!\n", answer, age);
}
