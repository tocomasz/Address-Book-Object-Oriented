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

public:
	ContactManager(string, int);
	void addNewContact();
	Contact inputNewContactData();
	void printAllContacts();
	~ContactManager();
};

