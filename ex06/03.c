#include <stdio.h>

void funkce1(int a[], int velikost)
{
    for (int i = 0; i < velikost; i++)
    {
        printf("%i %i %i\n", a[i], *(a+i), i[a]);
    } 
}

void funkce2(int * a, int velikost)
{
    for (int i = 0; i < velikost; i++)
    {
        printf("%i %i %i\n", a[i], *(a+i), i[a]);
    } 
}

int main()
{
    int a[] = {10, 20, 30};

    for (int i = 0; i < sizeof(a)/sizeof(int); i++)
    {
        printf("%i %i %i\n", a[i], *(a+i), i[a]);
    }

    funkce1(a, sizeof(a)/sizeof(int));
    funkce2(a, sizeof(a)/sizeof(int));

    return 0;
}