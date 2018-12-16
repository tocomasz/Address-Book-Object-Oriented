#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include "User.h"
#include <vector>

using namespace std;

class AdressBook
{
	int idOfLastLoggedUser;
	int idOfLastContact;
	int idOfDeletedUser;

	vector <User> users;

	User provideNewUserLoginCredentials();
	int newUserId();
	bool isLoginTaken(string);


public:
	void registerUser();
	void printAllUsers();
	AdressBook();
	~AdressBook();
};

