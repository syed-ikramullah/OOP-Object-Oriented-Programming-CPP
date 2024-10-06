/*
Write a C++ program to create a class called Triangle that has private member variables for
the lengths of its three sides.

Implement member functions to determine if the triangle is equilateral, isosceles, or scalene.
*/

                              // .h file

#include <iostream>
using namespace std;

class Triangle {
private:
	double side1;
	double side2;
	double side3;

public:
	void display()const;
	Triangle();
	Triangle(double s1, double s2, double s3);
	bool isValid()const;		//To check if the sides entered by the user makes a valid triangle
};


                              // .cpp file

#include "Triangle.h"

void Triangle::display()const {

	if (isValid() == false) {		//To check if the sides entered by the user makes a valid triangle
		cout << "Enter correct sides of the triangle" << endl;
		return;
	}
	else {
		if ((side1 == side2) && (side2 == side3) && (side1 == side3)) {
			cout << "Equilateral triangle" << endl;
		}
		else if ((side1 == side2) || (side2 == side3) || (side1 == side3)) {
			cout << "Isosceles Triangle" << endl;
		}
		else if ((side1 != side2) && (side2 != side3) && (side1 != side3)) {
			cout << "Scalene Triangle" << endl;
		}
	}
}
Triangle::Triangle() {
	side1 = 0.0;
	side2 = 0.0;
	side3 = 0.0;
}
Triangle::Triangle(double s1, double s2, double s3) {
	side1 = s1;
	side2 = s2;
	side3 = s3;
}
bool Triangle::isValid()const {		//To check if the sides entered by the user makes a valid triangle
	if ((side1 + side2 > side3) && (side2 + side3 > side1) && (side1 + side3 > side2)) {
		return true;
	}
	else {
		return false;
	}
}

                              // main.cpp


#include "Triangle.h"

int main() {
	int s1, s2, s3;
	cout << "Enter side 1: ";
	cin >> s1;
	cout << "Enter side 2: ";
	cin >> s2;
	cout << "Enter side 3: ";
	cin >> s3;

	Triangle t(s1, s2, s3);

	t.display();

	system("pause");
	return 0;
}
