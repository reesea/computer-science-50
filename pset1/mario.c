#include <cs50.h>
#include <stdio.h>

int main(void)

{
    int height = 1;

    do
    {

    /* The inputs a number within range for height of pyramid */
    if (height == 0)
    {

    break;
    }

    else if (height <= 0 || height >= 24)
    {
            printf("Retry");
            height = get_int();
    }
    else
    {
            printf("Height: ");
            height = get_int();
    }
}
    /* A positive integer causes this code to run */
    while (height <= 0 || height >= 24);

    /* Begin for loop based on user input */
    for(int i = 1; i <= height; i++)
        {

    /* This for loop sets the number of spaces */
    for(int j = 1; j <= (height - i); j++)
        {
            printf(" ");
        }

    /* This for loop sets the number of hashes */
    for(int k = 1; k <= (i + 1); k++)
        {
            printf("#");
        }

    /* Adds a new line after each row */
            printf("\n");
        }
    return 0;
}
