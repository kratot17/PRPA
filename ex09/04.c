#include <stdio.h>
#include <stdlib.h>

// struktura reprezentujici 2D pole
struct pole
{
    int W, H;
    int * data;
};

struct pole matrix_init()
{
    struct pole tmp;
    // nejprve nactu velikost matice z datoveho souboru
    scanf("%i%i", &tmp.H, &tmp.W);
    printf("H: %i, W: %i\n", tmp.H, tmp.W);
    // inicializace datoveho uloziste
    tmp.data = calloc(tmp.W*tmp.H, sizeof(int));
    for (int i = 0; i < tmp.H*tmp.W; i++)
    {
        scanf("%i", &tmp.data[i]); 
    }
    return tmp;
}

void matrix_print(struct pole x)
{
    for (int i = 0; i < x.H; i++)
    {
        for (int j = 0; j < x.W; j++)
        {
            printf("%i ", x.data[j+i*x.W]);
        }
        printf("\n");
    }
}

int main()
{
    struct pole A, B;
    A = matrix_init();
    B = matrix_init();
    matrix_print(A);
    matrix_print(B);
    return 0;
}