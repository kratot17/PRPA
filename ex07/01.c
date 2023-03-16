#include <stdio.h>

// globalni promenna
int b;

void funkce(int x)
{
    x += 10;
    b = 33;
}

void funkce1(int *x)
{
    *(x) = 44;
    b = 55;
}

int main()
{
    int a = 10;

    printf("a = %i, b = %i\n", a, b);
    funkce(a);
    printf("a = %i, b = %i\n", a, b);
    funkce1(&a);
    printf("a = %i, b = %i\n", a, b);

    return 0;
}