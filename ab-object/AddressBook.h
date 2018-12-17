#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <sstream>
#include "User.h"


using namespace std;

class AddressBook
{
	int idOfLastLoggedUser;
	int idOfLastContact;
	int idOfDeletedUser;

	string usersFileName;

	vector <User> users;

	User provideNewUserLoginCredentials();
	int newUserId();
	bool isLoginTaken(string);
	void saveUserToFile(User);
	string addSeparatingLinesToUserData(User);
	string intToString(int);
	bool isFileEmpty(fstream &);

public:
	AddressBook();
	void registerUser();
	void printAllUsers();
	~AddressBook();
};

