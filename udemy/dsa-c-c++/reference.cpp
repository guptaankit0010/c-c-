#include <iostream>
using namespace std;
// References are aliases/another name for existing variables.

int main()
{
    int a = 10;
    int &ref1 = a; // ref1 is a reference to a
    // reference must be initialized when declared and cannot be changed to refer to another variable later.
    // reference does not occupy any memory, it is just an alias for the variable.
    // reference is not a pointer, it cannot be null and does not require dereferencing.
    
    cout << "Value of a: " << a << endl;          // Prints 10
    cout << "Value of ref1: " << ref1 << endl;    // Prints 10, as ref1 is a reference to a
    ref1 = 20; // Changes value of a through reference ref1
    cout << "New value of a: " << a << endl;      // Prints 20, as ref1 is a reference to a
    return 0;
}