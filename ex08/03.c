#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// dynamicka alokace na halde
// U = malloc(N) - alokace N bytu
// U = calloc(N, S) - alokace N prvku o velikosti S + nulovani
// U2 = realloc(U1, N) - realokace bloku pametu na adrese U na novou velikost N
// free(U) - dealokace bloku na adrese U

struct student 
{
    char jmeno[20];
    int vek;
};

int main()
{
    // pole 5 prvku typu int
    int * a = malloc(5*sizeof(int));
    char * b = (char *)a;  

    for (int i = 0; i < 20; i++) {
        b[i] = 1;
        // a[i] = 10 + i;
    }

    for (int i = 0; i < 5; i++) {
        printf("%i ", a[i]);
    }
    printf("\n");

    free(b);

    struct student * c = malloc(5*sizeof(struct student));

    strcpy(c[0].jmeno, "Josef");
    c[0].vek = 55;
    strcpy(c[1].jmeno, "Jan");
    c[1].vek = 20;

    return 0;

}