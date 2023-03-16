#include <stdio.h>

int main()
{
    int x = 1;

    for (int i = 0; i < 10; i++)
    {
        printf("%i ", x);
        x = x * -1;
    }
    printf("\n");
    // druhy zpusob 
    for (int i = 0; i < 10; i++)
    {
        // if ((i%2) == 1) // i je liche
        // {
        //     printf("1 ");
        // }
        // else
        // {
        //     printf("-1 ");
        // }

        printf("%i ", ((i % 2) == 0) ? 1 : -1);
    }
    printf("\n");
    return 0;
}
