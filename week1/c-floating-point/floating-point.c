#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float x = get_float("x: ");
    float y = get_float("y: ");
    float z = x / y;

    printf("%f\n", z);   // x:2 - y:3 > 0.666667
    printf("%.2f\n", z); // x:2 - y:3 > 0.67

    // x:1 - y:10 > 0.10000000149011611938476562500000000000000000000000 (Huh?)
    // If you only have 32 bits, change to double and only have 64 bits. But it's still finite
    printf("%.50f\n", z);
}