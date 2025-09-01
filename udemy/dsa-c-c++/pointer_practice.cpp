#include <iostream>
using namespace std;

// pointers are variables that store memory addresses.
// They are used to access and manipulate heap memory, which is dynamically allocated memory.
// pointer variable itslef is stored in stack memory, but it points to a location in heap memory.
// pointers are used to access all types of resources external to RAM,
// such as memory hard drives, SSDs, etc.
// Stack memory resides in RAM and is used for static memory allocation
// Heap memory resides in RAM and is used for dynamic memory allocation.
// Pointers are also used for parameter passing in functions, especially for large data structures like arrays and structs.

int main()
{
    int a = 10;
    int *p;
    p = &a; // Pointer p points to the address of a

    cout << "Value of a: " << a << endl;                  // Prints 10
    cout << "Address of a: " << &a << endl;               // Prints address of a
    cout << "Value at pointer p: " << *p << endl;         // Dereferences p to get value of a, prints 10
    cout << "Address stored in pointer p: " << p << endl; // Prints address of a

    *p = 20;                                 // Changes value of a through pointer p
    cout << "New value of a: " << a << endl; // Prints 20

    // dynamically allocating memory using pointers
    int *q = (int *)malloc(5 * sizeof(int)); // Allocates memory for an array of 5 ints on the heap
    *q = 1;                                  // Assigns value 1 to the first element of the allocated memory
    *(q + 1) = 2;                            // Assigns value 2 to the second element of the allocated memory
    *(q + 2) = 3;                            // Assigns value 3 to the third element of the allocated memory
    *(q + 3) = 4;                            // Assigns value 4 to the fourth element of the allocated memory
    *(q + 4) = 5;                            // Assigns value 5 to the fifth element of the allocated memory
    cout << "Values in dynamically allocated array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << *(q + i) << " " << endl; // Prints values of the dynamically allocated array
    }

    free(q); // Frees the dynamically allocated memory
    // malloc(sizeof(int)) allocates enough bytes for one int (typically 4 bytes).
    // It returns a void*, which is a pointer that can point to any data type.
    // (int *) casts this generic pointer to an int*, so you can use it to store or access integer values.

    // In C, you can assign void* to any pointer type without a cast.
    // In C++, you must cast void* to the correct type (e.g., int*) before using it.

    int *r = new int[5]; // Allocates memory for an array of 5 ints on the heap using new
    *r = 5;
    *(r + 1) = 6; // Assigns value 6 to the second element of the allocated memory
    *(r + 2) = 7; // Assigns value 7 to the third element of the allocated memory
    *(r + 3) = 8; // Assigns value 8 to the fourth element of the allocated memory
    *(r + 4) = 9; // Assigns value 9 to the fifth element of the allocated memory

    delete[] r; // Frees the dynamically allocated memory using delete

    printf("Values in dynamically allocated array using new: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(r + i)); // Prints values of the dynamically allocated array
    }

    int arr1[] = {1, 2, 3, 4, 5};
    printf("Address of arr1: %p\n", arr1); // Prints the address of the first element of arr1

    int *arr2 = arr1; // arr2 points to the first element of arr1
    // Array declarations like int arr1[] = {1, 2, 3, 4, 5}; create an array on the stack.
    // The name of the array (arr1) acts as a pointer to the first element of the array.
    // Array name is not a pointer, but it can be used as one in expressions.
    // arr2[0] is equivalent to arr1[0], arr2[1] is equivalent to arr1[1], and so on.

    int *arr3 = new int[5]; // Dynamically allocates memory for an array of 5 ints on the heap
    arr3[0] = 10;           // Assigns value 10 to the first element of the dynamically allocated array
    arr3[1] = 20;           // Assigns value 20 to the second element of the dynamically allocated array
    arr3[2] = 30;           // Assigns value 30 to the third element of the dynamically allocated array
    arr3[3] = 40;           // Assigns value 40 to the fourth element of the dynamically allocated array
    arr3[4] = 50;           // Assigns value 50 to the fifth element of the dynamically allocated array

    printf("Values in dynamically allocated array using new: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr3[i]); // Prints values of the dynamically allocated array
    }
    printf("\n");

    int *p1;
    char *p2;
    double *p3;

    cout << "Size of int pointer: " << sizeof(p1) << " bytes" << endl;   // Prints size of int pointer
    cout << "Size of char pointer: " << sizeof(p2) << " bytes" << endl;  // Prints size of char pointer
    cout << "Size of double pointer: " << sizeof(p3) << " bytes" << endl; // Prints size of double pointer
}