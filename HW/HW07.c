#include <stdio.h>
#include <string.h>

int matrix_init(int *p, int H, int W)
{
    for (int i = 0; i < H * W; i++)
    {
        if (scanf("%i", &p[i]) == 0)
        {
            return 100;
        }
    }
    return 0;
}
void prnt_matrix(int *p, int H, int W)
{
    printf("%i %i\n", H, W);
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            printf("%i", p[j + i * W]);
            if (j != (W - 1))
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
char get_sign()
{
    char sign;
    scanf("%*c"); // skip the '\n' character
    scanf("%c", &sign);
    // try scanf("%c\n", &sign);
    scanf("%*c");
    return sign;
}
void calc(int *A, int H_A, int W_A, int *B, int H_B, int W_B, int *result, char sign)
{
    if (sign == '-')
    {
        for (int i = 0; i < (H_A * W_A); i++)
        {
            result[i] = A[i] - B[i];
        }
    }
    else if (sign == '+')
    {
        for (int i = 0; i < (H_A * W_A); i++)
        {
            result[i] = A[i] + B[i];
        }
    }
    if (sign == '*')
    {
        for (int i = 0; i < H_A; i++)
        {
            for (int j = 0; j < W_B; j++)
            {
                for (int k = 0; k < W_A; k++)
                {
                    result[j + i * W_B] += A[k + i * W_A] * B[j + k * W_B];
                }
            }
        }
    }
}
int main()
{
    int H_A = 0, W_A = 0, H_B = 0, W_B = 0;
    char sign = 0;

    scanf("%i%i", &H_A, &W_A);
    int A[H_A * W_A];
    if (matrix_init(A, H_A, W_A) == 100) // check for errors
    {
        fprintf(stderr, "%s", "Error: Chybny vstup!\n");
        return 100;
    }

    sign = get_sign();

    scanf("%i%i", &H_B, &W_B);
    int B[H_B * W_B];
    if (matrix_init(B, H_B, W_B) == 100) // check for errors
    {
        fprintf(stderr, "%s", "Error: Chybny vstup!\n");
        return 100;
    }

    if ((sign == '+') || (sign == '-'))
    {
        if ((W_A != W_B) || (H_A != H_B)) // check for right dimentions
        {
            fprintf(stderr, "%s", "Error: Chybny vstup!\n");
            return 100;
        }
        int result[H_A * W_A];
        memset(result, 0, sizeof(result));
        calc(A, H_A, W_A, B, H_B, W_B, result, sign);
        prnt_matrix(result, H_A, W_A);
    }
    else if (sign == '*')
    {
        if (W_A != H_B) // check for right dimentions
        {
            fprintf(stderr, "%s", "Error: Chybny vstup!\n");
            return 100;
        }
        int result[H_A * W_B];
        memset(result, 0, sizeof(result));
        calc(A, H_A, W_A, B, H_B, W_B, result, sign);
        prnt_matrix(result, H_A, W_B);
    }

    return 0;
}
