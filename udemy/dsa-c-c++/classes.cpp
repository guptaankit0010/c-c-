#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;
public:
    Rectangle(int l, int b);
    ~Rectangle();

    int area() { return length * breadth; };
    void modifyDimensions(int l, int b){
        length = l;
        breadth = b;
    };
};

Rectangle::Rectangle(int l, int b)
{
    length = l;
    breadth = b;
}
Rectangle::~Rectangle()
{
    cout << "Rectangle destroyed with length: " << length << " and breadth: " << breadth << endl;
}

int main()
{
    Rectangle r1(10, 5);
    Rectangle r2(20, 10);
    cout << "Area of r1: " << r1.area() << endl;
    cout << "Area of r2: " << r2.area() << endl;
    r1.modifyDimensions(15, 7);
    cout << "New area of r1 after modification: " << r1.area() << endl; 
    return 0;
}