#include <stdio.h>

// square
void square(int a)
{
    for (int i = 0; i < a; i++)
    {
        if (i == 0 || i == a - 1) // pokud se jedna o prvni, nebo posledni radek
        {
            for (int j = 0; j < a; j++)
            {
                printf("X");
            }
        }
        else
        {
            for (int j = 0; j < a; j++)
            {
                if (j == 0 || j == a - 1) // pokud se jedna o krajni znaky
                    printf("X");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
}

// house
int house(int a, int b)
{
    int counter = 0; // pro vypln
    if (a % 2 == 0)  // pokud je a sude
    {
        return 102;
    }

    for (int j = 0; j < (a - 1) / 2; j++) // prvni radek
    {
        printf(" ");
    }
    printf("X\n");

    for (int i = 1; i < (a - 1) / 2; i++) // ostatni radky
    {
        for (int j = 0; j < (a - 1) / 2 - i; j++) // mezery pred strechou
        {
            printf(" ");
        }
        printf("X");

        for (int k = 0; k < 2 * (i - 1) + 1; k++) // mezery uvnitr strechy
        {
            printf(" ");
        }
        printf("X\n");
    }

    if (a == b) // vyplnit domek
    {
        for (int i = 0; i < b; i++)
        {
            if (i == 0 || i == b - 1) // pokud se jedna o prvni, nebo posledni radek
            {
                for (int j = 0; j < a; j++)
                {
                    printf("X");
                }
            }
            else
            {
                for (int j = 0; j < a; j++)
                {
                    if (j == 0 || j == a - 1) // pokud se jedna o krajni znaky
                        printf("X");
                    else
                    {
                        if (counter % 2 == 0)
                            printf("o");
                        else
                            printf("*");
                        counter++;
                    }
                }
            }
            printf("\n");
        }
    }
    else // bez vzplne
    {
        for (int i = 0; i < b; i++)
        {
            if (i == 0 || i == b - 1) // pokud se jedna o prvni, nebo posledni radek
            {
                for (int j = 0; j < a; j++)
                {
                    printf("X");
                }
            }
            else
            {
                for (int j = 0; j < a; j++)
                {
                    if (j == 0 || j == a - 1) // pokud se jedna o krajni znaky
                        printf("X");
                    else
                        printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}

int fancy_house(int a, int b, int c)
{
    int counter = 0;       // pro vypln
    int fance_counter = 0; // pro planky plotu
    int row = 1;
    if (a % 2 == 0) // pokud je a sude
    {
        return 102;
    }
    if (c >= b || c < 0)
    {
        return 103;
    }

    for (int j = 0; j < (a - 1) / 2; j++) // prvni radek
    {
        printf(" ");
    }
    printf("X\n");

    for (int i = 1; i < (a - 1) / 2; i++) // ostatni radky
    {
        for (int j = 0; j < (a - 1) / 2 - i; j++) // mezery pred strechou
        {
            printf(" ");
        }
        printf("X");

        for (int k = 0; k < 2 * (i - 1) + 1; k++) // mezery uvnitr strechy
        {
            printf(" ");
        }
        printf("X\n");
    }

    if (a == b) // vyplnit domek
    {
        for (int i = 0; i < b; i++)
        {
            if (i == 0 || i == b - 1) // pokud se jedna o prvni, nebo posledni radek
            {
                for (int j = 0; j < a; j++)
                {
                    printf("X");
                }
            }
            else
            {
                for (int j = 0; j < a; j++)
                {
                    if (j == 0 || j == a - 1) // pokud se jedna o krajni znaky
                        printf("X");
                    else
                    {
                        if (counter % 2 == 0)
                            printf("o");
                        else
                            printf("*");
                        counter++;
                    }
                }
            }
            if (row == (b - c + 1)) // prvni radek plotu
            {
                for (int i = 0; i < c; i++)
                {
                    if (fance_counter % 2 == 0)
                    {
                        if (c % 2 == 0) // hlida, aby na posledni pozici byla "|"
                            printf("-");
                        else
                            printf("|");
                    }
                    else
                    {
                        if (c % 2 == 0) // hlida, aby na posledni pozici byla "|"
                            printf("|");
                        else
                            printf("-");
                    }
                    fance_counter++;
                }
                fance_counter = 0;
            }
            else if (row > (b - c + 1) && row < b) // stred plotu
            {
                for (int i = 0; i < c; i++)
                {
                    if (fance_counter % 2 == 0)
                    {
                        if (c % 2 == 0) // hlida, aby na posledni pozici byla "|"
                            printf(" ");
                        else
                            printf("|");
                    }
                    else
                    {
                        if (c % 2 == 0) // hlida, aby na posledni pozici byla "|"
                            printf("|");
                        else
                            printf(" ");
                    }
                    fance_counter++;
                }
                fance_counter = 0;
            }
            else if (row == b)
            {
                for (int i = 0; i < c; i++)
                {
                    if (fance_counter % 2 == 0)
                    {
                        if (c % 2 == 0) // hlida, aby na posledni pozici byla "|"
                            printf("-");
                        else
                            printf("|");
                    }
                    else
                    {
                        if (c % 2 == 0) // hlida, aby na posledni pozici byla "|"
                            printf("|");
                        else
                            printf("-");
                    }
                    fance_counter++;
                }
                fance_counter = 0;
            }
            printf("\n");
            row++;
        }
    }
    else // bez vzplne
    {
        for (int i = 0; i < b; i++)
        {
            if (i == 0 || i == b - 1) // pokud se jedna o prvni, nebo posledni radek
            {
                for (int j = 0; j < a; j++)
                {
                    printf("X");
                }
            }
            else
            {
                for (int j = 0; j < a; j++)
                {
                    if (j == 0 || j == a - 1) // pokud se jedna o krajni znaky
                        printf("X");
                    else
                        printf(" ");
                }
            }
            if (row == (b - c + 1)) // prvni radek plotu
            {
                for (int i = 0; i < c; i++)
                {
                    if (fance_counter % 2 == 0)
                    {
                        if (c % 2 == 0) // hlida, aby na posledni pozici byla "|"
                            printf("-");
                        else
                            printf("|");
                    }
                    else
                    {
                        if (c % 2 == 0) // hlida, aby na posledni pozici byla "|"
                            printf("|");
                        else
                            printf("-");
                    }
                    fance_counter++;
                }
                fance_counter = 0;
            }
            else if (row > (b - c + 1) && row < b) // stred plotu
            {
                for (int i = 0; i < c; i++)
                {
                    if (fance_counter % 2 == 0)
                    {
                        if (c % 2 == 0) // hlida, aby na posledni pozici byla "|"
                            printf(" ");
                        else
                            printf("|");
                    }
                    else
                    {
                        if (c % 2 == 0) // hlida, aby na posledni pozici byla "|"
                            printf("|");
                        else
                            printf(" ");
                    }
                    fance_counter++;
                }
                fance_counter = 0;
            }
            else if (row == b)
            {
                for (int i = 0; i < c; i++)
                {
                    if (fance_counter % 2 == 0)
                    {
                        if (c % 2 == 0) // hlida, aby na posledni pozici byla "|"
                            printf("-");
                        else
                            printf("|");
                    }
                    else
                    {
                        if (c % 2 == 0) // hlida, aby na posledni pozici byla "|"
                            printf("|");
                        else
                            printf("-");
                    }
                    fance_counter++;
                }
                fance_counter = 0;
            }
            printf("\n");
            row++;
        }
    }
    return 0;
}

int main()
{
    int input = 0, num0 = 0, num1 = 0, num2 = 0, input_index = 0, hodnota_scan = 0, ret_val;
    // input_index reprezentuje poradi cila na ktere se zapisuje

    while (1) // smycka nacitani vstupu
    {
        hodnota_scan = scanf("%i", &input);

        if (hodnota_scan == 1)
        {
            if (input >= 3 && input <= 69) // kontrola intervalu
            {
                if (input_index == 0)
                    num0 = input;
                else if (input_index == 1)
                    num1 = input;
                else if (input_index == 2)
                    num2 = input;
                input_index++;
            }
            else
            {
                fprintf(stderr, "%s", "Error: Vstup mimo interval!\n");
                return 101;
            }
        }
        else if (hodnota_scan == EOF)
        {
            break;
        }
        else // vstup neni int
        {
            fprintf(stderr, "%s", "Error: Chybny vstup!\n");
            return 100;
        }
    }

    // printf("num0: %i\n", num0);
    // printf("num1: %i\n", num1);
    // printf("num2: %i\n", num2);
    // printf("input_index: %i\n", input_index);

    if (input_index == 1)
    {
        square(num0);
    }
    else if (input_index == 2)
    {
        if (house(num0, num1) == 102)
        {
            fprintf(stderr, "%s", "Error: Sirka neni liche cislo!\n");
            return 102;
        }
    }
    else if (input_index == 3)
    {
        ret_val = fancy_house(num0, num1, num2);
        if (ret_val == 102)
        {
            fprintf(stderr, "%s", "Error: Sirka neni liche cislo!\n");
            return 102;
        }
        else if (ret_val == 103)
        {
            fprintf(stderr, "%s", "Error: Neplatna velikost plotu!\n");
            return 103;
        }
    }

    return 0;
}
