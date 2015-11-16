// Bank Account.cpp : Defines the entry point for the console application.
//

#include <iostream>
// 10/27/15 slc - Commented out various header files that are currently not used - remove them later if they stay commented out
//#include <sys/stat.h>
#include <fstream>
//#include <string.h>
//#include <process.h>
//#include <stdio.h>
//#include "stdafx.h"
//#include <conio.h>
#include "UserDetails.h"
#include "BankClass.h"

const int MaxBankAccounts = 10; // Let's use a constant for the max number of bank accounts - then we don't have to change this everywhere 
using namespace std;

int bank::accnumber = 0;  // not sure why we are initializing this to zero? It should be loaded now from the file by calling readaccDetails
                          // tried to comment it out but nothing worked right afterwards.
int get_account();
int saveaccdetails(bank *a[], int count);
int readaccdetails(bank *a[], int count);

int main()
{
	//char ch;
	int i = 0;
	bank *a[MaxBankAccounts];
	int x, k=0, j=0;
	i = readaccdetails(a, MaxBankAccounts);
	cout << "number of accounts loaded" << i << endl;
	do
	{
		cout << endl << endl << "************MENU***********************" << endl;
		if (i>0)
			cout << "            ----     # Accounts: [0-" << i << "]" << endl;
		else cout << "            ----     # Accounts: [0]" << endl;
		cout << "1.Create new account\n2.Deposit\n3.Withdraw\n4.Transfer credits\n5.View account details\n6. Update Account Details\n\n9. Exit\n\n";
		cout << "Enter choice no.: ";
		cin >> x;

		switch (x)
		{
		case 1:
		{		i += 1; 
				cout << "i account variable is currently: " << i << endl;
				a[i] = new bank;  
				a[i]->newaccount();
				break;
		}
		case 2:
		{         /* this account number is really the array index and not the 'accnumber' on the class - this needs to be changed */
			// this also needs to validate that the account entered has actually been allocated - right now it crashes
				  k = get_account();
				  a[k]->deposit();
				  break;
		}
		case 3:
		{  // this also needs to validate that the account entered has actually been allocated - right now it crashes
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
		case 6:
		{		  k = get_account();
				  a[k]->updateAccDetails();
				  break;
		}
		}
	} while (x != 9);
	saveaccdetails(a, i);
	return EXIT_SUCCESS;  // Although not required, it is recommended to supply return exit code from main for portability - some operating systems require it
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
	} while (i < 0 || i>(MaxBankAccounts-1));
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
	for (j = 0; j <= count; j++)
	{
		cout << "writing out item " << j << endl; // Debugging info
		myFile.write((char*)a[j], sizeof(bank));
	}
	myFile.close();
	return j;
}

int readaccdetails(bank *a[], int count)
{
	int j = 0, return_code = 0;
	char buffer[SCHAR_MAX];
	fstream myFile;
	myFile.open("bankacct.dat", ios::in | ios::binary); return_code = errno;
	if (!myFile)
	{
		strerror_s(buffer, 80);
		cerr << "Error opening file, error code is " << return_code << ", system error returned is: " << buffer << endl;
		return 0; // 11/5/15 slc - this was -1 and causing the bug #9 
	}
	cout << "reading in item: " << j << endl; //debugging info
	a[j] = new bank;  // we must allocate a new bank object in the array or it will crash! If not there is no memory allocation location to put data
	myFile.read((char *)a[j], sizeof(bank));
	while (!myFile.eof())
	{ // even after redoing this section, it will try to read another bank object even though if you look at the file, there is only 1
		++j;
		cout << "reading in item: " << j << endl; //debugging info
		a[j] = new bank;  // we must allocate a new bank object in the array or it will crash! If not there is no memory allocation location to put data
		myFile.read((char *)a[j], sizeof(bank));
	}
	--j; /* this is only here because the eof function doesn't get detected until it's gone one read too many */
	myFile.close();
	return j;
}