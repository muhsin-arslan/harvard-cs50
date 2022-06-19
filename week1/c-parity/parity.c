#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("This program find a number is even or odd.\n");
    int number = get_int("Enter a number: ");

    if (number % 2 == 0)
    {
        printf("The number (%i) is even.\n", number);
    }
    else
    {
        printf("The number (%i) is odd.\n", number);
    }
}