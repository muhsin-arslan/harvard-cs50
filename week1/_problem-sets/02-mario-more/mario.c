#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);

    for (int counter = 0; counter < height; counter++)
    {
        for (int i = height; i > counter + 1; i--)
        {
            printf(" ");
        }

        for (int j = 1; j <= counter + 1; j++)
        {
            printf("#");
        }

        printf("  ");

        for (int k = 1; k <= counter + 1; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}