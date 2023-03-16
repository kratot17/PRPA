#include <stdio.h>

int main()
{
    // pole je kolekce hodnot stejneho datoveho typu
    // jejich spolecnym znakem je adresa, kde pole zacina
    // adresa je soucasne nazvem pole

    // inicializace pole kompletnim vyctem, velikost
    // urci kompilator pri kompilaci
    int a[] = {1, 2, 3};

    for (int i = 0; i < 3; i++)
    {
        printf("%i ", a[i]);
    }
    printf("\n");

    // inicializace pole castecnym vyctem
    // bez uvedeni velikosti -> kompilator urci velikost sam
    int b[] = {[3] = 55}; // ctyrprvkove pole hodnot int
    // jak urcit velikost pole?
    // sizeof vraci, kolik bytu zabira prommenna v pameti
    for (int i = 0; i < sizeof(b)/sizeof(int); i++)
    {
        printf("%i ", b[i]);
    }
    printf("\n");

    // inicializace pole castecnym vyctem s uvedenim velikosti
    int c[5] = {[1] = 33};
    for (int i = 0; i < sizeof(c)/sizeof(int); i++)
    {
        printf("%i ", c[i]);
    }
    printf("\n");

    int d = 10;
    printf("%p\n", d);  // d je je hodnota typu int, tento zapis nedava smysl
    printf("%p\n", a);
    printf("%i\n", *(a));

    int N = 3;
    // hodnota N musi(!) byt znama ve chvili, kdy VLA vytvarim
    // VLA nelze inicializovat pri deklaraci
    int e[N];

    for (int i = 0; i < sizeof(e)/sizeof(int); i++)
    {
        e[i] = i;
    }

    for (int i = 0; i < sizeof(e)/sizeof(int); i++)
    {
        printf("%i ", e[i]);
    }
    printf("\n");

    return 0;
}