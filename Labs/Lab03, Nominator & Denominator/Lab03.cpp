#include <iostream>

using namespace std;

class Rational
{
private:
	int nom;
	int den;

public:

	// Constructor
	Rational(int n = 0, int d = 1)
	{
		nom = n;
		den = d;
	}

	// Read
	int getNom()
	{
		return nom;
	}

	int getDen()
	{
		return den;
	}


	// Write
	void setNom(int n)
	{
		nom = n;
	}

	void setDen(int d)
	{
		if (d == 0)
			den = 1;
		else
			den = d;
	}



	void input()
	{
		// Use Do-While Loop
		do
		{
			cout << "Nominator: ";
			cin >> nom;

			cout << "Denominator: ";
			cin >> den;

			if (den == 0)
			{
				cout << "Denominator Cannot be 0" << endl << endl;
			}
		} while (den == 0);
	}

	void output()
	{
		cout << nom << "/" << den << endl;
	}

	int getGCD(int a, int b)
	{
		if (b == 0)
			return a;

		getGCD(b, a % b);
	}

	void reduce()
	{
		int gcd = abs(getGCD(nom, den));
		nom /= gcd;
		den /= gcd;
	}



	// Overload
	friend Rational operator+(const Rational& left, const Rational& right);

	friend Rational operator-(const Rational& left, const Rational& right);

	friend Rational operator*(const Rational& left, const Rational& right);

	friend Rational operator/(const Rational& left, const Rational& right);

	friend bool operator<(const Rational& left, const Rational& right);

	friend bool operator>(const Rational& left, const Rational& right);

	friend bool operator<=(const Rational& left, const Rational& right);

	friend bool operator>=(const Rational& left, const Rational& right);

	friend bool operator==(const Rational& left, const Rational& right);

	friend bool operator!=(const Rational& left, const Rational& right);

	friend Rational operator+=(const Rational& left, const Rational& right);

	friend Rational operator-=(const Rational& left, const Rational& right);

	friend Rational operator*=(const Rational& left, const Rational& right);

	friend Rational operator/=(const Rational& left, const Rational& right);
};

Rational operator+(const Rational& left, const Rational& right)
{
	Rational sum;
	sum.nom = (right.den * left.nom) + (left.den * right.nom);
	sum.den = left.den * right.den;

	sum.reduce();

	return sum;
}

Rational operator-(const Rational& left, const Rational& right)
{
	Rational sum;
	sum.nom = (right.den * left.nom) - (left.den * right.nom);
	sum.den = left.den * right.den;

	sum.reduce();

	return sum;
}

Rational operator*(const Rational& left, const Rational& right)
{
	Rational sum;
	sum.nom = left.nom * right.nom;
	sum.den = left.den * right.den;

	sum.reduce();

	return sum;
}

Rational operator/(const Rational& left, const Rational& right)
{
	Rational sum;
	sum.nom = left.nom * right.den;
	sum.den = left.den * right.nom;

	sum.reduce();

	return sum;
}

bool operator<(const Rational& left, const Rational& right)
{
	return (right.den * left.nom) < (left.den * right.nom);
}

bool operator>(const Rational& left, const Rational& right)
{
	return (right.den * left.nom) > (left.den * right.nom);
}

bool operator<=(const Rational& left, const Rational& right)
{
	return (right.den * left.nom) <= (left.den * right.nom);
}

bool operator>=(const Rational& left, const Rational& right)
{
	return (right.den * left.nom) >= (left.den * right.nom);
}

bool operator==(const Rational& left, const Rational& right)
{
	return (right.den * left.nom) == (left.den * right.nom);
}

bool operator!=(const Rational& left, const Rational& right)
{
	return (right.den * left.nom) != (left.den * right.nom);
}

Rational operator+=(Rational& left, const Rational& right)
{
	left = left + right;
	return left;
}

Rational operator-=(Rational& left, const Rational& right)
{
	left = left - right;
	return left;
}

Rational operator*=(Rational& left, const Rational& right)
{
	left = left * right;
	return left;
}

Rational operator/=(Rational& left, const Rational& right)
{
	left = left / right;
	return left;
}

int main()
{
	// Rational a(2,6), b(2, 3),c;
	Rational a(2,2), b(1, 2),c;
	a += b;
	a.output();
	
}