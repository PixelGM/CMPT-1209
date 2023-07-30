#include <iostream>
#include <string>

using namespace std;

class Numbers
{
private:
    int number;
    void printHelper(int number) const;

public:
    static string lessThan20[20];
    static string tens[10];
    static string hundred;
    static string thousand;
    int getNumber() const;
    void setNumber(int = 0);
    void print() const;

    Numbers(int);
};

void Numbers::setNumber(int a)
{
    if (a < 0 || a > 9999)
    {
        cout << "Number out of range." << endl;
        return;
    }
    else
    {
        number = a;
    }
}

Numbers::Numbers(int a)
{
    setNumber(a);
}

int Numbers::getNumber() const
{
    return number;
}

void Numbers::printHelper(int number) const
{
    if (number < 20)
    {
        cout << lessThan20[number];
    }
    else if (number < 100)
    {
        cout << tens[number / 10];
        if (number % 10)
        {
            cout << " " << lessThan20[number % 10];
        }
    }
    else
    {
        if (number >= 1000)
        {
            cout << lessThan20[number / 1000] << " " << thousand;
            number %= 1000;
            if (number) cout << " ";
        }
        if (number >= 100)
        {
            cout << lessThan20[number / 100] << " " << hundred;
            number %= 100;
            if (number) cout << " ";
        }
        if (number >= 20)
        {
            cout << tens[number / 10];
            number %= 10;
            if (number) cout << "-";
        }
        if (number)
        {
            cout << lessThan20[number];
        }
    }
}

void Numbers::print() const
{
    printHelper(number);
    cout << endl;
}

string Numbers::lessThan20[20] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
string Numbers::tens[10] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";

int main()
{
    int num;
    cout << "Enter a number (0 - 9999): ";
    cin >> num;
    Numbers a(num);
    a.print();
    return 0;
}
