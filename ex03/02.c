#include <stdio.h>

int main()
{
    char a;

    scanf("%c", &a);

    printf("a = '%c', ASCII = %i\n", a, a);

    if (a >= 'a' && a <= 'z')
    {
        printf("%c je male pismeno\n", a);
    }
    else if (a >= 'A' && a <= 'Z')
    {
        printf("%c je velke pismeno\n", a);
    }
    else if (a >= '0' && a <= '9')
    {
        printf("'%c' je cislo s hodnotou %i\n", a, a - '0');
    }

    return 0;
}
