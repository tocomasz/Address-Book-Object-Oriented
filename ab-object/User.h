#pragma once
#include <iostream>

using namespace std;

class User
{
	int id;
	string login, password;

public:
	User();

	int getUserId();
	string getUserLogin();
	string getUserPassword();

	void setUserId(int);
	void setUserLogin(string);
	void setUserPassword(string);

	~User();
};

