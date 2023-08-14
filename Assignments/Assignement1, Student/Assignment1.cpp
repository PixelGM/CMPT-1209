#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student
{
    string firstName;
    string lastName;
    string studentID;
    string phoneNumber;
    double gpa;

public:
    Student(string fName = " ", string lName = " ", string sID = " ", string phone = " ", double g = 0.0);

    // Getters
    string getFirstName() const;
    string getLastName() const;
    string getStudentID() const;
    string getPhoneNumber() const;
    double getGpa() const;

    // Setters
    void setFirstName(string fName);
    void setLastName(string lName);
    void setStudentID(string sID);
    void setPhoneNumber(string phone);
    void setGpa(double g);

    void input();
    void output() const;
};

Student::Student(string fName, string lName, string sID, string phone, double g)
{
    firstName = fName;
    lastName = lName;
    studentID = sID;
    phoneNumber = phone;
    gpa = g;
}

string Student::getFirstName() const
{
    return firstName;
}

string Student::getLastName() const
{
    return lastName;
}

string Student::getStudentID() const
{
    return studentID;
}

string Student::getPhoneNumber() const
{
    return phoneNumber;
}

double Student::getGpa() const
{
    return gpa;
}

void Student::setFirstName(string fName)
{
    firstName = fName;
}

void Student::setLastName(string lName)
{
    lastName = lName;
}

void Student::setStudentID(string sID)
{
    studentID = sID;
}

void Student::setPhoneNumber(string phone)
{
    phoneNumber = phone;
}

void Student::setGpa(double g)
{
    gpa = g;
}

void Student::input()
{
    cout << "Enter the following student details:\n";
    cout << "First name: ";
    cin >> firstName;
    cout << "Last name: ";
    cin >> lastName;
    cout << "Student ID: ";
    cin >> studentID;
    cout << "Phone number: ";
    cin >> phoneNumber;
    cout << "GPA: ";
    cin >> gpa;
}

void Student::output() const
{
    cout << "First name: " << firstName << "\nLast name: " << lastName << "\nStudent ID: " << studentID << "\nPhone number: " << phoneNumber << "\nGPA: " << gpa << "\n";
}

class Course
{
    string code;
    int section;
    int capacity;
    int numStudents;
    Student* list;

public:
    Course(string c = "CMPT", int s = 1, int cap = 35);
    ~Course();

    // Getters
    string getCode() const;
    int getSection() const;
    int getCapacity() const;
    int getNumStudents() const;

    // Setters
    void setCode(string c);
    void setSection(int s);

    // Other member functions
    void add(Student& s);
    void display() const;
    void displayByFirst(string fName) const;
    void displayByLast(string lName) const;
    void displayByID(string sID) const;
    void displayByPhone(string phone) const;
    void remove(string phone);
    void bubbleSort(bool(*)(const Student&, const Student&));
    void swap(Student&, Student&);
    void sortByFirstAsc();
    void sortByFirstDes();
    void sortByLastAsc();
    void sortByLastDes();
    void sortByIDAsc();
    void sortByIDDes();
    void sortByPhoneAsc();
    void sortByPhoneDes();
    void sortByGPAAsc();
    void sortByGPADes();
};

Course::Course(string c, int s, int cap)
{
    code = c;
    section = s;
    capacity = cap;
    numStudents = 0;
    list = new Student[capacity];
}

Course::~Course()
{
    delete[] list;
}

string Course::getCode() const
{
    return code;
}

int Course::getSection() const
{
    return section;
}

int Course::getCapacity() const
{
    return capacity;
}

int Course::getNumStudents() const
{
    return numStudents;
}

void Course::setCode(string c)
{
    code = c;
}

void Course::setSection(int s)
{
    section = s;
}

void Course::add(Student& s)
{
    if (numStudents < capacity)
    {
        list[numStudents] = s;
        numStudents++;
    }
    else
    {
        cout << "Course is full.\n";
    }
}

void Course::display() const
{
    for (int i = 0; i < numStudents; i++)
    {
        list[i].output();
        cout << "\n";
    }
}

void Course::displayByFirst(string fName) const
{
    for (int i = 0; i < numStudents; i++)
    {
        if (list[i].getFirstName() == fName)
        {
            list[i].output();
            cout << "\n";
        }
    }
}

void Course::displayByLast(string lName) const
{
    for (int i = 0; i < numStudents; i++)
    {
        if (list[i].getLastName() == lName)
        {
            list[i].output();
            cout << "\n";
        }
    }
}

