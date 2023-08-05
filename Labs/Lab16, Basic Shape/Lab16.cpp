#include <iostream>

using namespace std;

class BasicShape
{
protected:
    double area;
    
public:
    double getArea()
    {
        return area;
    }

    virtual void calcArea() = 0;
};

class Circle : public BasicShape
{
private:
    long int centerX;
    long int centerY;
    double radius;

public:
    Circle(long int cx = 0, long int cy = 0, double r = 0)
    {
        centerX = cx;
        centerY = cy;
        radius = r;
    }

    long int getCenterX()
    {
        return centerX;
    }

    long int getCenterY()
    {
        return centerY;
    }

    void calcArea()
    {
        area = 3.14159 * radius * radius;
    }
};

class Rectangle : public BasicShape
{
private:
    long int width;
    long int length;

public:
    Rectangle(long int w = 0, long int l = 0)
    {
        width = w;
        length = l;
    }

    long int getWidth()
    {
        return width;
    }

    long int getLength()
    {
        return length;
    }

    void calcArea()
    {
        area = length * width;
    }
};

int main()
{
    Circle c(0,0,2);
    c.calcArea();
    cout << c.getArea() << endl;
    cout << endl;

    Rectangle r(2, 3);
    r.calcArea();
    cout << r.getArea() << endl;
}