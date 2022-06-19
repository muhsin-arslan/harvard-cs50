#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int amount_of_scores = get_int("Score amount: ");
    int scores[amount_of_scores];

    for (int i = 0; i < amount_of_scores; i++)
    {
        scores[i] = get_int("Score %i: ", i + 1);
    }

    float sum_of_scores = 0;
    for (int i = 0; i < amount_of_scores; i++)
    {
        sum_of_scores += scores[i];
    }

    printf("Average: %.2f\n", sum_of_scores / amount_of_scores);
}