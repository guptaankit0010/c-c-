#include <iostream>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
    char title;
};

// The compiler adds padding to structs for alignment to ensure that each member is stored 
// at a memory address suitable for its type. This improves performance because most CPUs 
// access memory faster when data is aligned to certain boundaries (like 4 or 8 bytes).

// For example, if a struct contains an int (usually 4 bytes, needs 4-byte alignment) and 
// a char (1 byte), the compiler may insert extra bytes (padding) so that the next int starts 
// at a 4-byte boundary. This avoids slow, misaligned memory access.

// Gotcha: PADDING can make the struct larger than the sum of its members. Always use sizeof() to check actual size.


Rectangle r2={1,10};

// The above line initializes the struct Rectangle r2 with length 1 and breadth 10.
// This is kind of global initialization. It will be accessed in the main function and other functions as well.

int main()
{
    // Create an instance of Rectangle
    struct Rectangle r1;

    // Print the size of the struct Rectangle
    cout << "sizeof(r1): " << sizeof(r1) << endl; // This will print the size of the struct Rectangle
    // even though char is 1 byte, the size of the struct Rectangle will be 12 bytes due to padding.
    // The size of the struct Rectangle will be 12 bytes, as int is 4 bytes and char is 1 byte.
    // The compiler adds padding to align the members of the struct Rectangle.
    
    // Print the address of the struct Rectangle
    cout << &r1 << endl;                          // This will print the address of the struct Rectangle
    cout << &r1.length << endl;                   // This will print the address of length member
    cout << &r1.breadth << endl;                  // This will print the address of breadth member

    // Print default values of members
    cout << "r1.length: " << r1.length << endl;   // This will print the default value of length, which is 0
    cout << "r1.breadth: " << r1.breadth << endl; // This will print the default value of breadth, which is 0

    return 0;
}