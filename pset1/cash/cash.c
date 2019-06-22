#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;

    // Prompts user to input a positive float for the change owed.
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);

    // Converts the float value into a rounded integer cents.
    int cents = round(change * 100);

    // These ints store the number of coins used for each denomination.
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

    // Calculates the number of 0.25 coins needed.
    if (cents > 25)
    {
        a = cents / 25;
        cents = cents % 25;
    }

    // Calculates the number of 0.10 coins needed.
    if (cents > 10)
    {
        b = cents / 10;
        cents = cents % 10;
    }

    // Calculates the number of 0.05 coins needed.
    if (cents >= 5)
    {
        c = cents / 5;
        cents = cents % 5;
    }

    // Calculates the number of 0.01 coins needed.
    if (cents >= 1)
    {
        d = cents / 1;
    }

    // Adds together the total number of coins needed and prints the same.
    printf("%i\n", a + b + c + d);

}
