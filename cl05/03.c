#include <stdio.h>



int main()
{
    int a = 10;
    int * p = &a; //hvezdicak je soucast nazvu datoveho typu
    char b = 

    printf("%p\n", p);

    printf("a = %i\n", a);
    // a = 20;
    * p = 20; //dereferencni operator
    printf("a = %i\n", a);
}
