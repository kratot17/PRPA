#include <stdio.h>

int main()

{
    // inicializace
    int a, b, c, d;

    // vstup
    scanf("%i %i %i", &a, &b, &c);

    d = (b * b - 4 * a * c);

    if (d >= -999 && d <= 999)
    {
        // tisk tabulky
        printf("+-----+-----+-----+-----+\n");
        printf("|%4i |%4i |%4i |%4i |\n", a, b, c, d);
        printf("+-----+-----+-----+-----+\n");
        if (d < 0)
        {
            printf("| Dva imaginarni koreny |\n");
        }
        else if (d == 0)
        {
            printf("|           Jeden koren |\n");
        }
        else
        {
            printf("|     Dva realne koreny |\n");
        }
        printf("+-----------------------+\n");
    }
    else
    {
        printf("Diskriminant mimo povoleny interval!\n");
    }

    return 0;
}
