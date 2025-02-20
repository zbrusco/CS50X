#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
} person;


int main(void)
{
    person people[3];
    people[0].name =  "David";
    people[0].number = "1-617-495-1000";

    people[1].name = "John";
    people[1].number = "1-949-468-2750";

    people[2].name = "Yullia";
    people[2].number = "1-617-495-1000";

    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
        }
    }
    printf("Not Found\n");
    return 1;
    // phonebook v0 where the string names and numbers are related
    // to each other, but they are prone to error if you switch any
    // of their positions
    /*
    string names[] = {"Yullia", "David", "John"};
    string numbers[] =  {"1-617-495-1000","1-617-495-1000","1-949-468-2750"};

    string name = get_string("Name: ");
    for (int i = 0; i < 3;  i++)
    {
        if (strcmp(names[i], name) == 0)
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
    */
}
