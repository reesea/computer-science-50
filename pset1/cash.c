#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    /* Initialize for user input */
    float change = 0;
    int coin = 0;

    do
    {
        if(change < 0)
        {
            /* Runs if value isless than zero */
            printf("Retry:");
            change = get_float();
        }
        else
        {

            printf("Change: ");
            change = get_float();
        }
    }

    while (change <= 0);

    /* Conter to an integer */
    int converted = (int)round(change * 100.0);

    /* While loops to convert amount */
    while (converted >= 25)
    {
        converted -= 25;
        coin++;
    }

    while (converted >= 10)
    {
        converted -= 10;
        coin++;
    }

    while (converted >= 5)
    {
        converted -= 5;
        coin++;
    }

    while (converted >= 1)
    {
        converted -= 1;
        coin++;
    }

    /* Displays amount */
    printf("%i\n", coin);
}
