#include <iostream>
#include <math.h>

#define M_PI           3.14159265358979323846  /* pi */

using namespace std;

class Vector2D
{
private:
    double rho; 
    double theta; 

    double x;
    double y;

public:
    // Getters
    double getRho() { return rho; }
    double getTheta() { return theta; }
    double getX() { return x; }
    double getY() { return y; }

    // Setters
    void setRho(double r)
    {
        rho = abs(r);
        this->x = rho * cos(theta * M_PI / 180);
        this->y = rho * sin(theta * M_PI / 180);
    }

    void setTheta(double t)
    {
        if (t <= -180 || t > 180)
        {
            t = fmod(t + 180, 360) - 180;
        }

        theta = t;
        this->x = rho * cos(theta * M_PI / 180);
        this->y = rho * sin(theta * M_PI / 180);
    }

    // Constructor
    Vector2D(double r = 1, double t = 0) // unit vector as default
    {
        setRho(r);
        setTheta(t);
    }

    // Funcs
    Vector2D operator+(Vector2D right)
    {
        Vector2D result;
        result.x = this->x + right.getX();
        result.y = this->y + right.getY();
        result.rho = sqrt(pow(result.x, 2) + pow(result.y, 2));
        result.theta = atan2(result.y, result.x) * 180 / M_PI; // atan2 is safer
        return result;
    }

    Vector2D operator-(Vector2D right)
    {
        Vector2D result;
        result.x = this->x - right.getX();
        result.y = this->y - right.getY();
        result.rho = sqrt(pow(result.x, 2) + pow(result.y, 2));
        result.theta = atan2(result.y, result.x) * 180 / M_PI;
        return result;
    }

    friend ostream& operator<<(ostream& os, const Vector2D& vec)
    {
        os << "Rho: " << vec.rho << ", Theta: " << vec.theta;
        return os;
    }

    friend istream& operator>>(istream& is, Vector2D& vec)
    {
        cout << "Enter rho: ";
        is >> vec.rho;
        cout << "Enter theta: ";
        is >> vec.theta;
        return is;
    }
};

bool operator==(Vector2D left, Vector2D right)
{
    return (left.getTheta() == right.getTheta() && left.getRho() == right.getRho());
}

bool operator!=(Vector2D left, Vector2D right)
{
    return !(left == right);
}

bool operator<(Vector2D left, Vector2D right)
{
    return (left.getRho() < right.getRho());
}

bool operator>(Vector2D left, Vector2D right)
{
    return (left.getRho() > right.getRho());
}

bool operator<=(Vector2D left, Vector2D right)
{
    return (left.getRho() <= right.getRho());
}

bool operator>=(Vector2D left, Vector2D right)
{
    return (left.getRho() >= right.getRho());
}

int main()
{
    Vector2D test(6, 180);
    Vector2D test2(8, 210);
    Vector2D test3;

    cout << test << endl;
    cout << test.getX() << " " << test.getY() << endl;

    test3 = test + test2;
    cout << test3 << endl;

    // input test
    cin >> test3;
    cout << test3 << endl;
}
