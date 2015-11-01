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
	void updateAccDetails(); //need to change the above to camel case as well - makes the names easier to read
};

