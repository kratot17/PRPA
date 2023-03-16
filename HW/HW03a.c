#include <stdio.h>
#include <limits.h>

int main()

{
    // decladation
    int vstup = 0, quan = 0, pos = 0, neg = 0, odd = 0, even = 0, sum = 0;
    int min = INT_MAX;
    int max = INT_MIN;

    // vstup
    while (scanf("%i", &vstup) != EOF)
    {
        quan++;
        if (vstup < -10000 || vstup > 10000)
        {
            // hlavni smicka
            printf("\nError: Vstup je mimo interval!\n");
            return 100;
        }

        if (vstup > 0)
            pos++;
        else if (vstup < 0)
            neg++;

        if (vstup % 2 == 0)
            even++;

        sum += vstup;

        if (vstup < min)
            min = vstup;
        if (vstup > max)
            max = vstup;

        if (quan == 1)
            printf("%i", vstup);
        else
            printf(", %i", vstup); // vypise cisla
    }

    odd = quan - even;

    printf("\nPocet cisel: %i\n", quan);
    printf("Pocet kladnych: %i\n", pos);
    printf("Pocet zapornych: %i\n", neg);
    printf("Procento kladnych: %.2f\n", (float)pos / quan * 100);
    printf("Procento zapornych: %.2f\n", (float)neg / quan * 100);
    printf("Pocet sudych: %i\n", even);
    printf("Pocet lichych: %i\n", odd);
    printf("Procento sudych: %.2f\n", (float)even / quan * 100);
    printf("Procento lichych: %.2f\n", (float)odd / quan * 100);
    printf("Prumer: %.2f\n", (float)sum / quan);
    printf("Maximum: %i\n", max);
    printf("Minimum: %i\n", min);

    return 0;
}
