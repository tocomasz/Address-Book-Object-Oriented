#pragma once
#include "Contact.h"
#include "ContactFile.h"
#include "HelperClass.h"
#include <vector>
#include <iostream>	

using namespace std;

class ContactManager
{
	vector <Contact> contacts;
	ContactFile contactFile;
	int loggedUserId;
	int lastContactId;

	void printContact(Contact contact);
	void printNumberOfContactsFound(int contactsCount);
	int chooseContact();
	char contactEditMenu();
	void updateLastContactId();


public:
	ContactManager(string, int);
	void addNewContact();
	Contact inputNewContactData();
	void printAllContacts();
	void findContactsByFirstName();
	void findContactsByLastName();
	void editContact();
	void deleteContact();
	~ContactManager();
};

