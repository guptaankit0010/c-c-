#include <iostream>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};
int main()
{
    struct Rectangle r1 = {10, 5};
    struct Rectangle *p;
    p = &r1; // Pointer p points to the address of r1

    cout << "Address of r1: " << &r1 << endl;                      // Prints address of r1
    cout << "Address stored in pointer p: " << p << endl;          // Prints address of r1
    cout << "Address of r1.length: " << &r1.length << endl;        // Prints address of r1.length
    cout << "Address of r1.breadth: " << &r1.breadth << endl;      // Prints address of r1.breadth
    
    
    cout << "Value of r1.length: " << r1.length << endl;           // Prints 10
    cout << "Value of r1.breadth: " << r1.breadth << endl;         // Prints 5
    cout << "Value at pointer p->length: " << p->length << endl;   // Dereferences p to get length of r1, prints 10
    cout << "Value at pointer p->breadth: " << p->breadth << endl; // Dereferences p to get breadth of r1, prints 5
    cout << "Value at pointer (*p).length: " << (*p).length << endl;   // Dereferences p to get length of r1, prints 10
    cout << "Value at pointer (*p).breadth: " << (*p).breadth << endl; // Dereferences p to get breadth of r1, prints 5

    p->length = 20;                                 // Changes length of r1 through pointer p
    p->breadth = 10;                                // Changes breadth of r1 through pointer p
    cout << "New value of r1.length: " << r1.length << endl;   // Prints 20
    cout << "New value of r1.breadth: " << r1.breadth << endl; // Prints 10

    struct Rectangle *r2 = (struct Rectangle *)malloc(sizeof(struct Rectangle)); // Allocates memory for a struct Rectangle on the heap
    r2->length = 15; // Assigns value 15 to length of r2
    r2->breadth = 7; // Assigns value 7 to breadth of r2
    cout << "Value of r2.length: " << r2->length << endl;   // Prints 15
    cout << "Value of r2.breadth: " << r2->breadth << endl; // Prints 7
    free(r2); // Frees the dynamically allocated memory
    

    return 0;
}