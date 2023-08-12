#include <iostream>

using namespace std;

class ParkedCar
{
private:
	string make;
	string model;
	string color;
	string licenseNum;
	int minsParked;

public:
	ParkedCar(string ma = " ", string mo = " ", string co = " ", string ln = " ", int mp = 0)
	{
		make = ma;
		model = mo;
		color = co;
		licenseNum = ln;
		minsParked = mp;
	}

	string getMake() const{ return make; }
	string getModel() const { return model; }
	string getColor() const { return color; }
	string getLicenseNum() const { return licenseNum; }
	int getMinsParked() const { return minsParked; }
};

class ParkingMeter
{
private:
	int minsPurchased;

public:
	ParkingMeter(int mp)
	{
		minsPurchased = mp;
	}

	int getMinsPurchased() const { return minsPurchased; }
};

class ParkingTicket
{
private:
	ParkedCar* parkedCar;
	ParkingMeter* parkingMeter;
	int fine;

public:
	ParkingTicket(ParkedCar& pc, ParkingMeter& pm)
	{
		parkedCar = &pc;
		parkingMeter = &pm;
		fine = 0;
	}

	// Print Illegally Parked Car
	void printCar()
	{
		// If Car Illegally Parked
		if (parkedCar->getMinsParked() > parkingMeter->getMinsPurchased())
		{
			cout << "Make: " << parkedCar->getMake() << endl;
			cout << "Model: " << parkedCar->getModel() << endl;
			cout << "Color: " << parkedCar->getColor() << endl;
			cout << "License Number: " << parkedCar->getLicenseNum() << endl;
			cout << endl;
		}
	}

	void printFine()
	{
		// If Car Illegally Parked
		if (parkedCar->getMinsParked() > parkingMeter->getMinsPurchased())
		{
			int sum = 0;
			
			double totalMins = parkedCar->getMinsParked() - parkingMeter->getMinsPurchased();
			double totalHours = ceil((totalMins) / 60);
			
			if (totalHours > 1)
			{
				fine = 25 + (10 * (totalHours - 1));
			}
			else if (totalHours == 1)
			{
				fine = 25;
			}

			cout << "Fine is: " << fine << endl;
		}
	}
};

class PoliceOfficer
{
private:
	string officerName;
	int badgeNum;

public:
	PoliceOfficer(string on, int bn) { officerName = on; badgeNum = bn; }

	void inspect(ParkedCar& pc, ParkingMeter& pm)
	{
		// If Car Illegally Parked
		if (pc.getMinsParked() > pm.getMinsPurchased())
		{
			// Generate / Issue New Ticket
			ParkingTicket ticket(pc, pm);
			ticket.printCar();
			ticket.printFine();
			cout << "--------------------" << endl;
		}
		else
		{
			cout << "No Violation!" << endl;
		}
	}
};

int main()
{
	ParkedCar Mazda("Mazda", "AE69", "White", "B 1234 XKX", 61);
	ParkingMeter A(60);
	/*ParkingTicket PT(Mazda, A);
	PT.printCar();
	PT.printFine();*/

	PoliceOfficer T("Tempeny", 123);
	T.inspect(Mazda, A);
}