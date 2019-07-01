#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function initialization for converting character to an int for key
int shift(char c);

// Main Program
int main(int argc, string argv[])
{
    // check if command line input is valid
    if (argc == 2)
    {
        // go through each point in the string
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            // if input is non alphabet
            if (!isalpha(argv[1][i]))
            {
                printf("./vigenere keyword\n");
                return 1;
            }
        }
        // get plaintext message input from use
        string pt = get_string("plaintext: ");
        // store length of plaintext message
        int ptLen = strlen(pt);
        // store length of key input provided at command line
        int keyLen = strlen(argv[1]);
        // char to store new key generated
        char newKey[ptLen];
        // generate new key based on message length
        for (int i = 0, j = 0; i < ptLen; i++, j++)
        {
            if (j == keyLen)
            {
                j = 0;
            }
            newKey[i] = argv[1][j];
        }
        // output
        printf("ciphertext: ");
        // convert plaintext to ciphertext.
        for (int i = 0, j = 0; i < strlen(pt); i++)
        {
            // call function
            int kn = shift(newKey[j]);
            // get character from plaintext
            char c = pt[i];
            // for uppercase
            if (isupper(c))
            {
                printf("%c", (((c + kn) - 'A') % 26) + 'A');
                j++;
            }
            // for lowercase.
            else if (islower(c))
            {
                printf("%c", (((c + kn) - 'a') % 26) + 'a');
                j++;
            }
            // if neither upper or lower.
            else
            {
                printf("%c", c);
            }
        }
        printf("\n");
        return 0;
    }
    // if command line argument input is non valid
    else
    {
        printf("./vigenere keyword\n");
        return 1;
    }
}

// function definition for converting character to an int for key
int shift(char c)
{
    if (isupper(c))
    {
        return ((c - 'A') % 26);
    }
    else if (islower(c))
    {
        return ((c - 'a') % 26);
    }
    else
    {
        return c;
    }
}
