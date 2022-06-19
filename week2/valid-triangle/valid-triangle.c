#include <cs50.h>
#include <stdio.h>

bool validate_triangle(float side1, float side2, float side3);

int main(void)
{
    float side1 = get_float("Side1: ");
    float side2 = get_float("Side2: ");
    float side3 = get_float("Side3: ");

    bool is_triangle_valid = validate_triangle(side1, side2, side3);

    is_triangle_valid ? printf("Triangle is valid.\n") : printf("Triangle is invalid.\n");

    return 0;
}

bool validate_triangle(float side1, float side2, float side3)
{
    if (side1 <= 0 || side2 <= 0 || side3 <= 0)
        return false;

    if ((side1 + side2 <= side3) || (side1 + side3 <= side2) || (side2 + side3 <= side1))
        return false;

    return true;
}
