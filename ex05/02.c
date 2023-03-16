#include <stdio.h>

float pi(int iterace)
{
    int N = 10000000;
    int citatel, jmenovatel;
    float suma = 0;
    // (-1)^k / 2k + 1, k = <0, N>
    for (int k = 0; k < iterace; k++)
    {
        citatel = ((k % 2) == 0) ? 1 : -1;
        jmenovatel = 2 * k + 1;
        suma += (float)citatel / jmenovatel;
    }
    return 4 * suma;
}

int main()
{
    int N = 1000;
    for (int i = 0; i < 10; i++)
    {
        printf("pi = %f (N = %i)\n", pi(N), N);
        N += 100000;
    }
    return 0;
}
