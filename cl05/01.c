#include <stdio.h>

int main()

{
    int a, b = -1, prvni = 1;

    while (scanf("%i", &a) > 0)
    {
        if (prvni == 1)
        {
            // nacetl jsem prvni cislo
            printf("-> %i\n", a);
        }
        else
        {
            printf("-> %i (%i)\n", a, b);

            //comm
            
        }
        prvni = 0;
    }
    return 0;
}
