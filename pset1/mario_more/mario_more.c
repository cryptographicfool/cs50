// code for mario More

#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int h;
    // the following prompts user for height input, making sure only a whole number between 1 and 8 is accepted.
    do
    {
        h = get_int("Enter height, which is a whole number between 1 and 8:\n");
    }
    while (h < 1 || h > 8);

    // outer loop controls the number of lines printed based on the height input received earlier.
    for (int a = 0; a < h; a++)
    {
        // inner loop to print spaces before the hashes for left pyramid
        for (int c = h - 1; c > a; c--)
        {
            printf(" ");
        }
        // inner loop to print the hashes for left pyramid
        for (int b = 0; b <= a; b++)
        {
            printf("#");
        }

        // following prints the space between two pyramids
        printf("  ");

        //inner loop to print the hashes for right pyramid
        for (int d = 0; d <= a; d++)
        {
            printf("#");
        }

        //following moves to the next line of pyramid
        printf("\n");
    }
}
