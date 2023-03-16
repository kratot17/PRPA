#include <stdio.h>

int main()
{
    char vstup = '0', predchozi_znak = '0';
    int pocet_opakovani = 0, poc_vstup_sym = 0, poc_zak_sym = 0;

    while (scanf("%c\n", &vstup) != EOF)
    {
        poc_vstup_sym++;

        if (pocet_opakovani == 255)
        {
            printf("%c%i", predchozi_znak, pocet_opakovani);
            pocet_opakovani = 0;
            poc_zak_sym += 4;
        }

        if (vstup != predchozi_znak) // jestlize nacteme jiny znak nez predchozi
        {
            if (pocet_opakovani > 2) // jestlize se znak opakoval vice nez 2x
            {
                printf("%c%i", predchozi_znak, pocet_opakovani);
                if (pocet_opakovani <= 9)
                    poc_zak_sym += 2;

                else if (pocet_opakovani > 9 && pocet_opakovani <= 99)
                    poc_zak_sym += 3;
                else
                    poc_zak_sym += 4;
            }
            else if (pocet_opakovani == 2)
            {
                printf("%c", predchozi_znak);
                printf("%c", predchozi_znak);
                poc_zak_sym += 2;
            }
            else if (pocet_opakovani == 1)
            {
                printf("%c", predchozi_znak);
                poc_zak_sym++;
            }
            pocet_opakovani = 1;
        }
        else
        {
            pocet_opakovani++;
        }

        predchozi_znak = vstup;

        if (vstup < 'A' || vstup > 'Z') // kontrola platneho vstupu
        {
            fprintf(stderr, "%s", "Error: Neplatny symbol!\n");
            return 100;
        }
    }

    if (pocet_opakovani > 2) // jestlize se znak opakoval vice nez 2x
    {
        printf("%c%i", predchozi_znak, pocet_opakovani);
        if (pocet_opakovani <= 9)
            poc_zak_sym += 2;

        else if (pocet_opakovani > 9 && pocet_opakovani <= 99)
            poc_zak_sym += 3;
        else
            poc_zak_sym += 4;
    }
    else if (pocet_opakovani == 2)
    {
        printf("%c", predchozi_znak);
        printf("%c", predchozi_znak);
        poc_zak_sym += 2;
    }
    else if (pocet_opakovani == 1)
    {
        printf("%c", predchozi_znak);
        poc_zak_sym++;
    }
    pocet_opakovani = 1;

    printf("\n");

    fprintf(stderr, "%s", "Pocet vstupnich symbolu: ");
    fprintf(stderr, "%i", poc_vstup_sym);
    fprintf(stderr, "%s", "\nPocet zakodovanych symbolu: ");
    fprintf(stderr, "%i", poc_zak_sym);
    fprintf(stderr, "%s", "\nKompresni pomer: ");
    fprintf(stderr, "%.2f", (float)poc_zak_sym / poc_vstup_sym);
    fprintf(stderr, "%s", "\n");

    return 0;
}
