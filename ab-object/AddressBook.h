#pragma once
#include <iostream>

#include "UserManager.h"
#include "ContactManager.h"


using namespace std;

class AddressBook
{
	const string CONTACTS_FILE_NAME;
	UserManager userManager;
	ContactManager *contactManager;
public:
	AddressBook(string, string);
	void registerUser();
	void printAllUsers();
	void logUserIn();
	void changeUserPassword();
	void logUserOut();
	void addContact();
	void printAllContacts();
	void findContactsByFirstName();
	void findContactsByLastName();
	void editContact();
	void deleteContact();
	int getLoggedUserId();
	~AddressBook();
};

