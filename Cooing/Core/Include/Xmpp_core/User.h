#ifndef _USER
#define _USER

#include <string>
using namespace std;

class User
{
private:
	string username;
	string name;
	string email;

public:
	string GetUsername(){return username;}
	string GetName(){return name;}
	string GetEmail(){return email;}

	User(string _username, string _name, string _email)
	{
		username = _username;
		name = _name;
		email = _email;
	}
};

#endif