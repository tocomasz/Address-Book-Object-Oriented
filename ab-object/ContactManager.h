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

public:
	ContactManager();
	int addNewContact(int, int);
	Contact inputNewContactData(int, int);
	void loadLoggedUserContacts(int, int&);
	void printAllContacts();
	~ContactManager();
};

