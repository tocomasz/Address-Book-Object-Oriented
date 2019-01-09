
#include "ContactFile.h"

ContactFile::ContactFile(string CONTACTFILENAME)
	: contactsFileName(CONTACTFILENAME), temporaryContactsFileName("temporaryContactsFile.txt")
{

}

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
	HelperClass::pauseProgram();
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
vector<Contact> ContactFile::loadLoggedUserContactsFromFile(int loggedUserId)
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

	return contacts;
}

void ContactFile::updateContactInFile(Contact contact)
{
	string contactNewData = separateContactDataWithLineSeparators(contact);
	fstream textFile, temp;
	textFile.open(contactsFileName.c_str(), ios::in);
	temp.open(temporaryContactsFileName.c_str(), ios::out);
	if (textFile.good() && temp.good())
	{
		string loadedLine = "";
		bool isFirstLine = true;
		while (getline(textFile, loadedLine))
		{
			if (!isFirstLine)
				temp << endl;
			if (getContactIdFromString(loadedLine) == contact.getId())
			{
				temp << contactNewData;
				isFirstLine = false;
				continue;
			}
			temp << loadedLine;
			isFirstLine = false;
		}
	}
	textFile.close();
	textFile.clear();
	temp.close();
	temp.clear();
	remove(contactsFileName.c_str());
	rename(temporaryContactsFileName.c_str(), contactsFileName.c_str());
}

void ContactFile::deleteContactFromFile(Contact contact)
{
	fstream textFile, temp;
	textFile.open(contactsFileName.c_str(), ios::in);
	temp.open(temporaryContactsFileName.c_str(), ios::out);
	if (textFile.good() && temp.good())
	{
		string loadedLine = "";
		bool isFirstLine = true;
		while (getline(textFile, loadedLine))
		{
			if (getContactIdFromString(loadedLine) == contact.getId())
				continue;
			if (!isFirstLine)
				temp << endl;
			temp << loadedLine;
			isFirstLine = false;
		}
	}
	textFile.close();
	textFile.clear();
	temp.close();
	temp.clear();
	remove(contactsFileName.c_str());
	rename(temporaryContactsFileName.c_str(), contactsFileName.c_str());
}

int ContactFile::getLastContactIdFromFile()
{
	fstream textFile, temp;
	textFile.open(contactsFileName.c_str(), ios::in);
	if (!textFile.good())
		return 0;
	else
	{
		textFile.seekg(-3, ios_base::end);
		if ((int)textFile.tellg() <= 1)
			return 0;
		else
		{
			while (1)
			{
				char ch;
				textFile.get(ch);
				if (ch == '\n')
					break;
				textFile.seekg(-2, ios_base::cur);
			}
			string lastLine = "";
			getline(textFile, lastLine);
			return getContactIdFromString(lastLine);
		}
	}
}

int ContactFile::getUserIdFromString(string line)
{
	int userIdPosition = line.find_first_of('|') + 1;
	int userId = HelperClass::stringToInt(HelperClass::getNumber(line, userIdPosition));

	return userId;
}

int ContactFile::getContactIdFromString(string line)
{
	int contactIdPosition = 0;
	int contactId = HelperClass::stringToInt(HelperClass::getNumber(line, contactIdPosition));
	return contactId;
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
