#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "UserDetails.h"
#include "BankClass.h"

bank bank::transfermoney(bank a)
{
	long amt;
	cout << "Enter amount to be transferred: ";
	cin >> amt;
	a.balance = a.balance + amt;
	if (balance<amt)
	{
		cout << "\nInsufficient balance! Operation Cannot be performed!" << endl << endl;
	}
	else
	{
		balance = balance - amt;
	}
	return a;
}
void bank::withdrawal()
{
	int amtdrawn;
	cout << "Enter amount to be withdrawn: ";
	cin >> amtdrawn;
	if (balance <= amtdrawn)
		cout << "\nInsufficient balance! Operation Cannot be performed!" << endl << endl;
	else
		balance = balance - amtdrawn;
}
void bank::deposit()
{
	int dep;
	cout << "Enter amount to be deposited: ";
	cin >> dep;
	balance += dep;
}
void bank::newaccount()
{
	accnumber++;
	d.getdetails();
	balance = 0;
}
void bank::viewaccdetails()
{  // this function needs to validate that the given account is truly been allocated, that or add a check in the main
	cout << endl << endl << "*********ASSIGNMENT BANK ACCOUNT DETAILS*********" << endl;
	cout << "         --- ---- ------- -------         " << endl;
	cout << "\tAccount no.: " << d.accno << endl;
	cout << "\tName: " << d.name << endl;
	cout << "\tBranch: " << d.branch << endl;
	cout << "\tCity: " << d.city << endl;
//	printf("Current Balance : %.02f\n", balance); //this didn't work
	//std::cout.precision(2); // this didn't work
	cout << "\tCurrent Balance: $" << balance << endl;
	cout << "\t_________________________________________" << endl;
}

void bank::updateAccDetails()
{  // this function needs to validate that the given account is truly been allocated, that or add a check in the main
	cout << endl << endl << "\t********* UPDATE BANK ACCOUNT DETAILS*********" << endl;
	cout << "         --- ---- ------- -------         " << endl;
	cout << "\tAccount no.: " << accnumber << endl;
	cout << "\tEnter New Account Number: ";
	cin >> d.accno;
	cout << "\tName: " << d.name << endl;
	cout << "\tEnter New Name: ";
	cin >> d.name;
	cout << "\tBranch: " << d.branch << endl;
	cout << "\tEnter Branch: ";
	cin >> d.branch;
	cout << "\tCity: " << d.city << endl;
	cout << "\tEnter City: ";
	cin >> d.city;
	cout << "\tAge: " << d.age << endl;
	cout << "\tEnter Age: ";
	cin >> d.age;
	cout << "\t_________________________________________" << endl;
}
