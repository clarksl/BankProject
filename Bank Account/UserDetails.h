using namespace std;
/* class definition for UserDetails
   See UserDetails.cpp for the code for the functions.
 */
class UserDetails
{
public:
	char *name;
	int age;
	int accno;
	char branch[50];
	char city[40];
	void getdetails();
	int saveUser();
};
