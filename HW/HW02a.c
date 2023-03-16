#include <stdio.h>

int main()

{
    // inicializace
    int first_num, sec_num;

    // vstup
    scanf("%i %i", &first_num, &sec_num);

    if (first_num <= 10000 && first_num >= -10000 && sec_num <= 10000 && sec_num >= -10000)
    {
        // Hlavni smicka
        printf("Desitkova soustava: %i %i\n", first_num, sec_num);
        printf("Sestnactkova soustava: %x %x\n", first_num, sec_num);
        printf("Soucet: %i + %i = %i\n", first_num, sec_num, first_num + sec_num);
        printf("Rozdil: %i - %i = %i\n", first_num, sec_num, first_num - sec_num);
        printf("Soucin: %i * %i = %i\n", first_num, sec_num, first_num * sec_num);
        if (sec_num == 0)
        {
            printf("Nedefinovany vysledek!\n");
        }
        else
        {
            printf("Podil: %i / %i = %i\n", first_num, sec_num, first_num / sec_num);
        }
        printf("Prumer: %.1f\n", (float)(first_num + sec_num) / 2);
    }
    else
    {
        printf("Vstup je mimo interval!\n");
    }

    return 0;
}
