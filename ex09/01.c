#include <stdio.h>

int main()
{
    int a[] = {1, 2, 3, 4};
    int b[] = {5, 6, 7, 9};

    // pole ukazatelu na int
    int * p[3];

    int c[4] = {10, 11, 12, 13};

    p[0] = a;
    p[1] = b;
    p[2] = c;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%i ", p[i][j]);
        }
        printf("\n");
    }
}