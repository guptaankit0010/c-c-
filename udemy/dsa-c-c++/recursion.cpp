#include <stdio.h>

void f1(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        f1(n - 1);
        printf("%d ", n);
    }
}

int factorial(int n)
{
    if (n > 0)
    {
        return n * factorial(n - 1);
    }
    return 1;
}

int sumOfNaturalNos(int n)
{
    if (n > 0)
    {
        return n + sumOfNaturalNos(n - 1);
    }
    return 0;
}
int power2m(int n, int m)
{
    if (m > 0)
    {
        return n * power2m(n, m - 1);
    }
    return 1;
}

int power2mV2(int n, int m)
{
    if (m > 0)
    {
        if (m % 2 == 0)
        {
            return power2mV2(n * n, m / 2);
        }
        else
        {
            return n * power2mV2(n * n, (m - 1) / 2);
        }
    }

    return 1;
}
int main()
{
    f1(3);
    printf("\nSum of natural numbers : %d", sumOfNaturalNos(3));
    printf("\nFactorial : %d", factorial(3));
    printf("\nPower 2^3 : %d", power2m(2, 3));
    printf("\nPowerv2 2^4 : %d", power2mV2(2, 4));
     printf("\nPowerv2 2^5 : %d", power2mV2(2, 5));
    printf("\n");
    return 0;
}
