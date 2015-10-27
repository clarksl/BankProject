#include <iostream>
#include "UserDetails.h"

using namespace std;

void UserDetails::getdetails()
	{
//		name = new char[40];
		cout << endl << endl << "**********Customer Details*********** " << endl;
		cout << "          -------- -------            " << endl;
		cout << "Enter Name: ";
		std::cin >> name;
		cout << "Enter Age: ";
		cin >> age;
		cout << "Enter Account Number: ";
		cin >> accno;
		cout << "Enter Branch: ";
		cin >> branch;
		cout << "Enter City: ";
		cin >> city;
		cout << "______________________________________" << endl;
	}
int UserDetails::saveUser()
	{ cout << endl << "Function saveUser function not written yet..." << endl;
return 0;
}

