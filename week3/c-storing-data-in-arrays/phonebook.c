#include <cs50.h>
#include <stdio.h>
#include <string.h>

/*
int main(void)
{
    string names[] = {"David", "Muhsin"};
    string numbers[] = {"+1-617-495-1000", "+1-611-420-2517"};

    for(int i = 0; i < 2; i++)
    {
        if(strcmp(names[i], "David") == 0)
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }

    printf("Not found\n");
    return 1;
}
*/

// STRUCTS

typedef struct
{
    string name;
    string number;
} person;

int main(void)
{
    person people[2];

    people[0].name = "David";
    people[0].number = "+1-617-495-1000";

    people[1].name = "Muhsin";
    people[1].number = "+1-611-420-2517";

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, "David") == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }

    printf("Not found\n");
    return 1;
}