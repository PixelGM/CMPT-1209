#include <iostream>
#include <vector>

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
		cout << "Fuel: " << gallons << " gallons" << endl;
	}

	void inc()
	{
		if (gallons < 15)
		{
			gallons++;
		}
		else
		{
			cout << "Gallons is full!" << endl;
		}
	}

	void dec()
	{
		if (gallons > 0)
		{
			gallons--;
		}
		else
		{
			cout << "Gallons is empty." << endl;
		}
	}
};

class OdoMeter
{
private:
	int mileage;
	FuelGauge* fuelGauge;

public:
	OdoMeter(FuelGauge& fg)
	{
		fuelGauge = &fg;
		mileage = 0;
	}

	int getMileage() const { return mileage; }

	void printMileage()
	{
		cout << "Mileage: " << mileage << endl;
	}

	void inc()
	{
		if (mileage < 999999)
		{
			mileage++;
		}
		else
		{
			cout << "Odometer Reset." << endl;
			mileage = 0;
		}
	}

	void decFuelGauge()
	{
		if (fuelGauge->getGallons() <= 0)
		{
			cout << "Gallon is Empty!" << endl;
			return;
		}

		fuelGauge->printGallons();
		printMileage();
		inc();
		if (mileage % 24 == 0)
		{
			fuelGauge->dec();
		}
	}
};

int main()
{
	FuelGauge Mazda(10);
	OdoMeter MazdaO(Mazda);

	for (int i = 0; i < 1000; i++)
	{
		MazdaO.decFuelGauge();
	}
}
