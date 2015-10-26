#include <iostream>

class bank
{
public:
	static int accnumber;
	long balance;
	UserDetails d;
	void getdata();
	bank transfermoney(bank);
	void deposit();
	void withdrawal();
	void newaccount();
	void viewaccdetails();
};

