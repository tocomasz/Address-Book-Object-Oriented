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

public:
	ContactManager(string, int);
	int addNewContact(int);
	Contact inputNewContactData(int);
	void loadLoggedUserContacts(int&);
	void printAllContacts();
	~ContactManager();
};

