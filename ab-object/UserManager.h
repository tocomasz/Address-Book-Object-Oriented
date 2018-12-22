#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "User.h"
#include "UserFile.h"

using namespace std;

class UserManager
{

	vector <User> users;
	UserFile userFile;

	int newUserId();
	bool isLoginTaken(string);
	User provideNewUserLoginCredentials();




public:
	UserManager() ;


	void registerUser();
	void printAllUsers();
	int logUserIn();
	void changeUserPassword(int);
	int logUserOut();


	~UserManager();
};

