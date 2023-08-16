#include <iostream>

using namespace std;

class Ship
{
protected:
	string ship;
	string year;

public:
	// Constrcutor
	Ship(string s = "-", string y ="-")
	{
		ship = s;
		year = y;
	}


	// Getter
	string getShip() const
	{
		return ship;
	}

	string getYear() const
	{
		return year;
	}


	// Setter
	void setShip(string s)
	{
		ship = s;
	}

	void setYear(string y)
	{
		year = y;
	}


	// Other
	void print()
	{
		cout << "Ship: " << ship << endl;
		cout << "Year: " << year << endl;
	}
};

class CruiseShip : public Ship
{
private:
	int maxP;

public:
	// Constructor
	CruiseShip(string s = "-", string y = "-", int p = 0)
	{
		ship = s;
		year = y;
		maxP = p;
	}


	// Getter
	int getMaxP() const
	{
		return maxP;
	}
	
	// Setter
	void setMaxP(int p)
	{
		maxP = p;
	}


	// Other
	void print()
	{
		cout << "Ship: " << ship << endl;
		cout << "Max People: " << maxP << endl;
	}
};

class CargoShip : public Ship
{
private:
	int cargo;

public:
	// Constructor
	CargoShip(string s = "-", string y = "-", int c = 0)
	{
		ship = s;
		year = y;
		cargo = c;
	}


	// Getter
	int getCargo() const
	{
		return cargo;
	}

	// Setter
	void setCargo(int c)
	{
		cargo = c;
	}


	// Other
	void print()
	{
		cout << "Ship: " << ship << endl;
		cout << "Cargo: " << cargo << endl;
	}
};

int main()
{
	Ship ship("A Ship", "1945");
	CruiseShip cruise("Cruise Ship", "2023", 100);
	CargoShip cargo("Cargo Ship", "2000", 1000);

	ship.print();
	cout << endl;

	cruise.print();
	cout << endl;

	cargo.print();
	cout << endl;
}