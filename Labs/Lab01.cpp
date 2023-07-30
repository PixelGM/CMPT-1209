#include <iostream>
#include <string>

using namespace std;

class Laptop
{
private:
    string manufacturer;
    string processor;
    double screenSize;
    string color;
    bool isNew;

public:
    string getManufacturer();
    string getProcessor();
    double getScreenSize();
    string getColor();
    bool getIsNew();

    void setManufacturer(string);
    void setProcessor(string);
    void setScreenSize(double);
    void setColor(string);
    void setIsNew(bool);



    // User Input dan Output
    void input();
    void output();



    // Constructors
    Laptop(string m, string p, double ss, string c, bool in);
    Laptop();
};



// Getters
string Laptop::getManufacturer()
{
    return manufacturer;
}

string Laptop::getProcessor()
{
    return processor;
}

double Laptop::getScreenSize()
{
    return screenSize;
}

string Laptop::getColor()
{
    return color;
}

bool Laptop::getIsNew()
{
    return isNew;
}



// Setters
void Laptop::setManufacturer(string m)
{
    manufacturer = m;
}

void Laptop::setProcessor(string p)
{
    processor = p;
}
void Laptop::setScreenSize(double ss)
{
    screenSize = ss;
}
void Laptop::setColor(string c)
{
    color = c;
}
void Laptop::setIsNew(bool in)
{
    isNew = in;
}



// User Input and Output
void Laptop::input()
{
    /*string manufacturer;
    string processor;
    double screenSize;
    string color;
    bool isNew;*/
    cout << "Laptop's Manufacturer? ";
    getline(cin, manufacturer);

    cout << "Laptop's Processor? ";
    getline(cin, processor);

    cout << "Laptop's Screen Size? ";
    cin >> screenSize;
    cin.ignore();

    cout << "Laptop's Color? ";
    getline(cin, color);

    cout << "Laptop's IsNew? ";
    cin >> isNew;

}

void Laptop::output()
{
    cout << "Laptop's Manufacturer: " << getManufacturer();
    cout << endl;
    cout << getManufacturer() << "'s Processor: " << getProcessor();
    cout << endl;
    cout << getManufacturer() << "'s's ScreenSize: " << getScreenSize();
    cout << endl;
    cout << getManufacturer() << "'s's Color: " << getColor();
    cout << endl;
    cout << getManufacturer() << "'s's IsNew: " << getIsNew();
    cout << endl;
}


// Constructors (Default Values)
Laptop::Laptop()
{
    manufacturer = "N/A";
    processor = "N/A";
    screenSize = 0;
    color = "N/A";
    isNew = false;
}

Laptop::Laptop(string m, string p, double ss, string c, bool in)
{
    manufacturer = m;
    processor = p;
    screenSize = ss;
    color = c;
    isNew = in;
}

int main()
{
    Laptop a, b("Dell", "Intel i5", 15.6, "black", true);
    Laptop c;
    
    a.output();
    cout << endl;

    b.output();
    cout << endl;

    c.input();
    cout << endl;

    c.output();
    
    /*cout << "A's Manufacturer: " << a.getManufacturer();
    cout << endl;
    cout << "A's Processor: " << a.getProcessor();
    cout << endl;
    cout << "A's ScreenSize: " << a.getScreenSize();
    cout << endl;
    cout << "A's Color: " << a.getColor();
    cout << endl;
    cout << "A's IsNew: " << a.getIsNew();
    cout << endl;

    cout << endl;

    cout << "B's Manufacturer: " << b.getManufacturer();
    cout << endl;
    cout << "B's Processor: " << b.getProcessor();
    cout << endl;
    cout << "B's ScreenSize: " << b.getScreenSize();
    cout << endl;
    cout << "B's Color: " << b.getColor();
    cout << endl;
    cout << "B's IsNew: " << b.getIsNew();
    cout << endl;*/

}