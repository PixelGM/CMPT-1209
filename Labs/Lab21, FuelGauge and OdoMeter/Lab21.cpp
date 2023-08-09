#include <iostream>

using namespace std;

class FuelGauge
{
private:
	int gallons;

public:
	FuelGauge(int g = 0)
	{
		gallons = g;
	}

	int getGallons() const { return gallons; }

	void printGallons()
	{
		cout << "Gallons is: " << gallons << " Gallons" << endl;
	}

	void Inc() 
	{
		if (gallons < 15)
		{
			gallons++;
		}
		else
		{
			cout << "Gallons is Full!" << endl;
		}
	}

	void Dec()
	{
		if (gallons > 0)
		{
			gallons--;
		}
	}
};

class OdoMeter
{
private:
	int mileage;
	FuelGauge* fuelGauge;

public:
	OdoMeter(FuelGauge& fg, int m = 0)
	{
		fuelGauge = &fg;
		mileage = m;
	}

	int getMileage() const { return mileage; }

	void printMileage()
	{
		cout << "Mileage is: " << mileage << " mileage" << endl;
	}

	void Inc()
	{
		mileage++;

		if (mileage > 999999)
		{
			mileage = 0;
		}

		if (mileage % 24 == 0)
		{
			fuelGauge->Dec();
		}
	}


};

int main()
{
	FuelGauge Mazda;
	OdoMeter MazdaO(Mazda);

	// Filling Up Car
	for (int i = 0; i < 15; i++)
	{
		Mazda.Inc();
		cout << "Fuel: " << Mazda.getGallons() << endl;
	}

	cout << endl;

	// See Mazda's Fuel
	Mazda.printGallons();

	cout << endl;

	// Car Run
	while (Mazda.getGallons() > 0)
	{
		MazdaO.Inc();
		MazdaO.printMileage();
		Mazda.printGallons();
	}

	cout << "Gallons is empty!" << endl;
}