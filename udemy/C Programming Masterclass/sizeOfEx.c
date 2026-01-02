#include <stdio.h>

int main()
{
    printf("Size of char: %d byte(s)\n", sizeof(char));
    printf("Size of int: %d byte(s)\n", sizeof(int));
    printf("Size of float: %d byte(s)\n", sizeof(float));
    printf("Size of double: %d byte(s)\n", sizeof(double));
    printf("Size of 'a': %d byte(s)\n", sizeof('a'));
    printf("Size of \"a\": %d byte(s)\n", sizeof("a"));

    int g1=60,g2=70;
    printf("Size of g1+g2: %d byte(s)\n", sizeof(g1+g2));
    return 0;
}