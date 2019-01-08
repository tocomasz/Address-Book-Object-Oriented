
#include "ContactManager.h"





ContactManager::ContactManager(string CONTACTSFILENAME, int LOGGEDUSERID)
	: contactFile(CONTACTSFILENAME), loggedUserId(LOGGEDUSERID)
{
	lastContactId = 0;
	contacts = contactFile.loadLoggedUserContactsFromFile(loggedUserId, lastContactId);
}

void ContactManager::printContact(Contact contact)
{
	cout << endl << "Id:                 " << contact.getId() << endl;
	cout << "Imie:               " << contact.getFirstName() << endl;
	cout << "Nazwisko:           " << contact.getLastName() << endl;
	cout << "Numer telefonu:     " << contact.getTelephoneNumber() << endl;
	cout << "Email:              " << contact.getEmail() << endl;
	cout << "Adres:              " << contact.getAddress() << endl;
}

void ContactManager::printNumberOfContactsFound(int contactsCount)
{
	if (contactsCount == 0)
		cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
	else
		cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << contactsCount << endl << endl;
}

void ContactManager::addNewContact()
{
	Contact contact;

	system("cls");
	cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
	contact = inputNewContactData();

	contacts.push_back(contact);
	contactFile.addContactToFile(contact);
}

Contact ContactManager::inputNewContactData()
{
	Contact contact;

	contact.setId(++lastContactId);
	contact.setUserId(loggedUserId);

	cout << "Podaj imie: ";
	string newFirstName = HelperClass::loadLine();
	newFirstName = HelperClass::convertStringToSentenceCase(newFirstName);
	contact.setFirstName(newFirstName);

	cout << "Podaj nazwisko: ";
	string newLastName = HelperClass::loadLine();
	newLastName = HelperClass::convertStringToSentenceCase(newLastName);
	contact.setLastName(newLastName);

	cout << "Podaj numer telefonu: ";
	contact.setTelephoneNumber(HelperClass::loadLine());

	cout << "Podaj email: ";
	contact.setEmail(HelperClass::loadLine());

	cout << "Podaj adres: ";
	contact.setAddress(HelperClass::loadLine());

	return contact;
}


void ContactManager::printAllContacts()
{
	for (vector <Contact>::iterator itr = contacts.begin(), end = contacts.end(); itr != end; itr++)
	{
		system("cls");
		if (!contacts.empty())
		{
			cout << "             >>> ADRESACI <<<" << endl;
			cout << "-----------------------------------------------" << endl;
			for (vector <Contact> ::iterator itr = contacts.begin(), end = contacts.end(); itr != end; itr++)
			{
				printContact(*itr);
			}
			cout << endl;
		}
		else
		{
			cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
		}
		system("pause");
	}
}

void ContactManager::findContactsByFirstName()
{
	string contactFirstName = "";
	int contactsCount = 0;

	system("cls");
	if (!contacts.empty())
	{
		cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

		cout << "Wyszukaj adresatow o imieniu: ";
		contactFirstName = HelperClass::loadLine();
		contactFirstName = HelperClass::convertStringToSentenceCase(contactFirstName);

		for (vector <Contact>::iterator itr = contacts.begin(), end = contacts.end(); itr != end; itr++)
		{
			if (itr->getFirstName() == contactFirstName)
			{
				printContact(*itr);
				contactsCount++;
			}
		}
		printNumberOfContactsFound(contactsCount);
	}
	else
	{
		cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
	}
	cout << endl;
	system("pause");
}

void ContactManager::findContactsByLastName()
{
	string contactLastName = "";
	int contactsCount = 0;

	system("cls");
	if (!contacts.empty())
	{
		cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

		cout << "Wyszukaj adresatow o nazwisku: ";
		contactLastName = HelperClass::loadLine();
		contactLastName = HelperClass::convertStringToSentenceCase(contactLastName);

		for (vector <Contact>::iterator itr = contacts.begin(), end = contacts.end(); itr != end; itr++)
		{
			if (itr->getLastName() == contactLastName)
			{
				printContact(*itr);
				contactsCount++;
			}
		}
		printNumberOfContactsFound(contactsCount);
	}
	else
	{
		cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
	}
	cout << endl;
	system("pause");
}


ContactManager::~ContactManager()
{
}
