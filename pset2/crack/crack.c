#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <crypt.h>

int main(int argc, string argv[])
{
    // if user input is not a hash, i.e. if user inputs more than one string, return with syntax and stop the program.
    if (argc != 2)
    {
        printf("Usage: crack hash\n");
        return 1;
    }

    /* hash can have 53 possible characters. i.e., 26 lowercase + 26 upercase + \0 null (this counts as 1 character) */
    const int letter_count = 53;
    // string with all possible letters
    string letters = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // convert user input to string hash
    string hash = argv[1];
    // variable salt to store first two characters of hash
    char salt[3];
    // put first two character of hash in salt and put null in third character of salt.
    memcpy(salt, hash, 2);
    salt[2] = '\0';

    char key_candidate[6] = "\0\0\0\0\0\0";

    // We go throught the outer loop less frequently compared to the inner loops, therefore it maps to the last (fifth) character in password.
    for (int five = 0; five < letter_count; five++)
    {
        for (int four = 0; four < letter_count; four++)
        {
            for (int three = 0; three < letter_count; three++)
            {
                for (int two = 0; two < letter_count; two++)
                {
                    // Innermost loop reiterates most frequently compared to outer loops, therefore, it maps to the first character in password.
                    // We cant initialize it at 0 because that would mean there is no password, which we initialize it at 1.
                    for (int one = 1; one < letter_count; one++)
                    {
                        key_candidate[0] = letters[one];    //1
                        key_candidate[1] = letters[two];    //2
                        key_candidate[2] = letters[three];  //3
                        key_candidate[3] = letters[four];   //4
                        key_candidate[4] = letters[five];   //5

                        // string functions in C stop looping when they encounter a null character.
                        // we leverage that when we initialize all key_candidate with null characters
                        // and progress in loops from first to fifth character. Sixth character was already
                        // initialized as a null.
                        if (strcmp(crypt(key_candidate, salt), hash) == 0)
                        {
                            printf("%s\n", key_candidate);
                            return 0;
                        }
                    }
                }
            }
        }
    }

    printf("Password could not be cracked\n");
    // we have already used exit status 0 and 1 above so we have to use 2 in this case.
    return 2;

}
