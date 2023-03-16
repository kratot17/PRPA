#include <stdio.h>

struct komplex
{
    float re;
    float im;
};

// typedef int numeric;

typedef struct 
{
    float re, im;
} complex;

struct komplex soucet (struct komplex A, struct komplex B)
{
    struct komplex tmp;
    tmp.re = A.re + B.re;
    tmp.im = A.im + B.im;
    return tmp;
}

void komplex_soucet (struct komplex A, struct komplex B, struct komplex * C)
{
    // ukazacel na primit. datovy typ, napr. int * a
    // dereference *(a)
    (*C).re = A.re + B.re;
    (*C).im = A.im + B.im;
    C->re = A.re + B.re;
    C->im = A.im + B.im;    
}

void komplex_print (struct komplex X)
{
    printf("%.2f%+.2fj\n", X.re, X.im);
}

int main()
{
    complex d = {3.14, -10};
    // deklarace bez inicializace, hodnota nastavena v programu po slozkach
    struct komplex a;
    // inicializace vyctem vsech hodnot
    struct komplex b = {10.5, -6.3};
    // inicializace castecnym vyctem, nevyjmenovane slozky inic. na 0
    struct komplex c = {.im = 20.0};
    // a ~ 2.0 + 3.1j
    a.im = 3.1;
    a.re = 2.0;

    komplex_print (a);
    komplex_print (b);

    c = soucet (a, b);
    komplex_print(c);

    komplex_soucet(a, b, &c);
    komplex_print(c);

    return 0;
}
