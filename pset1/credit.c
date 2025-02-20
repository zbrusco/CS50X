#include <cs50.h>
#include <stdio.h>

int counter(long card);
void card_type_check(int sum_even, int sum_odd, int digits, long first_digits);

int main(void)
{

    long card = get_long("Number: ");
    long first_digits = card;
    int digits = counter(card);     // uses function to count the number of digits
    if (digits > 17 || digits < 13) // range of CC numbers defined on the scope of the CS50 problem
    {
        printf("INVALID\n");
    }
    else
    {
        int pos, digit, even, sum_even = 0, sum_odd = 0;
        for (pos = 1; pos <= digits; pos++) // loops that runs through all digits, assigning the
                                            // position 1 to the right-most number
        {
            digit = (card % 10);
            if (pos % 2 != 0) // gets odd positions
            {
                sum_odd = sum_odd + digit; // sums up the odd digits
            }
            else // even positions
            {
                even = digit * 2;
                if (even > 9)
                {
                    even = (even % 10) + (even / 10);
                }
                sum_even = sum_even + even; // sums up the even digits
            }
            card /= 10; // removes the current digit and move on to the next one
        }
        card_type_check(sum_even, sum_odd, digits, first_digits); // function to check card types
    }
}

int counter(long card) // counts the number of digits
{
    int digits = 0;
    while (card > 0)
    {
        card = card / 10;
        digits++;
    }
    return digits;
}

void card_type_check(int sum_even, int sum_odd, int digits, long first_digits)
{
    if ((sum_even + sum_odd) % 10 == 0) // checks if the total’s last digit is 0
    {
        while (first_digits > 100) // loop to extract the first two digits from the number provided
        {
            first_digits /= 10;
        }
        // conditions for MC, AMEX and VISA defined by the scope of CS50 credit assignment
        if ((first_digits >= 51 && first_digits <= 55) && digits == 16)
        {
            printf("MASTERCARD\n");
        }
        else if ((first_digits == 34 || first_digits == 37) && digits == 15)
        {
            printf("AMEX\n");
        }
        else if ((first_digits / 10 == 4) && (digits == 13 || digits == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