void Course::displayByID(string sID) const
{
    for (int i = 0; i < numStudents; i++)
    {
        if (list[i].getStudentID() == sID)
        {
            list[i].output();
            cout << "\n";
        }
    }
}

void Course::displayByPhone(string phone) const
{
    for (int i = 0; i < numStudents; i++)
    {
        if (list[i].getPhoneNumber() == phone)
        {
            list[i].output();
            cout << "\n";
        }
    }
}

void Course::remove(string phone)
{
    int index = -1;
    for (int i = 0; i < numStudents; i++)
    {
        if (list[i].getPhoneNumber() == phone)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        for (int i = index; i < numStudents - 1; i++)
        {
            list[i] = list[i + 1];
        }
        numStudents--;
    }
}

// Swap function
void Course::swap(Student& a, Student& b)
{
    Student temp = a;
    a = b;
    b = temp;
}

void Course::bubbleSort(bool(*compFunc)(const Student&, const Student&))
{
    for (int i = 0; i < numStudents; i++)
    {
        for (int j = 0; j < numStudents - i - 1; j++)
        {
            if (compFunc(list[j], list[j + 1]))
                swap(list[j], list[j + 1]);
        }
    }
}

void Course::sortByFirstAsc()
{
    bubbleSort([](const Student& a, const Student& b)
        {
            return a.getFirstName() > b.getFirstName();
        });
}

void Course::sortByFirstDes()
{
    bubbleSort([](const Student& a, const Student& b)
        {
            return a.getFirstName() < b.getFirstName();
        });
}

void Course::sortByLastAsc()
{
    bubbleSort([](const Student& a, const Student& b)
        {
            return a.getLastName() > b.getLastName();
        });
}

void Course::sortByLastDes()
{
    bubbleSort([](const Student& a, const Student& b)
        {
            return a.getLastName() < b.getLastName();
        });
}

void Course::sortByIDAsc()
{
    bubbleSort([](const Student& a, const Student& b)
        {
            return a.getStudentID() > b.getStudentID();
        });
}

void Course::sortByIDDes()
{
    bubbleSort([](const Student& a, const Student& b)
        {
            return a.getStudentID() < b.getStudentID();
        });
}

void Course::sortByPhoneAsc()
{
    bubbleSort([](const Student& a, const Student& b)
        {
            return a.getPhoneNumber() > b.getPhoneNumber();
        });
}

void Course::sortByPhoneDes()
{
    bubbleSort([](const Student& a, const Student& b)
        {
            return a.getPhoneNumber() < b.getPhoneNumber();
        });
}

void Course::sortByGPAAsc()
{
    bubbleSort([](const Student& a, const Student& b)
        {
            return a.getGpa() > b.getGpa();
        });
}

void Course::sortByGPADes()
{
    bubbleSort([](const Student& a, const Student& b)
        {
            return a.getGpa() < b.getGpa();
        });
}




int main()
{
    // Create a course object
    Course cmpt("CMPT", 130, 100);

    // Create some student objects
    Student john("John", "Doe", "1234", "604-555-1234", 3.7);
    Student jane("Jane", "Doe", "2345", "604-555-2345", 3.9);
    Student alice("Alice", "Smith", "3456", "604-555-3456", 3.6);

    // Add students to the course
    cmpt.add(john);
    cmpt.add(jane);
    cmpt.add(alice);

    // Display all students in the course
    cout << "================ All students in the course ================" << endl;
    cmpt.display();
    cout << "===========================================================" << endl << endl;

    // Display students by specific attribute
    cout << "================ Students with first name 'John' ================" << endl;
    cmpt.displayByFirst("John");
    cout << "===============================================================" << endl << endl;

    cout << "================ Students with last name 'Doe' ================" << endl;
    cmpt.displayByLast("Doe");
    cout << "==============================================================" << endl << endl;

    // Sorting examples
    cout << "========= Students sorted by first name (ascending) =========" << endl;
    cmpt.sortByFirstAsc();
    cmpt.display();
    cout << "============================================================" << endl << endl;

    cout << "========= Students sorted by last name (descending) =========" << endl;
    cmpt.sortByLastDes();
    cmpt.display();
    cout << "=============================================================" << endl << endl;

    // Removing a student
    cout << "========= Removing student with phone number '604-555-2345' =========" << endl;
    cmpt.remove("604-555-2345");
    cmpt.display();
    cout << "=====================================================================" << endl << endl;

    return 0;
}