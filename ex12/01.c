#include <stdio.h>
#include <stdlib.h>

// spojovy seznam

// data     data    data
// |next| -> next 
struct uzel
{
    int data;
    struct uzel *next;
};

int main()
{
    // nas seznam bude tvoren tremi uzly
    struct uzel a, b, c;
    a.data = 10;
    b.data = 11;
    c.data = 13;

    a.next = &b;
    b.next = &c;
    c.next = NULL;

    printf("a: %i\n,"a.data);
    printf("b: %i, "a.next);
    printf("c: %i, "a.data);

    return 0;
}
