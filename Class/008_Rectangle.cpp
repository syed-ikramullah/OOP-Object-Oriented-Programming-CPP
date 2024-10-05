/*
Question:
Write a C++ program to create a class called Rectangle that has private member variables for length and width.
Implement member functions to calculate the rectangle's area and perimeter.
*/

                                // .h file


#include<iostream>
using namespace std;

class Rectangle {
private:
	double length;
	double width;
public:
	double area() const;
	double perimeter() const;

	Rectangle();
	Rectangle(double l, double w);
	~Rectangle();
};


                                // .cpp file

#include "Rectangle.h"

double Rectangle::area() const {
	return length * width;
}
double Rectangle::perimeter() const {
	return 2 * (length + width);
}

Rectangle::Rectangle() {
	length = 0.0;
	width = 0.0;
}
Rectangle::Rectangle(double l, double w) {
	length = l;
	width = w;
}
Rectangle::~Rectangle() {
	cout << "constructor called!!!";
}



                                // main.cpp file

#include "Rectangle.h"

int main() {

	Rectangle t1;

	Rectangle t2(2.22, 3.33);

	cout << "area of the triangle is: " << t2.area() << endl;
	cout << "perimeter of the rectangle: " << t2.perimeter() << endl;

	system("pause");
	return 0;
}
