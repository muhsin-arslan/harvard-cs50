#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {7, 4, 10, 8, 3, 1};
    int length = 6;
    int minimum;

    for (int i = 0; i < length - 1; i++)
    {
        minimum = i;

        for (int j = i + 1; j < length; j++)
        {
            if (numbers[j] < numbers[minimum])
            {
                minimum = j;
            }
        }

        int previous = numbers[i];
        numbers[i] = numbers[minimum];
        numbers[minimum] = previous;
    }

    for (int x = 0; x < length; x++)
    {
        printf("%i\n", numbers[x]);
    }
}