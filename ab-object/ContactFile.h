#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "Contact.h"
#include "HelperClass.h"

class ContactFile
{
	const string contactsFileName;
	string separateContactDataWithLineSeparators(Contact);
	int getUserIdFromString(string);
	int getContactIdFromString(string);

	Contact divideLineWithSeparatorsIntoContactData(string);
public:
	ContactFile(string CONTACTFILENAME) : contactsFileName(CONTACTFILENAME) {};
	void addContactToFile(Contact);
	vector <Contact> loadLoggedUserContactsFromFile(int, int&);
	~ContactFile();
};

