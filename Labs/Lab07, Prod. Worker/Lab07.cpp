#include <iostream>

using namespace std;


class Employee 
{
protected:
	string fullName;
	int employeeNum;
	int hireYear;

public:
	// Construct
	Employee(string = "Name", int = 0);

	// GET
	string getFullName() const;
	int getEmployeeNum() const;
	int getHireYear() const;

	// SET
	void setFullName(string);
	void setEmployeeNum(int);
	void setHireYear(int);
};

// Construct Def
Employee::Employee(string fn, int hy)
{
	employeeNum = 0;
	fullName = fn;
	hireYear = hy;
}

// GET Def
string Employee::getFullName() const
{
	return fullName;
}

int Employee::getEmployeeNum() const
{
	return employeeNum;
}

int Employee::getHireYear() const
{
	return hireYear;
}

void Employee::setFullName(string fn)
{
	fullName = fn;
}

void Employee::setEmployeeNum(int en)
{
	employeeNum = en;
}

void Employee::setHireYear(int hy)
{
	hireYear = hy;
}



class ProductionWorker : public Employee
{
private:
	int shift;
	double hourlyPay;

public:
	// Construct
	ProductionWorker(int = 0, double = 0);

	// GET
	int getShift() const;
	int getHourlyPay() const;

	// SET
	void setShift(int);
	void setHourlyPay(double);
};

// Constuct DEF
ProductionWorker::ProductionWorker(int s, double hp)
{
	shift = s;
	hourlyPay = hp;
}

//GET Def
int ProductionWorker::getShift() const
{
	return shift;
}

int ProductionWorker::getHourlyPay() const
{
	return hourlyPay;
}

void ProductionWorker::setShift(int s)
{
	shift = s;
}

void ProductionWorker::setHourlyPay(double hp)
{
	hourlyPay = hp;
}


int main()
{
	ProductionWorker a(1, 20.5);
	cout << a.getFullName() << " " << a.getHourlyPay() << " " << a.getShift();

}


