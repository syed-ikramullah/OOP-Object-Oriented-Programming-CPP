/*
Question:
Write a C++ program to implement a class called Student that has private member variables for name, class, roll number, and marks.
Include member functions to calculate the grade based on the marks and display the student's information.
*/

                                              // .h file

#include <iostream>
using namespace std;

class Student {
private:
	char* name;
	int Class;
	int roll_no;
	double marks;

public:
	void display()const;

	Student();
	Student(char* n, int c, int rn, double m);
	~Student();
	char cal_grade(double mar)const;
};


                                              // .cpp file

#include "Student.h"

void Student::display()const {
	if (name != nullptr) {
		cout << "Name of the Student is: " << name << endl;
	}
	cout << "Class: " << Class << endl;
	cout << "Roll no: " << roll_no << endl;
	cout << "Marks: " << marks << endl;
	cout << "Grade: " << cal_grade(marks) << endl;
}

Student::Student() {
	name = nullptr;
	Class = 0;
	roll_no = 0;
	marks = 0.0;
}
Student::Student(char* n, int c, int rn, double m) {
	int size = strlen(n);
	name = new char[size + 1];
	for (int i = 0; i < size; i++) {
		name[i] = n[i];
	}
	name[size] = '\0';

	Class = c;
	roll_no = rn;
	marks = m;
}
Student::~Student() {
	delete[] name;
	cout << "Destructor called!";
}
char Student::cal_grade(double mar)const {
	if ((mar >= 90) && (mar <= 100)) {
		return 'A';
	}
	else if ((mar >= 80) && (mar < 90)) {
		return 'B';
	}
	else if ((mar >= 65) && (mar < 80)) {
		return 'C';
	}
	else if ((mar >= 50) && (mar < 65)) {
		return 'D';
	}
	else {
		return 'F';
	}
}


                                              // main.cpp file


#include "Student.h"

int main() {
	char name[20];
	int rollno, Class;
	double marks;
	cout << "Enter name of the student: ";
	cin.getline(name, 19);
	cout << "Enter roll no of the student: ";
	cin >> rollno;
	cout << "Enter class of the student: ";
	cin >> Class;
	cout << "Enter marks of the student: ";
	cin >> marks;

	Student St(name, Class, rollno, marks);

	St.display();

	system("pause");
	return 0;
}

