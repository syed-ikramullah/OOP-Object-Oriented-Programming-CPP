/*
Question:
Write a C++ program to implement a class called BankAccount that has private member variables for 
account number and balance.Include member functions to deposit and withdraw money from the account.
*/


                              // .h file

#include<iostream>
using namespace std;

class BankAcc {
private:
	int AccNum = 1234567890;
	int balance = 150000;
	int deposit;
	int withdraw;
public:

	void display()const;
	void setdep(int dep);
	void setwith(int with);
	int getdep();
	int getwith();

};


                              // .cpp file

#include "BankAcc.h"

void BankAcc::display() const {
	cout << "Account Number is: " << AccNum << endl;
	cout << "Ammount withdrawn is: " << withdraw << endl;
	cout << "Ammount deposited is: " << deposit << endl;
	cout << "Current Balancce is: " << balance << endl;
}

void BankAcc::setdep(int dep) {
	balance = balance + dep;
	deposit = dep;
	withdraw = 0;
}
void BankAcc::setwith(int with) {
	if (with <= balance)
	{
		balance = balance - with;
		withdraw = with;
		deposit = 0;
	}
	else {
		cout << "Insufficient balance!";
	}
}
int BankAcc::getdep() {
	return deposit;
}
int BankAcc::getwith() {
	return withdraw;
}


                              //main.cpp

#include "BankAcc.h"

int main() {

	int depamm;
	int withamm;
	char choice;

	BankAcc BA;


	cout << "Do you want to deposit aur withdraw  money? (Press D/W): ";
	cin >> choice;

	if ((choice == 'D') || (choice == 'd')) {
		cout << "Enter the ammount you want to deposit: ";
		cin >> depamm;

		BA.setdep(depamm);
	}
	else if ((choice == 'W') || (choice == 'w')) {
		cout << "Enter the ammount you want to withdraw: ";
		cin >> withamm;

		BA.setwith(withamm);
	}
	else {
		cout << "Incorrect input";
	}

	BA.display();

	system("pause");
	return 0;
}
