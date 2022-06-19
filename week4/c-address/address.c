#include <stdio.h>

int main(void)
{
    // Integer
/*  int n = 50;
    int *p = &n;

    int x = n;
    int *p2 = &x;

    printf("%p\n", p);
    printf("%i\n", *p);

    printf("%p\n", p2);
    printf("%i\n", *p2); */

    // String
    char *s = "HI!";

    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
}