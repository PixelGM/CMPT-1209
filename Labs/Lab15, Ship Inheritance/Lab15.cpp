#include <iostream>

using namespace std;

class Ship
{
protected:
    string ship;
    string year;
public:
    // Constructor
    Ship(string s = "-", string y ="-")
    {
        ship = s;
        year = y;
    }

    // Getters
    string getShip() const
    {
        return ship;
    }

    string getYear() const
    {
        return year;
    }


    // Setters
    void setShip(string s)
    {
        ship = s;
    }

    void setYear(string y)
    {
        year = y;
    }


    // Others
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
    CruiseShip(string s = "-", string y = "-", int p = 0) : Ship(s, y)
    {
        maxP = p;
    }

    // Getters
    int getMaxP() const
    {
        return maxP;
    }

    // Setters
    void setMaxP(int p)
    {
        maxP = p;
    }

    // Print
    void print()
    {
        cout << "Ship: " << ship << endl;
        cout << "Max Passengers: " << maxP << endl;
    }
};

class CargoShip : public Ship
{
private:
    int cargoCapacity;

public:
    // Constructor
    CargoShip(string s = "-", string y = "-", int c = 0) : Ship(s, y)
    {
        cargoCapacity = c;
    }

    // Getters
    int getCargoCapacity() const
    {
        return cargoCapacity;
    }

    // Setters
    void setCargoCapacity(int c)
    {
        cargoCapacity = c;
    }

    // Print
    void print()
    {
        cout << "Ship: " << ship << endl;
        cout << "Cargo Capacity: " << cargoCapacity << endl;
    }
};

int main()
{
    CruiseShip cruise("Cruiser", "2021", 2000);
    cout << "CruiseShip Details: " << endl;
    cruise.print();

    CargoShip cargo("Carrier", "2020", 5000);
    cout << "\nCargoShip Details: " << endl;
    cargo.print();

    return 0;
}
