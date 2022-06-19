#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Research: For non-English characters like ü,ğ contains 2 space/ASCII character
// This is why when calculate length of string can return +1 value for each non-English characters.

int string_length(string s);

int main(void)
{
    string name = get_string("Name: ");
    int length = string_length(name);

    printf("%i\n", length);

    string last_name = get_string("Lastname: ");
    int length_of_last_name = strlen(last_name);
    printf("%i\n", length_of_last_name);
}

int string_length(string s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }

    return i;
}