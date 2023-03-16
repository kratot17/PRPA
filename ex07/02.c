#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
    printf("%s\n", argv[0]);
    printf("%s\n", argv[1]);
    int velikost, r;
    // nacteme z STDIN nacteme velikost pole
    r = scanf("%i", &velikost);
    if (r != 1)
    {
        return 100;
    }
    // vytvorim VLA
    int a[velikost];
    printf("velikost pole (B) = %ld\n", sizeof(a));
    memset(a, 0, sizeof(a));

    for (int i = 0; i < sizeof(a)/sizeof(int); i++)
    {
        scanf("%i", &a[i]);
        printf("%i ", a[i]);
    }
    printf("\n");
    
    for (int j = 0; j < sizeof(a)/sizeof(int); j++)
    {
        int vymena = 0;
        for (int i = 0; i < sizeof(a)/sizeof(int)-1; i++)
        {
            if (a[i] < a[i+1])
            {
                vymena = 1;
                int tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
            }
        }
        if (vymena == 0)
        {
            break;
        }
        for (int i = 0; i < sizeof(a)/sizeof(int); i++)
        {
            printf("%i ", a[i]);
        }
        printf("\n");
    }
    int N =4;
    printf("%i-te nejvetsi cislo je %i\n", N, a[velikost-N]);

    return 0;
}