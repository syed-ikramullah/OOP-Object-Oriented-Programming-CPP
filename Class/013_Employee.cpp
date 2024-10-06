/*
  Question:
Write a C++ program to implement a class called Employee that has private member variables for
name, employee ID, and salary.
Include member functions to calculate and set salary based on employee performance.
*/


                                  // .h file


#include<iostream>
using namespace std;

class Employee {
private:
	char* name;
	int ID;
	double salary;

public:
	void display()const;
	Employee();
	Employee(char* n, int id, int sal_hour, double bonus, int work_hrs);
	Employee(const Employee& obj);
	~Employee();
	double CalSalary(double sal_hrs, int work_hours, double bon);

};



                                  // .cpp file

#include "Employee.h"

void Employee::display()const {

	if (name != nullptr) {
		cout << "Employee name is: " << name << endl;
	}
	cout << "and Employee ID is: " << ID << endl;
	cout << "Salary is: " << salary << endl;
}
Employee::Employee() {
	name = nullptr;
	ID = 0;
	salary = 0;
}
Employee::Employee(char* n, int id, int sal_hour, double bonus, int work_hrs) {
	int size = strlen(n);
	name = new char[size + 1];
	for (int i = 0; i < size; i++) {
		name[i] = n[i];
	}
	name[size] = '\0';

	ID = id;
	salary = CalSalary(sal_hour, work_hrs, bonus);
}
Employee::Employee(const Employee& obj) {
	int size = strlen(obj.name);
	name = new char[size + 1];
	for (int i = 0; i < size; i++) {
		name[i] = obj.name[i];
	}
	name[size] = '\0';

	ID = obj.ID;
	salary = obj.salary;
}
Employee::~Employee() {
	delete[] name;
	cout << "Destructor called!";
}
double Employee::CalSalary(double sal_hrs, int work_hours, double bon) {
	double sal = (work_hours * sal_hrs) + bon;
	return sal;
}


                                  // main.cpp file


#include "Employee.h"

int main() {
	char nam[20];
	int id;
	double salary_per_hr;
	double bonus;
	int working_hours;

	cout << "Enter employee name: ";
	cin.getline(nam, 19);
	cout << "Enter Employee id: ";
	cin >> id;
	cout << "Enter salary per hour: ";
	cin >> salary_per_hr;
	cout << "Enter bonus: ";
	cin >> bonus;
	cout << "How many hours a week does the employee works: ";
	cin >> working_hours;

	Employee e(nam, id, salary_per_hr, bonus, working_hours);

	e.display();

	system("pause");
	return 0;
}
