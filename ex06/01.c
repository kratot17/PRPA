#include <stdio.h>

void funkce1 (int a)
{
    // funkce ma argument ciselneho datoveho typu
    // pri volani je predana hodnota a v tele funkce
    // je vytvorena lokalni promenna s nazvem totoznym
    // jako parametr
    printf("a = %i\n", a);
}

void funkce2 (int * a)
{
    // funkce ma argument typu ukazatel
    printf("%p\n", a);
    // protoze to je ale adresa(!), mohu pres dereferencni operator
    // menit obsah na adrese, ktera je hodnotou ukazatele
    *(a) = 2222;
}

void inkrementace (int * a)
{
    (*(a))++; // *(a++) vs. *(a)++
}

int main()
{
    // prommena je charakterizovana 
    // - hodnotou
    // - adresou (mistem) v pameti
    // prommena ciselneho datoveho typu: hodnota odpovidajici DT + adresa
    int a = 256; // adresa je &a  
    // prommenna typu ukazatel ma hodnotu typu adresa + svoji vlastni adresu
    int * p = &a;
    char * q = &a;
    // int * q = (int *)10;   // odpovida adrese v pocitaci 0xA
    // primy pristup - nazev promenne
    // pokud znam adresu, mohu pristoupit k datum neprimo
    // *(p) ~ a - defererecni operator vyhodnoti adresu
    printf("a = %i\n", *(p)); 
    printf("obsah p: %p\n", p);
    printf("*(q) = %i\n", *(q));
    printf("*(q) = %i\n", *(q+1));

    funkce1(55);
    funkce2(&a);
    printf("a = %i\n", a);

    for (int i = 0; i < 5; i++)
    {
        inkrementace(&a);
        printf("a = %i, %p\n", a, &a);
    }

    return 0;
}