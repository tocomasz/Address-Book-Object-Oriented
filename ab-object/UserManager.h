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
	int loggedUserId;

	
	int newUserId();
	bool isLoginTaken(string);
	User provideNewUserLoginCredentials();
	
public:
	UserManager(string) ;
	
	void registerUser();
	void printAllUsers();
	void logUserIn();
	void changeUserPassword();
	void logUserOut();
	int getLoggedUserId();
	bool isUserLoggedIn();


	~UserManager();
};

