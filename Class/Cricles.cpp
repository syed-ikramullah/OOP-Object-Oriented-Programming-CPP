/*
Question:
Write a C++ program to implement a class called Circle that has private member variables for radius.
Include member functions to calculate the circle's area and circumference.
*/
                            //.h file

#include<iostream> 
using namespace std;

class Circle {
private:
	double* radius;
	const double pi;		//Member/constructor initializer lists
public:
	double diameter()const;
	double circumference()const;
	double area()const;
	void display()const;
	Circle();
	Circle(double r);				//Constructor to set value
	Circle(const Circle& obj);		//Copy Constructor
	~Circle();


};


                            //.cpp file

#include"Circle.h"

	double Circle::diameter() const {
		return 2 * *radius;
	}
	double Circle::circumference() const {
		return 2 * pi * (*radius);
	}
	double Circle::area() const {
		return pi * (*radius) * (*radius);
	}
	void Circle::display() const {
		if (radius != nullptr) {
			cout << "radius is: " << *radius << endl;
		}
		cout << "pi= " << pi << endl;
	}

	Circle::Circle() :pi(22.0 / 7) {
		radius = nullptr;
	}
	Circle::Circle(double r) :pi(22.0 / 7) {
		radius = new double;
		*radius = r;
	}
	Circle::Circle(const Circle& obj) :pi(22.0 / 7) {
		radius = new double;
		*radius = *obj.radius;
	}
	Circle::~Circle() {
		delete radius;
		cout << "destructor called!!!" << endl;
	}


                            //main.cpp file

#include"Circle.h"

int main() {

	double value = 2.79;
	Circle c2(value);
	cout << "c2 display:" << endl;
	c2.display();

	Circle c3 = c2;					//Copy constructor will be called
	cout << "c3 display:" << endl;
	c3.display();

	cout << "circumference: " << c3.circumference() << endl;
	cout << "area: " << c3.area() << endl;
	cout << "diameter: " << c3.diameter() << endl;

	system("pause");
	return 0;
}
