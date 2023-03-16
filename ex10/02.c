#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int cmp(const void * a, const void * b)
{
    return strcmp(a, b);
}

int main()
{
    char tmp[20];
    char * slovnik[11];
    int i;

    while (scanf("%s", tmp) > 0)
    {
        /* 
            1. nactu retezec do promenne tmp
            2. nakopiruju ho nekam do pameti. kam? -> dynamicka alokace
            3. ukazatel z dynamicke alokace pouziju jako ukazatel ve slovniku
        */
       slovnik[i] = malloc(strlen(tmp)+1);
       if (tmp[0] >= 'A' && tmp[0] <= 'Z')
       {
            // tmp[0] += ('a' - 'A');
            // bitova maska: (1 << 5)   0b00000001 -> 0b00100000
            tmp[0] |= (1<<5);
       }
       strcpy(slovnik[i], tmp);
       i++; 
    }
    // bubble sort pro serazeni podle velikosti
    // qsort (slovnik, 11, sizeof(char *), cmp);
    
    for (int a = 0; a < 11; a++)
    {
        for (int b = 0; b < 10; b++)
        {
            if (strcmp(slovnik[b], slovnik[b+1]) > 0)
            // if (strlen(slovnik[b]) > strlen(slovnik[b+1]))
            {
                char * t = slovnik[b];
                slovnik[b] = slovnik[b+1];
                slovnik[b+1] = t;
            }
        }
    }
    
    for (int x = 0; x < i; x++)
    {
        printf("%s\n", slovnik[x]);
    }
    return 0;
}   
