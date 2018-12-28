
#include "ContactFile.h"


void ContactFile::addContactToFile(Contact contact)
{
	string line = "";
	fstream textFile;
	textFile.open(contactsFileName.c_str(), ios::out | ios::app);

	if (textFile.good() == true)
	{
		line = separateContactDataWithLineSeparators(contact);

		if (HelperClass::isFileEmpty(contactsFileName) == true)
		{
			textFile << line;
		}
		else
		{
			textFile << endl << line;
		}
		textFile.close();
	}
	else
	{
		cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
	}
	system("pause");
}

string ContactFile::separateContactDataWithLineSeparators(Contact contact)
{
	string line = "";

	line += HelperClass::intToString(contact.getId()) + '|';
	line += HelperClass::intToString(contact.getUserId()) + '|';
	line += contact.getFirstName() + '|';
	line += contact.getLastName() + '|';
	line += contact.getTelephoneNumber() + '|';
	line += contact.getEmail() + '|';
	line += contact.getAddress() + '|';

	return line;

}
vector<Contact> ContactFile::loadLoggedUserContactsFromFile(int loggedUserId, int &lastContactId)
{
	vector <Contact> contacts;
	Contact contact;
	string singleContactDataWithSeparators = "";
	string lastContactData = "";
	fstream textFile;
	textFile.open(contactsFileName.c_str(), ios::in);

	if (textFile.good() == true)
	{
		while (getline(textFile, singleContactDataWithSeparators))
		{
			if (loggedUserId == getUserIdFromString(singleContactDataWithSeparators))
			{
				contact = divideLineWithSeparatorsIntoContactData(singleContactDataWithSeparators);
				contacts.push_back(contact);
			}
		}
		lastContactData = singleContactDataWithSeparators;
		textFile.close();
	}
	else
		cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

	if (lastContactData != "")
	{
		lastContactId = getContactIdFromString(lastContactData);
	}
	return contacts;
}

int ContactFile::getUserIdFromString(string line)
{
	int userIdPosition = line.find_first_of('|') + 1;
	int userId = HelperClass::stringToInt(HelperClass::getNumber(line, userIdPosition));

	return userId;
}

int ContactFile::getContactIdFromString(string line)
{
	int pozycjaRozpoczeciaIdAdresata = 0;
	int idAdresata = HelperClass::stringToInt(HelperClass::getNumber(line, pozycjaRozpoczeciaIdAdresata));
	return idAdresata;
}

Contact ContactFile::divideLineWithSeparatorsIntoContactData(string singleContactDataWithSeparators)
{
	Contact contact;
	string singleContactData = "";
	int counter = 1;

	for (int position = 0; position < singleContactDataWithSeparators.length(); position++)
	{
		if (singleContactDataWithSeparators[position] != '|')
		{
			singleContactData += singleContactDataWithSeparators[position];
		}
		else
		{
			switch (counter)
			{
			case 1:
				contact.setId(atoi(singleContactData.c_str()));
				break;
			case 2:
				contact.setUserId(atoi(singleContactData.c_str()));
				break;
			case 3:
				contact.setFirstName(singleContactData);
				break;
			case 4:
				contact.setLastName(singleContactData);
				break;
			case 5:
				contact.setTelephoneNumber(singleContactData);;
				break;
			case 6:
				contact.setEmail(singleContactData);
				break;
			case 7:
				contact.setAddress(singleContactData);
				break;
			}
			singleContactData = "";
			counter++;
		}
	}
	return contact;
}

ContactFile::~ContactFile()
{
}
