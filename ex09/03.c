#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;      // cislo nactene ze standardniho vstupu
    int r = 0;  // citac nactenych cisel
    int i = -1;  // i-ty vektor
    int j = 0;
    // jednoprvkove pole ukazatelu na ukazatele na int
    int ** p = malloc(sizeof(int **));
    // proc ukazatel na ukazatel?
    // protoze obsahuje adresy poli, ktere jsou jiz ukazateli

    while (scanf("%i", &a) > 0)
    {
        // pokud r je 0, 4, 8, ... je treba inicializovat novy vektor
        // nebo pokud pokud r%4 je nula 
        if (r%4 == 0) 
        {
            i++;
            // realokuji pole na velikost o jeden (int **) vetsi
            p = realloc(p, (i+1)* sizeof(int **));
            // nacetl jsem prvni cislo vektoru -> je treba vektor inicializovat
            p[i] = malloc(4 * sizeof(int));
            j = 0;
        }
        p[i][j++] = a;
        r++;
    }
    printf("pocet vektoru: %i\n", i+1);

    for (int ii = 0; ii < i+1; ii++)
    {
        for (int jj = 0; jj < 4; jj++)
        {
            printf("%i ", p[ii][jj]);
        }
        printf("\n");
    }

    for (int ii = 0; ii < i+1; ii++)
    {
        // dealokuji jednotlive radky
        free(p[ii]);
    }
    // dealokuji pole ukazatelu na jednotlive radky
    free(p);

    return 0;
}