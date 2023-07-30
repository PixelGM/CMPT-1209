#include <iostream>
#include <cstdlib>  // For abs function
using namespace std;

class Rational 
{
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) 
    {
        if (b == 0) 
        {
            return a;
        }
        else 
        {
            return gcd(b, a % b);
        }
    }

    void reduce() 
    {
        int gcdVal = gcd(abs(numerator), abs(denominator));
        numerator /= gcdVal;
        denominator /= gcdVal;
    }



public:

    Rational()
    {
        numerator = 0;
        denominator = 1;
    }

    // one argument constructor
    Rational(int num)
    {
        numerator = num;
        denominator = 1;
        reduce();
    }

    // two arguments constructor
    Rational(int a, int b) 
    {
        if (b == 0) 
        {
            cout << "Denominator cannot be zero. Setting it to 1." << endl;
            b = 1;
        }
        if (b < 0) 
        {
            a *= -1;
            b *= -1;
        }
        numerator = a;
        denominator = b;
        reduce();
    }

    // Accessors
    int getNumerator() const 
    {
        return numerator;
    }

    int getDenominator() const 
    {
        return denominator;
    }

    // Mutators
    void setNumerator(int num) 
    {
        numerator = num;
        reduce();
    }

    void setDenominator(int den) 
    {
        if (den == 0) 
        {
            cout << "Denominator cannot be zero. Setting it to 1." << endl;
            den = 1;
        }
        if (den < 0) 
        {
            numerator *= -1;
            den *= -1;
        }
        denominator = den;
        reduce();
    }

    // input function
    void input() 
    {
        cout << "Enter numerator: ";
        cin >> numerator;
        do 
        {
            cout << "Enter denominator: ";
            cin >> denominator;
            if (denominator == 0) 
            {
                cout << "Denominator cannot be zero. Please re-enter." << endl;
            }
        } while (denominator == 0);
        if (denominator < 0) 
        {
            numerator *= -1;
            denominator *= -1;
        }
        reduce();
    }

    // output function
    void output() const 
    {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() 
{
    Rational a, b(6), c(-6, -8), d(9, -6), e (6, -2);

    cout << "Rational a: ";
    a.output();

    cout << "Rational b: ";
    b.output();

    cout << "Rational c: ";
    c.output();

    cout << "Rational d: ";
    d.output();

    cout << "Rational e: ";
    e.output();

    return 0;
}
