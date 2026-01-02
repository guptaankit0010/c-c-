#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void genericSwap(void *a, void *b, size_t size)
{
    void *temp = malloc(size);
    if (temp == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // void *memcpy(void *dest, const void *src, size_t n);
    //  Copies n bytes from memory area src to memory area dest
    // The memory areas must not overlap.
    // returns a universal void pointer to dest
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

void basicSwap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapIntsNoThird1(int *a, int *b)
{
    if (a == b)
        return; // avoid zeroing if same address
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void swapIntsNoThird2(int *a, int *b)
{
    if (a == b)
        return; // avoid zeroing if same address
    *a = *a * *b;
    *b = *a / *b;
    *a = *a / *b;
}


int main()
{
    int a = 10;
    int *pa1 = &a;     // pointer to int
    int **ppa1 = &pa1; // pointer to pointer to int
    printf("Value of a: %d\n", a);
    printf("Address of a: %p\n", (void *)&a);
    printf("Value of pa1 (Address of a): %p\n", (void *)pa1);
    printf("Value at a (*pa1): %d\n", *pa1);
    printf("Address of pa1: %p\n", (void *)&pa1);
    printf("Value of ppa1 (Address of pa1): %p\n", (void *)ppa1);

    // Dereferencing a void * is not allowed in C,
    // because the compiler does not know the size or type of the data pointed to by a void *
    // printf("Value of a (*(ppa1)): %d\n", *(void *)*ppa1);

    printf("Value of a (*(ppa1)): %d\n", *(int *)*ppa1);

    // Swapping values using genericSwap
    int x = 5, y = 10;
    printf("Before swap: x = %d, y = %d\n", x, y);
    genericSwap(&x, &y, sizeof(int));
    printf("After swap: x = %d, y = %d\n", x, y);

    // Swapping doubles using genericSwap
    double m = 1.5, n = 2.5;
    printf("Before swap: m = %.2f, n = %.2f\n", m, n);
    genericSwap(&m, &n, sizeof(double));
    printf("After swap: m = %.2f, n = %.2f\n", m, n);
    return 0;
}