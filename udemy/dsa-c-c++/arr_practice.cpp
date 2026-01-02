#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "expected size of arr: 20 bytes " << endl;
    cout << "size of arr: " << sizeof(arr) << endl;

    int arr1[5] = {1};
    cout << arr1[0] << endl; // This will print 1
    cout << arr1[1] << endl; // This will print 0, as the rest of the elements are initialized to 0
    cout << arr1[2] << endl; // This will print 0, as the rest of the elements are initialized to 0

    int n = 8;
    int arr2[n];

    arr2[0] = 5;
    cout << "arr2 vals: " << endl;
    for (int i : arr2)
    {

        cout << i << " " << endl;
    }

    // struct
    struct Rectangle
    {
        int length;
        int breadth;
    };

    // Above definition does not allocate memory for the struct Rectangle.
    // It only defines the structure of the Rectangle.
    // To allocate memory for the struct Rectangle, we need to create an instance of it.
    // Below line creates an instance of the struct Rectangle and allocates memory for it.
    // The size of the struct Rectangle will be the sum of the sizes of its members.

    struct Rectangle r1;
    int *ptrToR1length;
    ptrToR1length = &r1.length;

    cout << "Address of ptrToR1length: " << ptrToR1length << endl; // This will print the address of the length member
    cout << "sizeof(r1): " << sizeof(r1) << endl;                  // This will print the size of the struct Rectangle
    cout << "Address of r1: " << &r1 << endl;                      // This will print the address of the struct Rectangle
    cout << "Address of r1.length: " << &r1.length << endl;        // This will print the address of the struct Rectangle
    cout << "Address of r1.breadth: " << &r1.breadth << endl;      // This will print the address of the struct Rectangle
    cout << "r1.length: " << r1.length << endl;                    // This will print the default value of length, which is 0
    cout << "r1.breadth: " << r1.breadth << endl;                  // This will print the default value of breadth, which is 0

    struct Rectangle r2[5] = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
        {9, 10}};

    for (size_t i = 0; i < sizeof(r2) / sizeof(r2[0]); i++)
    {
        cout << "Area of rectangle " << i + 1 << ": " << r2[i].length * r2[i].breadth << endl;
    }

    return 0;
}