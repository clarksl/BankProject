#include <iostream>

class bank
{
public:
	static int accnumber;
	float balance;
	UserDetails d;
	void getdata();
	bank transfermoney(bank);
	void deposit();
	void withdrawal();
	void newaccount();
	void viewaccdetails();
};

