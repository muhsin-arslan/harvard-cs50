#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {5, 2, 7, 4, 1, 6, 3, 0};
    // int numbers[] = {3, 1, 0};

    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 8; j++)
        {
            if (numbers[i] > numbers[j])
            {
                int current_number = numbers[i];
                int compared_number = numbers[j];

                numbers[i] = compared_number;
                numbers[j] = current_number;
            }
        }
    }

    for (int z = 0; z < 8; z++)
    {
        printf("%i", numbers[z]);
    }
}