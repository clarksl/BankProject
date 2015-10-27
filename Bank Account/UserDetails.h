using namespace std;
/* class definition for UserDetails
   See UserDetails.cpp for the code for the functions.
 */
class UserDetails
{
public:
	char name[50];
	int age;
	int accno;
	char branch[50];
	char city[40];
	void getdetails();
	int saveUser();
};
