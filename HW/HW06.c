#include <stdio.h>
#include <stdlib.h>

int scan_line(char *p, int array_length)
{
    scanf("%*c"); // skip the '\n' character
    for (int i = 0; i < array_length; i++)
    {
        char letter = 0;
        scanf("%c", &letter);
        if (letter == '\n') // check if there's '\n'
        {
            fprintf(stderr, "%s", "Error: Chybna delka vstupu!");
            return 101;
        }
        else if (!(((letter >= 'a') && (letter <= 'z')) || ((letter >= 'A') && (letter <= 'Z')))) // check for numbers
        {
            fprintf(stderr, "%s", "Error: Chybny vstup!");
            return 100;
        }
        *(p + i) = letter;
    }
    return 0;
}

void prnt_carray(char *p, int array_length)
{
    for (int i = 0; i < array_length; i++)
    {
        printf("%c", *(p + i));
    }
    printf("\n");
}

void prnt_iarray(int *p, int array_length)
{
    for (int i = 0; i < array_length; i++)
    {
        printf("%i", *(p + i));
    }
    printf("\n");
}

void shift(char *src, char *dst, int offset)
{
    for (int i = 0; i < offset; i++)
    {
        if (*src == 'Z')
            *dst = 'a'; // shifts to lc
        else if (*src == 'z')
            *dst = 'A'; // returns to capital
        else
            *dst = (*src) + 1;
    }
}

void rotate(char *array, int offset, int array_length)
{
    for (int i = 0; i < array_length; i++)
    {
        shift(array + i, array + i, offset);
    }
}

void cpy_array(char *src, char *dst, int array_length)
{
    for (int i = 0; i < array_length; i++)
    {
        *(dst + i) = *(src + i);
    }
}

void freee(char *frst, char *scnd, char *thrd, short *frth)
{
    free(frst);
    free(scnd);
    free(thrd);
    free(frth);
}

int main()
{
    int array_length = 0, ret = 0, counter = 0, attempts = 50, matches = 0, max_val = 0;

    if (scanf("%i", &array_length) != 1)
    {
        fprintf(stderr, "%s", "Error: Chybny vstup!");
        return 100;
    }

    char *cipher = calloc(sizeof(char), array_length);
    char *stub = calloc(sizeof(char), array_length);
    char *tmp = calloc(sizeof(char), array_length);
    short *results = calloc(sizeof(short), attempts);

    // char cipher[array_length];
    // char stub[array_length];
    // char tmp[array_length];
    // int results[attempts];

    ret = scan_line(cipher, array_length);
    if (ret == 100)
    {
        freee(cipher, stub, tmp, results);
        return 100;
    }
    else if (ret == 101)
    {
        freee(cipher, stub, tmp, results);
        return 101;
    }

    cpy_array(cipher, tmp, array_length); // copies cipher to tmp

    ret = scan_line(stub, array_length);
    if (ret == 100)
    {
        return 100;
        freee(cipher, stub, tmp, results);
    }
    else if (ret == 101)
    {
        freee(cipher, stub, tmp, results);
        return 101;
    }

    for (int i = 0; i < attempts; i++) // scaning cycle
    {
        for (int j = 0; j < array_length; j++) // checks for matches
        {
            if (*(tmp + j) == *(stub + j))
                matches++;
        }
        // printf("%02i matches: %i ", i, matches);
        // prnt_carray(tmp, array_length);
        results[i] = matches;
        matches = 0;
        rotate(tmp, 1, array_length);
    }

    for (int i = 0; i < attempts - 1; i++) // result cycle
    {
        if (results[i] > max_val)
        {
            counter = i;
            max_val = results[i];
        }
    }

    // printf("results: ");
    // prnt_iarray(results, attempts);
    // printf("top result: %ith iteration\n", counter);

    rotate(cipher, counter, array_length);
    prnt_carray(cipher, array_length);

    freee(cipher, stub, tmp, results);

    return 0;
}
