#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char encode(char letter, int key);
bool only_digits(string argument);

int main(int argc, string argv[])
{
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string key_argument = argv[1];
    bool is_key_argument_valid = only_digits(key_argument);

    if (is_key_argument_valid == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(key_argument);
    string plain_message = get_string("plaintext: ");
    int plain_message_length = strlen(plain_message);

    printf("ciphertext: ");

    for (int i = 0; i < plain_message_length; i++)
    {
        printf("%c", encode(plain_message[i], key));
    }

    printf("\n");

    return 0;
}

char encode(char letter, int key)
{
    bool is_lower = isupper(letter) == 0;
    char letter_to_check = tolower(letter);

    if (isalpha(letter) == 0)
    {
        return (char)letter;
    }

    for (int i = 0; i < 26; i++)
    {
        if (letters[i] == letter_to_check)
        {
            int letter_position_in_alphabet = i + 1;

            if (letter_position_in_alphabet + key > 26)
            {
                int new_position = (letter_position_in_alphabet + key) - 26;

                if (new_position > 26)
                {
                    while (new_position > 26)
                    {
                        new_position -= 26;
                    }
                }

                return is_lower ? letters[new_position - 1] : toupper(letters[new_position - 1]);
            }

            break;
        }
    }

    return (char)((int)letter + key);
}

bool only_digits(string argument)
{
    int argument_length = strlen(argument);

    for (int i = 0; i < argument_length; i++)
    {
        if (isdigit(argument[i]) == 0)
        {
            return false;
        }
    }

    return true;
}