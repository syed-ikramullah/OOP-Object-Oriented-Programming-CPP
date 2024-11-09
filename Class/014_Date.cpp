/*
Task 2:
Create a class named as Date which has day, month, year as private attributes.
Write a program to create two objects of date in main(). In one you have to ask user to enter his birthDate and in other the currentDate.
Display the birthdate and currentDate of the user by display function. And then calculate age of the user from the objects and print it.

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
	void display()const;

	void setday(int D);
	void setmonth(int M);
	void setyear(int Y);
	int getday()const;
	int getmonth()const;
	int getyear()const;

	Date();
	Date(int d, int m, int y);
	bool isleapyear()const;
	bool isValid()const;
};
                                      // .cpp file

#include "Date.h"

void Date::display() const{
	if (isValid()) {
		cout << "day: " << day << endl;
		cout << "month: " << month << endl;
		cout << "year: " << year << endl;
		cout << endl << day << "/" << month << "/" << year << endl;
	}
	else {
		cout << endl << "Enter the correct date and month!";
	}
}

void Date::setday(int D) {
	day = D;
}
void Date::setmonth(int M) {
	month = M;
}
void Date::setyear(int Y) {
	year = Y;
}
int Date::getday()const {
	return day;
}
int Date::getmonth()const {
	return month;
}
int Date::getyear()const {
	return year;
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

bool Date::isleapyear() const{
	if (year % 4 == 0) {
		return true;
	}
	else {
		return false;
	}
}
bool Date::isValid() const{
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
void CalculateAge(const Date& BirthDate, const Date& CurrDate);
int main() {

	int DayOfBirth, MonthOfBirth, YearOfBirth;
	cout << "Enter your date of birth: ";
	cin >> DayOfBirth;
	cout << "Enter your month of birth: ";
	cin >> MonthOfBirth;
	cout << "Enter your year of birth: ";
	cin >> YearOfBirth;

	Date BirthDate(DayOfBirth, MonthOfBirth, YearOfBirth);


	int CurrDay, CurrMonth, CurrYear;
	cout << "Enter Current day: ";
	cin >> CurrDay;
	cout << "Enter Current month: ";
	cin >> CurrMonth;
	cout << "Enter Current year: ";
	cin >> CurrYear;

	Date CurrentDate(CurrDay, CurrMonth, CurrYear);

	cout << endl << "Birth date: " << endl;
	BirthDate.display();
	cout << endl << endl << "Current date: " << endl;
	CurrentDate.display();

	CalculateAge(BirthDate, CurrentDate);

	system("pause");
	return 0;
}

void CalculateAge(const Date& BirthDate, const Date& CurrDate) {
	int age = CurrDate.getyear() - BirthDate.getyear();
	int month = CurrDate.getmonth() - BirthDate.getmonth();
	if (month < 0) {
		age--;
	}
	
	int days = CurrDate.getday() - BirthDate.getday();
	if (days < 0) {
		month--;
	}

	cout << "Age of the user is " << age << " years, " << month << " months, and " << days << " days." << endl;

}
