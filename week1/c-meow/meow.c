#include <cs50.h>
#include <stdio.h>

// Declaring function / prototype
// Otherwise meow function must be top of the c file
void meow(void);

int main(void)
{
    // While Loop
    printf("With while loop\n");

    int i = 0;
    while (i < 3)
    {
        meow();
        i++;
    }

    printf("----------\n");

    // For Loop
    printf("With for loop\n");

    for (int i = 0; i < 3; i++)
    {
        meow();
    }
}

void meow(void)
{
    printf("meow\n");
}