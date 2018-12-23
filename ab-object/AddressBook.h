#pragma once
#include <iostream>

#include "UserManager.h"
#include "ContactManager.h"


using namespace std;

class AddressBook
{
	UserManager userManager;
	ContactManager contactManager;
	int loggedUserId;
	int lastContactId;
public:
	AddressBook();
	void registerUser();
	void printAllUsers();
	void logUserIn();
	void changeUserPassword();
	void logUserOut();
	void addContact();
	void loadContacts();
	void printAllContacts();
	~AddressBook();
};

