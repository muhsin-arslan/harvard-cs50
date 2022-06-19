#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number = get_int("Enter a number between 1-5: ");

    switch (number)
    {
    case 1:
        printf("You entered 1");
        break;
    case 2:
        printf("You entered 2");
        break;
    case 3:
        printf("You entered 3");
        break;
    case 4:
        printf("You entered 4");
        break;
    case 5:
        printf("You entered 5");
        break;
    default:
        printf("Sorry!");
    }

    printf("\n");
}