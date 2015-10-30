using namespace std;
/* class definition for UserDetails
   See UserDetails.cpp for the code for the functions.
 */
class UserDetails
{
public:
	char name[50];
	int age;
	int accno; // why do we have 2 account numbers? There's already one on the Bank class.
	char branch[50];
	char city[40];
	void getdetails();
	int saveUser();
};
