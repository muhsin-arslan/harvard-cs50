#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int get_grade(float average_letters, float average_sentences);
int get_letter_amount(string text);
int get_word_amount(string text);
int get_sentence_amount(string text);
float calculate_average_letters(int letter_amount, int word_amount);
float calculate_average_sentences(int sentence_amount, int word_amount);

int main(void)
{
    string text = get_string("Text: ");

    int letter_amount = get_letter_amount(text);
    int word_amount = get_word_amount(text);
    int sentence_amount = get_sentence_amount(text);

    float average_letters = calculate_average_letters(letter_amount, word_amount);
    float average_sentences = calculate_average_sentences(sentence_amount, word_amount);

    int grade = get_grade(average_letters, average_sentences);

    grade<1 ? printf("Before Grade 1\n") : grade> 16 ? printf("Grade 16+\n") : printf("Grade %i\n", grade);
}

int get_grade(float average_letters, float average_sentences)
{
    return round(0.0588 * average_letters - 0.296 * average_sentences - 15.8);
}

int get_letter_amount(string text)
{
    int letter_amount = 0;
    int character_amount = strlen(text);

    for (int i = 0; i < character_amount; i++)
    {
        char current_character = text[i];

        if ((current_character >= 'a' || current_character >= 'A') && (current_character <= 'z' || current_character <= 'Z'))
        {
            letter_amount++;
        }
    }

    return letter_amount;
}

int get_word_amount(string text)
{
    int word_amount = 1;
    int character_amount = strlen(text);

    for (int i = 0; i < character_amount; i++)
    {
        char current_character = text[i];

        if (isspace(current_character))
        {
            word_amount++;
        }
    }

    return word_amount;
}

int get_sentence_amount(string text)
{
    int sentence_amount = 0;
    int character_amount = strlen(text);

    for (int i = 0; i < character_amount; i++)
    {
        char current_character = text[i];

        if (current_character == '.' || current_character == '?' || current_character == '!')
        {
            sentence_amount++;
        }
    }

    return sentence_amount;
}

float calculate_average_letters(int letter_amount, int word_amount)
{
    return (letter_amount / (float)word_amount) * 100;
}

float calculate_average_sentences(int sentences_amount, int word_amount)
{
    return (sentences_amount / (float)word_amount) * 100;
}