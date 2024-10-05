/*
Question:
Write a C++ program to create a class called Person that has private member variables for name, age and country.
Implement member functions to set and get the values of these variables.
*/

                          // .h file

#include<iostream>
using namespace std;

class Person {
private:
	char* name;
	int age;
	char* country;
public:

	void display() const ;
	Person();
	Person(char* n, int a, char* c);
	Person(const Person& obj);
	~Person();
};


                          // .cpp file

#include "Person.h"

void Person::display() const {

	if (name != nullptr) {
		cout << "Name of the person is : " << name << endl;
	}

	cout << "Age of " << name << " is: " << age << endl;

	if (country != nullptr) {
		cout << "Country " << name << " belongs to is: " << country << endl;
	}
}
Person::Person() {
	name = nullptr;
	age = 0;
	country = nullptr;
}
Person::Person(const Person& obj) {
	int size = strlen(obj.name);
	name = new char[size + 1];
	for (int i = 0; i < size; i++) {
		name[i] = obj.name[i];
	}
	name[size] = '\0';

	age = obj.age;

	int size2 = strlen(obj.country);
	country = new char[size2 + 1];
	for (int i = 0; i < size2; i++) {
		country[i] = obj.country[i];
	}
	country[size2] = '\0';
}

Person::Person(char* n, int a, char* c) {
	int size = strlen(n);
	name = new char[size + 1];
	for (int i = 0; i < size; i++) {
		name[i] = n[i];
	}
	name[size] = '\0';

	age = a;

	int size2 = strlen(c);
	country = new char[size2 + 1];
	for (int i = 0; i < size2; i++) {
		country[i] = c[i];
	}
	country[size2] = '\0';
}
Person::~Person() {
	cout << "Destructor called!";
	delete[] name;
	delete[] country;
}


                          // main.cpp file

#include "Person.h"

int main() {

	char nm[20];    // Named like this to avoid any confusion.
	int ag;
	char cntry[20];
	cout << "Enter name of the person: ";
	cin.getline(nm, 19);

	cout << "Enter age of the person: ";
	cin >> ag;

	cin.ignore();		// Ignore the newline left in the buffer
						// If not added, the program will not take country input from the user

	cout << "Enter name of the country: ";
	cin.getline(cntry, 19);

	const Person p(nm, ag, cntry);

	p.display();

	system("pause");
	return 0;
}
