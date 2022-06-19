#include <cs50.h>
#include <stdio.h>

float discount(float price, int percent_off);

int main(void)
{
    float regular = get_float("Regular price: ");
    int percent_off = get_int("Percent off: ");

    float sale = discount(regular, percent_off);

    printf("Sale price: %.2f\n", sale);
}

float discount(float price, int percent_off)
{
    return price - (price * (percent_off / 100.0));
}