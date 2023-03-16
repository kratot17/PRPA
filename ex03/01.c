#include <stdio.h>

int main()
{
    //prikaz "./a.out < data.in" posle testovaci data do vstupu programu
    //chceme nacist 3 cisla
    int a, b, c, d; //cisla reprezentujici strany troj.
    d = scanf("%i%i%i", &a, &b, &c);

    printf("d = %i, a = %i, b = %i, c = %i\n", d, a, b, c);

    if ((a + b) > c)
    {
        printf("Trojuhelnik lze sestrojit\n");
    }
    else
    {
        printf("Trojuhelnik nelze sestrojit\n");
    }

    return 0;
}
