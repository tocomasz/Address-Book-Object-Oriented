#pragma once
#include <iostream>

#include "UserManager.h"


using namespace std;

class AddressBook
{
	UserManager userManager;
	int loggedUserId;
public:
	AddressBook();
	void registerUser();
	void printAllUsers();
	void logUserIn();
	void changeUserPassword();
	void logUserOut();
	~AddressBook();
};

