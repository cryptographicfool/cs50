#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // int to store commad line input.
    int k = 0;
    // make sure user has given command line input.
    if (argc == 2)
    {
        // convert commmand line input string to an int.
        k = atoi(argv[1]);
        // go through each point in the string.
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            // if any of it is not a digit.
            if (!isdigit(argv[1][i]))
            {
                printf("./caesar key\n");
                return 1;
            }
        }
        // if it is a digit.
        // define a string to store the plaintext.
        string ct = 0;
        // get input from use.
        string pt = get_string("plaintext: ");
        printf("ciphertext: ");
        // convert plaintext to ciphertext.
        for (int i = 0; i < strlen(pt); i++)
        {
            char c = pt[i];
            // for uppercase
            if (isupper(c))
            {
                printf("%c", (((c + k) - 'A') % 26) + 'A');
            }
            // for lowercase.
            else if (islower(c))
            {
                printf("%c", (((c + k) - 'a') % 26) + 'a');
            }
            // if neither upper or lower.
            else
            {
                printf("%c", c);
            }

        }
        printf("\n");
        return 0;

        // formula ci = (pi + k) % 26
    }
    // if there is no key input in command line.
    else
    {
        printf("./caesar key\n");
        return 1;
    }
}
