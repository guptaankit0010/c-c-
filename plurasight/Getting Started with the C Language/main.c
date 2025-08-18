#include <stdio.h>
#include <string.h>


void swap(int *a, int *b);

int main()
{
    printf("tdds\n");
    char n1[5] = "ccc";
    printf("%s\n", n1);
    printf("%c---%p\n", n1[2], &n1[2]);
    printf("%c---%p\n", n1[3], &n1[3]);
    printf("%c---%p\n", n1[4], &n1[4]);
    printf("%c---%p\n", n1[5], &n1[5]);

    printf("length of n1 ==%ld\n", strlen(n1));
    printf("szie of n1 ==%ld\n", sizeof(n1));
    // printf("%c\n",n1[5]);

    char n2[40] = "LLL";
    char n3[60];
    strcat(n3, n1);
    strcat(n3, n2);
    printf("%c---%p\n", n3[4], &n3[4]);
    printf("%c---%p\n", n3[5], &n3[5]);
    printf("length of n1 ==%ld\n", strlen(n3));
    printf("szie of n1 ==%ld\n", sizeof(n3));

    int a1;
    int a2 = (a1 = 2);
    printf("%d---%p\n", a2, &a2);

    int x = 20, y = 10;
    swap(&x, &y);
    printf("x = %d,y= %d\n", x, y);
    return 0;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}