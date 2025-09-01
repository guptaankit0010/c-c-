#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

struct Uniforms
{
    int code[10];
};

int add(int a, int b) // this line int add(int a,int b) is function declaration or function prototype
// formal parameters a and b
{
    return a + b;
}

int add(int *a, int *b)
{
    return *a + *b;
}

void swap1(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

int swap2(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

int swap3(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    return 0;
}

int *newArray(int arr[], int n) // arr is a pointer to the first element of the array
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // how to return an array from a function
    int *newArr = new int[n];
    for (int i = 0; i < n; i++)
    {
        newArr[i] = arr[i];
    }
    return newArr;
}

void printTest1(int *a)
{
    cout << "Value of a in printTest1: " << a[0] << endl;
    cout << "Value of a in printTest1: " << a[112] << endl;
}

int area1(struct Rectangle *r)
{
    return r->length * r->breadth;
}

int area2(struct Rectangle r)
{
    return r.length * r.breadth;
}

int area3(struct Rectangle &r)
{
    return r.length * r.breadth;
}

int getCodes(struct Uniforms u)
{
    return u.code[0];
}

int getCodes2(struct Uniforms *u)
{
    return u->code[0];
}


int main()
{
    int x = 5, y = 10; // these are created in stack memory
    int a = 10, b = 20;
    cout << "add(x, y): " << add(x, y) << endl; // Calls add(int, int)
    // actual parameters x and y
    // function call add(x,y) creates a new stack frame for the function add in stack memory
    // and copies the values of x and y into the parameters a and b
    // after the function call is complete, the stack frame is destroyed and the values of a and b are lost
    // the original variables x and y in main() remain unchanged

    cout << "add(&a, &b): " << add(&a, &b) << endl; // Calls add(int*, int*)

    // swap1(x, y); // This will not swap the values of x and y in main()
    cout << "Before swap1: x = " << x << ", y = " << y << endl;
    swap1(x, y); // This will not swap the values of x and y in main()
    cout << "After swap1: x = " << x << ", y = " << y << endl;

    int *xp = &x, *yp = &y;

    cout << "Before swap2: x = " << x << ", y = " << y << endl;
    swap2(xp, yp); // This will swap the values of x and y in main()
    cout << "After swap2: x = " << x << ", y = " << y << endl;

    int &xr = x, &yr = y; // references must be initialized when declared
    cout << "Before swap3: x = " << x << ", y = " << y << endl;
    swap3(xr, yr); // This will swap the values of x and y in main()
    cout << "After swap3: x = " << x << ", y = " << y << endl;

    // In C++, references act as aliases to original variables.
    // When using references (like in swap3), changes made inside the function
    // directly affect the original variables.
    // References are typically implemented as hidden pointers by the compiler,
    // but unlike pointers, they cannot be null or changed to refer to another variable.

    // Array as function argument
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]); // here sizeof(arr) gives the total size of the array in bytes

    // but when array is passed to a function, it decays to a pointer to the first element of the array
    //  sizeof(arr) inside the function will give the size of the pointer (typically 4 or 8 bytes)

    int *newArr = newArray(arr, n); // arr decays to a pointer to the first element of the array
    for (int i = 0; i < n; i++)
    {
        cout << newArr[i] << " ";
    }
    cout << endl;
    delete[] newArr; // free the memory allocated for newArr

    int val = 10;
    int *valP = &val;
    cout << "Address of val in main: " << valP << endl;
    printTest1(valP);

    // Struct as function argument

    Rectangle r1 = {10, 5};
    Rectangle *r1P = &r1;
    cout << "Address of r1 in main: " << r1P << endl;
    cout << "Area of rectangle (using pointer): " << area1(r1P) << endl;

    cout << "Area of rectangle (using value): " << area2(r1) << endl;
    cout << "Area of rectangle (using reference): " << area3(r1) << endl;

    // when struct is passed to a function by value, a copy of the struct is made
    // when struct is passed to a function by reference, no copy is made, the function works with the original struct
    // This can have performance implications for large structs.
    // In general, prefer passing large structs by reference to avoid the overhead of copying.

    // when struct contains a pointer, passing by value copies the pointer, not the data it points to.
    // This means both the original and the copy point to the same data.
    // If the data is modified through one pointer, the change is visible through the other pointer.
    // To avoid this, pass the pointer by reference or use smart pointers.

    // when array contains arrays or structs, passing by value copies the entire array or struct.
    // This can be inefficient for large arrays or structs.
    // In general, prefer passing large arrays or structs by reference to avoid the overhead of copying.
    // For arrays, passing by pointer is common practice in C and C++.
    // This allows functions to modify the original array without making a copy.
    Uniforms u1 = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
    cout << "First code in uniforms: " << getCodes(u1) << endl;
    cout << "First code in uniforms (using pointer): " << getCodes2(&u1) << endl;
    return 0;
}