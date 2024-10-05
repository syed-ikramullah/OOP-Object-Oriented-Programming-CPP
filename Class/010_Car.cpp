/*
Write a C++ program to create a class called Car that has private member variables for
company, model, and year.
Implement member functions to get and set these variables.
*/

                                  // .h file

#include<iostream>
using namespace std;

class Car {
private:
	char* company;
	char* model;
	int year;
public:

	void display()const;
	Car();
	Car(char* co, char* mod, int yr);
	Car(const Car& obj);				// Deep copy constructor (if needed)
	~Car();

};

                                  // .cpp file

#include "Car.h"

void Car::display() const {
	if(company!=nullptr)
	{
		cout << "Company is: " << company << endl;
	}
	if(model!=nullptr)
	{
		cout << "Model is: " << model << endl;
	}
	cout << "Year: " << year << endl;
}
Car::Car() {
	company = nullptr;
	model = nullptr;
	year = 0;
}
Car::Car(char* co, char* mod, int yr) {
	int size = strlen(co);
	company = new char[size + 1];
	for (int i = 0; i < size; i++) {
		company[i] = co[i];
	}
	company[size] = '\0';

	int size2 = strlen(mod);
	model = new char[size2 + 1];
	for (int i = 0; i < size2; i++) {
		model[i] = mod[i];
	}
	model[size2] = '\0';

	year = yr;
}
Car::Car(const Car& obj) {				// Deep copy constructor (if needed)
	int size = strlen(obj.company);
	company = new char[size + 1];
	for (int i = 0; i < size; i++) {
		company[i] = obj.company[i];
	}
	company[size] = '\0';

	int size2 = strlen(obj.model);
	model = new char[size2 + 1];
	for (int i = 0; i < size2; i++) {
		model[i] = obj.model[i];
	}
	model[size2] = '\0';

	year = obj.year;
}

Car::~Car() {
	delete[] company;
	delete[] model;
	cout << "Destructor called!!!";
}


                                  // main.cpp file

/*
Write a C++ program to create a class called Car that has private member variables for
company, model, and year.
Implement member functions to get and set these variables.
*/

#include "Car.h"

int main() {
	char company[20] = { "Toyota" };
	char model[10] = { "Corola" };
	int year = 2007;

	Car c(company, model, year);

	c.display();

	system("pause");
	return 0;
}

