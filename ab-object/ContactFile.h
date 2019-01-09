#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "Contact.h"
#include "HelperClass.h"

class ContactFile
{
	const string contactsFileName;
	const string temporaryContactsFileName;
	string separateContactDataWithLineSeparators(Contact);
	int getUserIdFromString(string);
	int getContactIdFromString(string);

	Contact divideLineWithSeparatorsIntoContactData(string);
public:
	ContactFile(string);
	void addContactToFile(Contact);
	vector <Contact> loadLoggedUserContactsFromFile(int);
	void updateContactInFile(Contact);
	void deleteContactFromFile(Contact);
	int getLastContactIdFromFile();
	~ContactFile();
};

