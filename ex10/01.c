#include <stdio.h>
#include <string.h>

int main()
{
    char tmp[20];
    char hledam[] = "Messi";

    while (scanf("%s", tmp) > 0)
    {
        // tmp[2] = 0; // ~ '\0'
        // printf("%s %li %c\n", tmp, strlen(tmp), tmp[strlen(tmp)-1]);
        // char posledni = tmp[strlen(tmp)-1]; // znak na poslednim miste
        char * posledni = tmp+strlen(tmp)-1;
        if (!((*posledni >= 'A' && *posledni <= 'Z') || (*posledni >= 'a' && *posledni <= 'z')))
        {
            // pokud nepatri posledni znak retezce do povolene skupiny, nahradim ho koncem retezce
            // tmp[strlen(tmp)-1] = 0;
            *posledni = 0;
        }
        printf("%s\n", tmp);
        // if (tmp == hledam) nelze porovnavat promenne, protoze jsou to ruzne ukazatele
        if (strcmp(tmp, hledam) == 0)
        {
            printf("-> nasel jsem hledany retezec %s\n", hledam);
        }
    }
    return 0;
}