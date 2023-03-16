#include <stdio.h>

int main()
{
    int i = 11; // ridici promenna cyklu

    while (i > 0)
    {
        printf("%i ", i);
        // i = i - 1; //zmena ridici promenne
        // i -= 1; //zkraceny operator
        // i --; //dekrementace
        i -= 1;
        if ((i % 2) == 0)
        {
            printf("%i ", i);
        }
    }

    for (int p = 0; p < 5; p++)
    {
        printf("p = %i\n", p);
    }

    printf("\n");

    return 0;
}
