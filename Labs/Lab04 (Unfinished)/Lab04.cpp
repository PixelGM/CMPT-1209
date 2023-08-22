#include <iostream>

using namespace std;

class Complex
{
private:
	double real;
	double imag;

public:
	// Construct
	Complex(double r = 0, double i = 0)
	{
		real = r;
		imag = i;
	}

	// Get
	double getReal() const
	{
		return real;
	}

	double getImag() const
	{
		return imag;
	}


	// Set
	void setReal(double r)
	{
		real = r;
	}

	void setImag(double i)
	{
		imag = i;
	}


	// Output


	// Input


};

int main()
{

}