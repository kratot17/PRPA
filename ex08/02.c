#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// priklad popisuje vyuziti pole a struktury

struct student
{
    char jmeno[20];
    char * prijmeni;
    char * vesnice;
    int vek; 
};

int main()
{
    struct student paralelka[20];

    char * jmena[20] = {"Adam", "Josef", "Milos", "Pavel", "Bronislav"};
    char * prijmeni[20] = {"Novak", "Bures", "Sedlacek", "Pilny", "Stavitel"};
    char * vesnice[20] = {"Praha", "Brno", "Ostrava", "Olomouc", "Plzen"};
/*
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", jmena[i]);
    }
*/
    for (int i = 0; i < 5; i++)
    {
        // paralelka[i].jmeno = jmena[i]; - nelze kopirovat pole do pole
        strcpy (paralelka[i].jmeno, jmena[i]);
        // ve strukture muzu mit ukazatel na existujici zaznam v pameti pro retezce
        paralelka[i].prijmeni = prijmeni[i];
        // ve strukture muzu mit ukazatel na dynamicky alokovane pole, do ktereho nakopiruji text
        paralelka[i].vesnice = malloc(20);
        strcpy(paralelka[i].vesnice, vesnice[i]);
        paralelka[i].vek = 19;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%-10s %-10s vek: %i, vesnice: %s\n", 
        paralelka[i].jmeno, paralelka[i].prijmeni, paralelka[i].vek, paralelka[i].vesnice);
    }

    // adresy retezcu ve strukture
    printf("%p\n", paralelka[0].jmeno);
    printf("%p\n", paralelka[0].prijmeni);
    printf("%p\n", paralelka[0].vesnice);

    // dealokace (uvolneni) dyn. alokovane pameti
    for (int i = 0; i < 5; i++)
        free(paralelka[i].vesnice);

    return 0;
}
