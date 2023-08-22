#include <iostream>

using namespace std;

class PersonData
{
protected:
	string lastName;
	string firstName;
	string address;
	string city;
	string state;
	int zip;
	long long phone;

public:
	// Accessors(using const because it's safer and more efficient)
	string getLastName() const { return lastName; }
	string getFirstName() const { return firstName; }
	string getAddress() const { return address; }
	string getCity() const { return city; }
	string getState() const { return state; }
	int getZip() const { return zip; }
	long long getPhone() const { return phone; }

	// Mutators (Passing by reference & for saving memory 
	// and const to avoid bugs).
	void setLastName(const string& ln) { lastName = ln; }
	void setFirstName(const string& fn) { firstName = fn; }
	void setAddress(const string& ad) { address = ad; }
	void setCity(const string& ct) { city = ct; }
	void setState(const string& st) { state = st; }
	// Not passing by reference with int becaue it's not worth it
	void setZip(int zp) { zip = zp; }
	void setPhone(long long ph) { phone = ph; }
};

class CustomerData : public PersonData
{
protected:
	int customerNumber;
	bool mailingList;

public:
	// Accessors (using const because it's safer and more efficient)
	int getCustomerNumber() const { return customerNumber; }
	bool getMailingList() const { return mailingList; }

	// Mutators
	void setCustomerNumber(int cn) { customerNumber = cn; }
	void setMailingList(bool ml) { mailingList = ml; }
};

class PreferredCustomer : public CustomerData
{
private:
	double purchasesAmount;
	double discountLevel;

public:
	// Accessors (using const because it's safer and more efficient)
	double getPurchasesAmount() const { return purchasesAmount; }
	double getDiscountLevel() const { return discountLevel; }

	// Mutators
	void setPurchasesAmount(double pa)
	{ 
		if (pa < 0)
		{
			cout << "Warning! Purchase Amount is minus! It will be set to 0!" << endl;
			purchasesAmount = 0;
		}
		else
		{
			purchasesAmount = pa;
		}

		updateDiscountLevel();
	}
	
private:
	// Make in private, just to be safe
	void updateDiscountLevel() 
	{
		// 2000 first, because if I do 500 first, discountLevel would be set to 0.05 even if I set purchasesAmount to 10000. 
		if (purchasesAmount >= 2000) 
		{
			discountLevel = 0.1;
		}
		else if (purchasesAmount >= 1500) 
		{
			discountLevel = 0.07;
		}
		else if (purchasesAmount >= 1000) 
		{
			discountLevel = 0.06;
		}
		else if (purchasesAmount >= 500) 
		{
			discountLevel = 0.05;
		}
		else 
		{
			discountLevel = 0;
		}
	}

	// Don't need, because it calculates itself with function updateDiscountLevel()
	/*void setDiscountLevel(double dl) { discountLevel = dl; }*/
};


int main()
{
	PreferredCustomer a;
	a.setFirstName("John");
	a.setLastName("Lark");

	a.setPurchasesAmount(1000);

	cout << "Purchase Amount: " << a.getPurchasesAmount() << endl;
	cout << "Discount Level: " << a.getDiscountLevel() << endl;


	cout << endl;


	PreferredCustomer b;
	b.setFirstName("Ethan");
	b.setLastName("Hunt");

	b.setPurchasesAmount(-1);

	cout << "Purchase Amount: " << b.getPurchasesAmount() << endl;
	cout << "Discount Level: " << b.getDiscountLevel() << endl;

}