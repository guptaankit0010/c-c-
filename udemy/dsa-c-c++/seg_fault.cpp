#include <stdio.h>

int main()
{
    int arr1[10000000] = {1, 1}; // this causes a segmentation fault
    //  because we are trying to allocate a large amount of memory on the stack,
    // which exceeds the stack size limit.
    // The stack is a limited memory area used for function calls and local variables, and
    // allocating a large array like this can lead to a stack overflow,
    // resulting in a segmentation fault.
    return 0;
}