#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int LETTER_AMOUNT = 26;
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int LETTERS[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    score1 == score2 ? printf("Tie!\n") : score1 > score2 ? printf("Player 1 wins!\n") : printf("Player 2 wins!\n");
}

int compute_score(string word)
{
    int score = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        char letter = word[i];
        letter = tolower(letter);

        if (letter >= 'a' && letter <= 'z')
        {
            for (int j = 0; j < LETTER_AMOUNT; j++)
            {
                char current_letter = LETTERS[j];

                if (current_letter == letter)
                {
                    score += POINTS[j];
                }
            }
        }
    }

    return score;
}
