#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char LETTERS[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

string encode_message(string message, string key);
bool validate_key(string key_argument);

int main(int argc, string argv[])
{
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int key_length = strlen(argv[1]);

    if (key_length < 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string key = argv[1];
    bool is_key_valid = validate_key(key);

    if (!is_key_valid)
    {
        printf("Key characters must be alphabetical and must not contain repetitive characters.\n");
        return 1;
    }

    string plain_message = get_string("plain text: ");
    string encoded_message = encode_message(plain_message, key);

    printf("ciphertext: %s\n", encoded_message);

    return 0;
}

string encode_message(string message, string key)
{
    for (int i = 0; i < strlen(message); i++)
    {
        char message_character = message[i];
        bool message_character_upper = isupper(message_character);

        message_character = tolower(message_character);

        for (int j = 0; j < 26; j++)
        {
            if (LETTERS[j] == message_character)
            {
                message[i] = message_character_upper ? toupper(key[j]) : tolower(key[j]);
            }
        }
    }

    return message;
}

bool validate_key(string key_argument)
{
    for (int i = 0; i < strlen(key_argument); i++)
    {
        char char_of_key_argument = key_argument[i];
        bool is_alphabetical = isalpha(char_of_key_argument);

        if (!is_alphabetical)
        {
            return false;
        }

        for (int j = 0; j < strlen(key_argument); j++)
        {
            if (i == j)
            {
                continue;
            }

            if (char_of_key_argument == key_argument[j])
            {
                return false;
            }
        }
    }

    return true;
}