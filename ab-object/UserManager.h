#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "User.h"
#include "UserFile.h"

using namespace std;

class UserManager
{
	int loggedUserId;
	vector <User> users;
	UserFile userFile;

	int newUserId();
	bool isLoginTaken(string);
	User provideNewUserLoginCredentials();



public:
	UserManager();


	void registerUser();
	int logUserIn();

	~UserManager();
};
