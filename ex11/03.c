#include <stdio.h>
#include <stdlib.h>

struct hodnota
{
    int data;
    int opakovani;
};

int cmp(const void * a, const void * b)
{
    // return ((struct hodnota *)a)->opakovani < ((struct hodnota *)b)->opakovani;
    return ((struct hodnota *)a)->data < ((struct hodnota *)b)->data;
}

int main()
{
    int tmp;
    struct hodnota * kolekce = NULL;
    int i = 0;
    int nalezeno = 0;

    while (scanf("%i", &tmp) > 0)
    {
        // projdu kolekci a zjistim, jestli tam cislo uz je
        for (int j = 0; j < i; j++)
        {
            if (kolekce[j].data == tmp)
            {
                // printf("opakovani: i: %i, j: %i, tmp: %i\n", i, j, tmp);
                // nalezl jsem vyskyt cisla v kolekci a tudiz inkrementuju opakovani
                kolekce[j].opakovani += 1;
                nalezeno = 1;
                break;
            }
        }
        if (nalezeno == 1)
        {
            nalezeno = 0; 
            continue;
        }
        // pokud jsem se dotal na toto misto v kodu, znamena to, ze cislo jeste v kolekci neni
        // printf("nove: i: %i tmp: %i\n", i, tmp);
        kolekce = realloc(kolekce, (i+1)*sizeof(struct hodnota));
        kolekce[i].data = tmp;
        kolekce[i].opakovani = 1;
        i++;
    }

    qsort(kolekce, i, sizeof(struct hodnota), cmp);

    for (int j = 0; j < i; j++)
    {
        printf("%-10i%i\n", kolekce[j].data, kolekce[j].opakovani);
    }

    free(kolekce);
}
