#include <stdio.h>

int main()
{
    int x = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%2i ", x++);
        }
        printf("\n");
    }
}
