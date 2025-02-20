#include <cs50.h>
#include <stdio.h>

int quarters_calc(int cents);
int dimes_calc(int cents);
int nickels_calc(int cents);
int pennies_calc(int cents);

int main(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);
    // Updates the value of cents and subtracts the amount for each type of coin
    int quarters = quarters_calc(cents);
    cents = cents - (quarters * 25);
    int dimes = dimes_calc(cents);
    cents = cents - (dimes * 10);
    int nickels = nickels_calc(cents);
    cents = cents - (nickels * 5);
    int pennies = pennies_calc(cents);
    cents = cents - pennies;
    // After getting minimum values for each type of coin, they are summed up and printed onto the
    // screen
    printf("%i\n", quarters + dimes + nickels + pennies);
}

// function that calculates the amounts of quarters, dimes, nickels and pennies and returns an
// integer
int quarters_calc(int cents)
{
    int quarters = cents / 25;
    return quarters;
}

int dimes_calc(int cents)
{
    int dimes = cents / 10;
    return dimes;
}

int nickels_calc(int cents)
{
    int nickels = cents / 5;
    return nickels;
}

int pennies_calc(int cents)
{
    int pennies = cents;
    return pennies;
}
