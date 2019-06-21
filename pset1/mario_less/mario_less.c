

//Pseudocode
//  - prompt user for an integer, between 1 and 8, lets call it 'h' .
//  - check if user input is between 1 and 8, if yes, move to the next step, if no, prompt user again.
//  - lets say 'n' is the number of the strings being printed ( first string being 1, second being 2, third being 3, etc.)
//  - print a string 'n' what has spaces 's' equal to 'h-n', followed by '#' symbols, number of '#' symbols printed is equal to 'n'.
//  - loop this until 'n' equals 'h'.


//code for mario less

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
        // inner loop to print spaces before the hashes
        for (int c = h - 1; c > a; c--)
        {
            printf(" ");
        }
        // inner loop to print the hashes
        for (int b = 0; b <= a; b++)
        {
            printf("#");
        }
        printf("\n");
    }
}
