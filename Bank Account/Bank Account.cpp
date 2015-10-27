// Bank Account.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <string.h>
#include <process.h>
#include <stdio.h>
#include "stdafx.h"
#include <conio.h>
#include "UserDetails.h"
#include "BankClass.h"

using namespace std;

int bank::accnumber = 0;
int get_account();
int saveaccdetails(bank *a[], int count);
int readaccdetails(bank *a[]);

int main()
{
	char ch;
	static int i = 0;
	bank *a[10];
	int x, k, j;
	i = readaccdetails(a);
	do
	{
		cout << endl << endl << "************MENU************" << endl;
		cout << "            ----            " << endl;
		cout << "1.Create new account\n2.Deposit\n3.Withdraw\n4.Transfer credits\n5.View account details\n\n";
		cout << "Enter choice no.: ";
		cin >> x;

		switch (x)
		{
		case 1:
		{
				  a[i] = new bank;
				  a[i]->newaccount();
				  i++; 
				  break;
		}
		case 2:
		{         /* this account number is really the array index and not the 'accnumber' on the class - this needs to be changed */
				  k = get_account();
				  a[k]->deposit();
				  break;
		}
		case 3:
		{  
			k = get_account();
			a[k]->withdrawal();
				  break;
		}
		case 4:
		{
				  cout << "Enter the source and destination account nos.: ";
				  cin >> k >> j;
				  *a[j] = a[k]->transfermoney(*a[j]);
				  break;
		}
		case 5:
		{		  k = get_account();
				  a[k]->viewaccdetails();
				  break;
		}
		}cout << "\nDo you wish to continue [Press 'Y' to continue or 'N' to exit menu] : ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	saveaccdetails(a, i);
}

int get_account()
{  /* this function ensures that we get an account that fits within the array of bank accounts */
	int i;
	do {
		cout << "Enter account number [0-9]: ";
		while (!(cin >> i) || i < 0) // <<< note use of "short circuit" logical operation here
		{
			cout << "Bad input - try again: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
		}
	} while (i < 0 || i>9);
	return i;
}

int saveaccdetails(bank *a[], int count)
{  
	int j = 0, return_code=0;
	char buffer[SCHAR_MAX];
	fstream myFile;
	myFile.open("bankacct.dat", ios::out | ios::binary); return_code = errno;
	if (!myFile)
	{
		strerror_s(buffer, 80);
		cerr << "Error opening file, error code is " << return_code << ", system error returned is: " << buffer << endl;
		return -1;
	}
	for (j = 0; j < count; j++)
	{
		cout << "writing out item " << j << endl;
		myFile.write((char*)a[j], sizeof(bank));
	}
	myFile.close();
	return j;
}

int readaccdetails(bank *a[])
{
	/* this is not working yet - array is not getting set and viewing the first array after this function crashes */
	int j = 0, return_code = 0;
	char buffer[SCHAR_MAX];
	fstream myFile;
	myFile.open("bankacct.dat", ios::in | ios::binary); return_code = errno;
	if (!myFile)
	{
		strerror_s(buffer, 80);
		cerr << "Error opening file, error code is " << return_code << ", system error returned is: " << buffer << endl;
		return -1;
	}
	//for (j = 0; j < count; j++)
	//{
		cout << "reading in item " << endl;
		myFile.read((char*)&a, sizeof(bank));
		//myFile.read(&a[j], sizeof(bank));
	//}
	myFile.close();
	return j;
}