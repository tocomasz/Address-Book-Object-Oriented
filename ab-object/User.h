#pragma once
#include <iostream>

using namespace std;

class User
{
	int id;
	string login, password;

public:
	User();

	int getId();
	string getLogin();
	string getPassword();

	void setId(int);
	void setLogin(string);
	void setPassword(string);

	~User();
};

