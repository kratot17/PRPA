#include <stdio.h>
#include <stdlib.h>

void matrix_read(int s, int v, int m[s][v])
{
    int tmp;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < v; j++)
        {
            scanf("%i", &tmp);
            m[i][j] = tmp;
        }
    }
}

int * matrix_dynamix (int s, int v)
{
    int a;
    int * tmp = malloc(s*v*sizeof(int));

    for (int i = 0; i < s*v; i++)
    {
        scanf("%i", &a);
        tmp[i] = a;
    }
    return tmp;
}

int main()
{
    int sirka, vyska;
    int * maticeB;
    scanf("%i%i", &sirka, &vyska);
    printf("sirka: %i, vyska: %i\n", sirka, vyska);

    int maticeA[sirka][vyska];
    // matrix_read(sirka, vyska, maticeA);
    // printf("[1][1] = %i\n", maticeA[1][1]);
    maticeB = matrix_dynamix(sirka, vyska);
    for (int i = 0; i < sirka; i++)
    {
        for (int j = 0; j < vyska; j++)
        {
            printf("%2i ", maticeB[j+i*vyska]);
        }
        printf("\n");
    }
    int * maticeC = maticeB;
    // free(maticeB);
    free(maticeC);
    return 0;
}