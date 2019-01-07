#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])

{
    // check command line argument
    if (argc != 2)
    {

        printf("Hello, Please enter a key word.\n");
        return 1;
    }

    else
    {
        // iterate over the string
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            // check to see if character is a letter
            if (!isalpha(argv[1][i]))
            {
                printf("Hello, the key must be an alphabetic character only.");
                return 1;
            }
        }
    }

    string k = argv[1];
    int kLength = strlen(k);

    printf("Key: %s\n", k);

    string p = get_string("plaintext: ");

    printf("ciphertext: ");

    // iterate over the string length
    for (int i = 0, j = 0, n = strlen(p); i < n; i++)
    {
        int characterKey = tolower(k[j % kLength]) - 'a';

        // check to see if character is upper case
        if (isupper(p[i]))
        {
            printf("%c", 'A' + (p[i] - 'A' + characterKey) % 26);
            j++;
        }

        // check to see if character is lower case
        else if (islower(p[i]))
        {
            printf("%c", 'a' + (p[i] - 'a' + characterKey) % 26);
            j++;
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    // returns new line
    printf("\n");
    return 0;
}
