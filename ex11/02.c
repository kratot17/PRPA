#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void * b)
{
    return *((int *)a) > *((int *)b);
}

int main()
{
    int i = 0;
    int tmp;
    // na zacatku vytvorim pole velikosti jeden prvek, nebo taky ne
    int * p = NULL; // = malloc(sizeof(int));
    int * p_tmp;

    while (scanf("%i", &tmp) > 0)
    {
        p_tmp = realloc(p, (i+1)*sizeof(int));
        if (p_tmp != NULL)
        {
            p = p_tmp;
        }
        p[i++] = tmp;
    }

    qsort(p, i, sizeof(int), cmp);

    printf("pocet cisel: %i\n", i);

    for (int j = 0; j < i; j++)
    {
        printf("%i ", p[j]);
    }

    free(p);

    return 0;
    
}