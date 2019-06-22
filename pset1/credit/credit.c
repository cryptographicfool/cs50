#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Stores cc number
    long cnumber;
    int digit_1 = 0, digit_2 = 0, digitn = 0, sum_odd = 0, sum_even = 0;

    do
    {
        // Prompts user to input cc number
        cnumber = get_long("Card Number: ");
    }
    while (cnumber < 0);

    // Seperates the digits in cc number, stores the number of digits in 'digitn'.
    while (cnumber > 0)
    {
        digit_2 = digit_1;
        digit_1 = cnumber % 10;

        // Calculates sum of even digits
        if (digitn % 2 == 0)
        {
            sum_even += digit_1;
        }

        // Calculates sum of odd digits
        else
        {
            int m = 2 * digit_1;
            sum_odd += (m / 10) + (m % 10);
        }

        cnumber /=10;
        digitn++;
    }

    // Checks if input is a valid cc number.
    bool valid = (sum_even + sum_odd) % 10 == 0;
    // Calculates first 2 digits on the card.
    int first_2 = (digit_1 * 10) + digit_2;

    // Checks if it is a VISA number.
    if (digit_1 == 4 && digitn >= 13 && digitn <=16 && valid)
    {
        printf("VISA\n");
    }

    // Checks if it is a MASTERCARD number.
    else if (first_2 >= 51 && first_2 <= 55 && digitn == 16 && valid)
    {
        printf("MASTERCARD\n");
    }

    // Checks if it is an AMEX number.
    else if ((first_2 == 34 || first_2 == 37) && digitn == 15 && valid)
    {
        printf("AMEX\n");
    }

    // Outputs INVALID if input is not a valid cc number.
    else
    {
        printf("INVALID\n");
    }
}
