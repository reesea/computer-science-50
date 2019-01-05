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

        printf("Hello, Please enter a valid command line argument\n");
        return 1;
    }
    // plain text string from user
    printf("plaintext: ");
    string s = get_string();

    // convert argv to integer
    int key = atoi(argv[1]);
    printf("ciphertext: ");

    // iterate thru string and output ciphertext
    for (int i = 0; i < strlen(s); i++)
    {

        int cipherkey = key % 26;

        // check if character is a letter
        if (s[i] < 65 || (s[i] > 90 && s[i] < 97) || s[i] > 122)

        {
            printf("%c", s[i]);
        }

        // if character is a letter and does not need to wrap around
        else if (toupper(s[i]) + cipherkey <= 90)
        {
            printf("%c", s[i] + cipherkey);
        }
        else
        {
            // if character is a letter and does need to wrap around
            printf("%c", s[i] + cipherkey - 26);
        }
    }
    printf("\n");
    return 0;
}
