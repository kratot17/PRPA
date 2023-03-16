#include <stdio.h>

int main()
// porovnat vstup s promenou, ktera slouzi jako pamet
{
    // decladation
    int vstup = 0, predchozi_cislo = 0, prvni = 1, pocet_opakovani = 1;

    // vstup
    while (scanf("%i", &vstup) != EOF)
    {
        if (vstup >= 0 && vstup <= 100)
        {
            if (prvni == 1)
            {
                prvni = 0;
            }
            else
            {
                if (vstup == predchozi_cislo)
                {
                    pocet_opakovani++;
                }
                else
                {
                    if (pocet_opakovani > 1)
                    {
                        printf("%ix %i\n", pocet_opakovani, predchozi_cislo);
                    }
                    pocet_opakovani = 1;
                }
            }
            predchozi_cislo = vstup;
        }
        else
        {
            if (pocet_opakovani > 1)
            {
                printf("%ix %i\n", pocet_opakovani, predchozi_cislo);
            }
            printf("Error: Vstup je mimo interval!\n");
            return 100;
        }
    }
    if (pocet_opakovani > 1)
    {
        printf("%ix %i\n", pocet_opakovani, predchozi_cislo);
    }
    return 0;
}
