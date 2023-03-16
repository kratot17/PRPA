#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = {'a', 'b'};
    char str2[] = "ab";
    char * str3[] = "ab";
    char * str4[] = "ab";
    printf("%p\n", str3);
    printf("%p\n", str4);
    str4 = "cd";
    printf("%p\n", str3);

    // str2 = "ahoj";

    char str5[5] = {0};
    strcpy(str5, "ahoj");
    printf("%s\n", str5);



    return 0;
}
