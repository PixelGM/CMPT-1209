// Joshua A. Prayogo, Midterm Exam - Spring/Summer 2023

#include <iostream>

using namespace std;

// Money Class
class Money
{
private:
	int dollars;
	int cents;

public:
	// Constructor
	Money(int d = 0, int c = 0)
	{
		dollars = d;
		cents = c;
	}



	// Getters
	int getDollars() const
	{
		return dollars;
	}

	int getCents() const
	{
		return cents;
	}



	// Setters
	void setDollars(int d)
	{
		dollars = d;
	}

	void setCents(int c)
	{
		cents = c;
	}



	// Other Functions
	// Input
	void input()
	{
		do
		{
			// Ask user for Dollar
			cout << "Input Dollar: ";
			cin >> dollars;

			// Ask user for Cents
			cout << "Input Cents: ";
			cin >> cents;

			// Print Invalid Input if input is invalid
			if (dollars < 0 || cents < 0 || cents > 99)
				cout << "Invalid Input, Please Try Again." << endl << endl;

		} while (dollars < 0 || cents < 0 || cents > 99); // Try again if invalid input
	}

	void output()
	{
		if (cents < 10)
		{
			cout << "Your Money: " << "$" << dollars << ".0" << cents << endl;
		}
		else
		{
			cout << "Your Money: " << "$" << dollars << "." << cents << endl;
		}
	}



	// Operator Overloads (Member)
	// Operator+
	Money operator+(Money right)
	{
		Money sum;
		sum.dollars = dollars + right.dollars;
		sum.cents = cents + right.cents;

		return sum;
	}

	// Operator-
	Money operator-(Money right)
	{
		Money sum;
		sum.dollars = dollars - right.dollars;
		sum.cents = cents - right.cents;

		return sum;
	}

	// Operator* (Multiplication with INT NUMBER)
	Money operator*(int right)
	{
		Money sum;

		sum.dollars = dollars * right;
		sum.cents = cents * right;

		// If sum.cents 100 or more
		if (sum.cents >= 100)
		{
			sum.cents = sum.cents % 100;
			
			// TO be Fixed
			sum.dollars = sum.dollars + (100 / sum.cents);
		}

		return sum;
	}

	// Operators Overloads (Non-Member Friend)
	friend bool operator==(const Money& left, const Money& right);
	friend bool operator<(const Money& left, const Money& right);
	friend bool operator>(const Money& left, const Money& right);
	friend ofstream operator<<(const Money& left, const Money& right);
};


bool operator==(const Money& left, const Money& right)
{
	return (left.cents == right.cents && left.dollars == right.dollars);
}

bool operator<(const Money& left, const Money& right)
{
	if (left.dollars < right.dollars)
	{
		return true;
	}
	else if (left.dollars == right.dollars && left.cents < right.cents)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator>(const Money& left, const Money& right)
{
	if (left.dollars > right.dollars)
	{
		return true;
	}
	else if (left.dollars == right.dollars && left.cents > right.cents)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//ofstream operator<<(const Money& left, const Money& right)
//{
//
//}

// Inventory Class
class Inventory
{
private:
	string retailer;
	int capacity;
	int numItems;
	string* itemName;
	Money* price;

public:
	// Default Constructor (No-Args) and Constructor (1 mark + 1 mark = 2 marks)
	Inventory(string r = "Walmart", int c = 100)
	{
		retailer = r;
		capacity = c;
		numItems = 0;

		itemName = new string[capacity];
		price = new Money[capacity];
	}

	// Destructor
	~Inventory()
	{
		delete[] price;
		numItems--;
	}




	// Acessors
	string getRetailer() const
	{
		return retailer;
	}

	int getCapacity() const
	{
		return capacity;
	}

	int getNumItems() const
	{
		return numItems;
	}



	// Mutators
	void setRetailer(string r)
	{
		retailer = r;
	}



	// Other Functions
	// Args: (itemName, price)
	void addItem(string i, Money p)
	{
		itemName[numItems] = i;
		price[numItems] = p;
		numItems++;
	}

	void display()
	{
		for (int i = 0; i < numItems; i++)
		{
			cout << "------------------------" << endl;
			cout << "Item Name: " << itemName[i] << endl;
			cout << "Price: ";
			price[i].output();
			cout << endl;
		}
	}

	// Bubble Sort
	void sort()
	{
		for (int i = 0; i < numItems; i++)
		{
			for (int j = 0; j < numItems - 1; j++)
			{
				if (itemName[j] < itemName[j + 1])
				{
					swap(itemName[j], itemName[j + 1]);
					swap(price[j], price[j + 1]);
				}
			}
		}
	}
};


int main()
{
	Money a(18, 95), b, c(15), d(100,10), e(50,75);
	Inventory x("BestBuy", 200);
	x.addItem("Box Packaging", b);
	x.addItem("Mouse Pad", a);
	x.addItem("Monitor", d);
	x.addItem("Keyboard", e);

	x.sort();

	x.display();
}
