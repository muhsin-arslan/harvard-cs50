#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Exponent: 2_32 > max 4294967296
    /* int x = get_int("x: ");
    int y = get_int("y: ");
    printf("%i\n", x + y); */

    // Via long (Avoid from integer overflow)
    // Exponent: 4_32 > max 1.844674407371𝐸+19
    long x = get_long("x: ");
    long y = get_long("y: ");
    printf("%li\n", x + y);
}
