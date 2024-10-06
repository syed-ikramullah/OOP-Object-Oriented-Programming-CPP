/*
Write a C++ program to implement a class called Date that has private member variables for day, month, and year.
Include member functions to set and get these variables, as well as to validate if the date is valid.
*/


                                      // .h file

#include <iostream>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;

public:
	void display();
	Date();
	Date(int d, int m, int y);
	Date(const Date& obj);
	bool isleapyear();
	bool isValid();
};

                                      // .cpp file

#include "Date.h"

void Date::display() {
	if (!isValid()) {
		cout << endl << "Enter correct date and month!";
	}
	else {
		cout << "day: " << day << endl;
		cout << "month: " << month << endl;
		cout << "year: " << year << endl;
		cout << endl << day << "/" << month << "/" << year << endl;
	}
}
Date::Date() {
	day = 0;
	month = 0;
	year = 0;
}
Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}
Date::Date(const Date& obj) {
	day = obj.day;
	month = obj.month;
	year = obj.year;
}
bool Date::isleapyear() {
	if (year % 4 == 0) {
		return true;
	}
	else {
		return false;
	}
}
bool Date::isValid() {
	if (isleapyear() && (month == 2) && (day <= 29)) {
		return true;
	}
	if (!isleapyear() && (month == 2) && (day <= 28)) {
		return true;
	}
	if ((month == 4) || (month == 6) || (month == 9) || (month == 11) && (day > 0) && (day < 31)) {
		return true;
	}
	if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12) && (day > 0) && (day <= 31)) {
		return true;
	}
	else {
		return false;
	}
}


                                      // main.cpp


#include "Date.h"

int main() {

	int d, m, y;
	cout << "Enter day: ";
	cin >> d;
	cout << "Enter month: ";
	cin >> m;
	cout << "Enter year: ";
	cin >> y;

	Date D(d, m, y);

	D.display();

	system("pause");
	return 0;
}

