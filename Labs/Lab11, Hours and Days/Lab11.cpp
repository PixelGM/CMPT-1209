#include <iostream>

using namespace std;

class NumDays
{
private:
	double hrs;
	double days;

public:
	NumDays(double h = 0)
	{
		hrs = h;
	}

	double getHrs() const
	{
		return hrs;
	}

	double getDays() const
	{
		return days;
	}

	void setHrs(double h)
	{
		hrs = h;
	}

	void setDays(double d)
	{
		days = d;
	}
	


	void convert()
	{
		days = hrs / 8;
	}

	void print() const
	{
		cout << "Hours: " << hrs << " Days: " << days << endl;
	}



	/*NumDays operator+(NumDays right)
	{
		NumDays result;
		result.hrs = hrs + right.hrs;
		result.days = days + right.days;
		return result;
	}*/

	friend NumDays operator-(const NumDays&, const NumDays&);

	

	NumDays operator--() // Prefix
	{
		NumDays result;
		result.hrs = --hrs;
		result.convert();
		return result;
	}

	NumDays operator--(int) // Postfix
	{
		NumDays result;
		result.hrs = hrs--;
		result.convert();
		return result;
	}
};

NumDays operator+(const NumDays &left, const NumDays& right)
{
	NumDays result;
	// result.hrs = hrs + right.hrs;
	result.setHrs(left.getHrs() + right.getHrs());
	// result.days = days + right.days;
	result.setDays(left.getDays() + right.getDays());
	return result;
}

NumDays operator-(const NumDays& left, const NumDays& right)
{
	NumDays result;
	result.hrs = left.hrs - right.hrs;
	result.days = left.days - right.days;
	return result;
}

NumDays operator++(NumDays& a) // Prefix
{
	NumDays result;
	result.setHrs(a.getHrs()+1);
	result.convert();
	a = result;
	return result;
}

NumDays operator++(NumDays& a, int) // Postfix
{
	NumDays temp;
	temp = a;
	a.setHrs(1 + a.getHrs());
	a.convert();
	return temp;
}


int main()
 {
	NumDays a(8), b(16), c;
	a.convert(); // 1 day 
	b.convert(); // 2 days

	cout << "A: " << endl;
	a.print();

	cout << endl;

	cout << "B: " << endl;
	b.print();

	cout << endl;

	cout << "C: " << endl;
	c = a + b;
	c.print();

	cout << "C: " << endl;
	a = 2 + c++;
	a.print();
	c.print();

	cout << "C: " << endl;
	++c;
	c.print();
}