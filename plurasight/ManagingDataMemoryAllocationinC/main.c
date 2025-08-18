#include <stdio.h>
#include <stdlib.h>

void badMalloc(int *numP);
void safeMalloc(int **numP);

typedef struct
{
    char name[10];
    void (*greet)();
} Person;

typedef struct
{
    char name[10];

} DblP;

void greet1();
void greet2();

int main(int arg, char *argc[])
{
    int count = 4;

    // malloc for 4 int
    int *n1 = (int *)malloc(count * sizeof(int));

    for (int i = 0; i < count; i++)
    {
        *(n1 + i) = i;
        printf("value = %d , addr = %p \n", *(n1 + i), n1 + i);
    }
    printf("\n\n");
    // calloc for 4 int
    int *n2 = (int *)calloc(count, sizeof(int));

    for (int i = 0; i < count; i++)
    {
        printf("value = %d , addr = %p \n", *(n2 + i), n2 + i);
        *(n2 + i) = i;
        printf("value = %d , addr = %p \n", *(n2 + i), n2 + i);
    }

    printf("\n\n");

    // realloc
    n2 = (int *)realloc(n2, (count + 2) * sizeof(int));

    for (int i = 0; i < count + 2; i++)
    {
        if (i >= count)
        {
            printf("value = %d , addr = %p \n", *(n2 + i), n2 + i);
            *(n2 + i) = i;
            printf("value = %d , addr = %p \n", *(n2 + i), n2 + i);
        }
    }
    printf("\n\n");

    free(n1);
    free(n2);

    int num = 10;
    int *numP = &num;

    badMalloc(numP);
    safeMalloc(&numP);
    void (*greet)();
    if (arg > 1)
    {
        greet = &greet2;
    }
    else
    {
        greet = &greet1;
    }

    Person p1 = {"ankit", greet};
    p1.greet();

    DblP **testDblP = (DblP **)malloc(2 * sizeof(DblP));
    DblP **testDblP1 = (DblP **)malloc(2 * sizeof(DblP));
    DblP **testDblP2 = (DblP **)malloc(2 * sizeof(DblP));
    DblP pp1 = {"asasassa"};
    // DblP *pp1ptr = &pp1;
    *testDblP = &pp1;
    return 0;
}

void badMalloc(int *numP)
{
    // this creates new local pointer on stack which points to some memory on heap
    // this does not modify pointer to num
    // this will cause memory leak even if free(numP) is used as numP freed will be the original numP in main
    // and this local new copy will continue unfreed
    numP = (int *)malloc(sizeof(int));
    printf("\n");
}

void safeMalloc(int **numP)
{
    // this modifies the pointer to num variable and now pointer variables points to some diff mem locstion on heap
    // this will not cause mem leak if free(numP) is used in main
    *numP = (int *)malloc(sizeof(int));
    printf("\n");
}

void greet1()
{
    printf("greet1");
}

void greet2()
{
    printf("greet2");
}