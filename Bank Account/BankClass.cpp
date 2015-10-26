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
{
	cout << endl << endl << "*********ASSIGNMENT BANK ACCOUNT DETAILS*********" << endl;
	cout << "         --- ---- ------- -------         " << endl;
	cout << "Account no.: " << accnumber << endl;
	cout << "Name: " << d.name << endl;
	cout << "Branch: " << d.branch << endl;
	cout << "City: " << d.city << endl;
	cout << "Current Balance: " << balance << endl;
	cout << "_________________________________________" << endl;
}
