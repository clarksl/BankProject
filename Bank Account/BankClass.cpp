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
	cout << "\tAccount no.: " << accnumber << endl;
	cout << "\tName: " << d.name << endl;
	cout << "\tBranch: " << d.branch << endl;
	cout << "\tCity: " << d.city << endl;
//	printf("Current Balance : %.02f\n", balance); //this didn't work
	//std::cout.precision(2); // this didn't work
	cout << "\tCurrent Balance: $" << balance << endl;
	cout << "\t_________________________________________" << endl;
}
