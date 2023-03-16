#include <stdio.h>
#include <limits.h>

int main()
{
    int a, r = 0, max = INT_MIN;

    /*
    while (r != -1)
    {
        r = scanf("%i", &a);
        if (r == 1)
        {
            printf("-> %i\n", a);
        }
    }
    */

    // while (scanf("%i", &a) > 0 )
    // {
    //     printf("-> %i\n", a);
    //     if (a > max)
    //     {   
    //         max = a;
    //     }
    // }
    // printf("maximum: %i\n", max);
    int poprve = 1;
    while (scanf("%i", &a) > 0 )
    {
        printf("-> %i\n", a);
        if (a > max)
        {   
            max = a;
        }
    }
    printf("maximum: %i\n", max);

    return 0;
}
