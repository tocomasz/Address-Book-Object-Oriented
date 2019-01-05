#pragma once
#include <iostream>

#include "UserManager.h"
#include "ContactManager.h"


using namespace std;

class AddressBook
{

	int loggedUserId;
	int lastContactId;
	const string usersFileName;
	const string contactsFileName;
	UserManager userManager;
	ContactManager contactManager;
public:
	AddressBook(string, string);
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

