#include <iostream>
using namespace std;
class Shape
{
public:
    Shape()
    {
        cout << "Base Shape Constructor" << endl;
    }
    // pure virtual functions for dimensions
    virtual double length() = 0;
    virtual double width() = 0;
    // concrete function uses abstract functions
    virtual double area()
    {
        return length() * width();
    }
    virtual void draw() = 0;
    virtual ~Shape()
    {
        cout << "Destructor of Shape" << endl;
    }
};
class Rectangle : public Shape
{
private:
    double l, w;

public:
    Rectangle(double length, double width) : l(length), w(width)
    {
        cout << "Rectangle Constructor" << endl;
    }
    double length() override
    {
        return l;
    }
    double width() override
    {
        return w;
    }
    void draw() override
    {
        cout << "Drawing Rectangle" << endl;
    }
    ~Rectangle()
    {
        cout << "Destructor of Rectangle" << endl;
    }
};
int main()
{
    Rectangle r(5, 3);
    cout << "Area: " << r.area() << endl;
    // delete s;
    return 0;
}