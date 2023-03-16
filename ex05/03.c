#include <stdio.h>

int main()
{
    // obecny N*M
    int N = 5, M = 6;

    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            printf(" ");
        }
        for (int k = 0; k < j; k++)
        {
            printf("*");
        }
        printf("\n");
    }
}
