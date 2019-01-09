
#include "ContactManager.h"





ContactManager::ContactManager(string CONTACTSFILENAME, int LOGGEDUSERID)
	: contactFile(CONTACTSFILENAME), loggedUserId(LOGGEDUSERID)
{
	lastContactId = 0;
	contacts = contactFile.loadLoggedUserContactsFromFile(loggedUserId);
	updateLastContactId();
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

int ContactManager::chooseContact()
{
	int chosenContact = 0;
	cout << "Podaj numer ID Adresata: ";
	chosenContact = HelperClass::loadInteger();
	return chosenContact;
}

char ContactManager::contactEditMenu()
{
	char choice;

	cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
	cout << "---------------------------" << endl;
	cout << "Ktore dane zaktualizowac: " << endl;
	cout << "1 - Imie" << endl;
	cout << "2 - Nazwisko" << endl;
	cout << "3 - Numer telefonu" << endl;
	cout << "4 - Email" << endl;
	cout << "5 - Adres" << endl;
	cout << "6 - Powrot " << endl;
	cout << endl << "Twoj wybor: ";
	choice = HelperClass::loadCharacter();

	return choice;
}

void ContactManager::updateLastContactId()
{
	lastContactId = contactFile.getLastContactIdFromFile();
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

void ContactManager::editContact()
{
	system("cls");
	Contact contact;
	int contactId = 0;
	int contacLine = 0;
	string contactData = "";

	cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
	contactId = chooseContact();

	char choice;
	bool isContact = false;

	for (vector <Contact>::iterator itr = contacts.begin(), end = contacts.end(); itr != end; itr++)
	{
		if (itr->getId() == contactId)
		{
			isContact = true;
			choice = contactEditMenu();

			switch (choice)
			{
			case '1':
				cout << "Podaj nowe imie: ";
				itr->setFirstName(HelperClass::convertStringToSentenceCase(HelperClass::loadLine()));
				contactFile.updateContactInFile(*itr);
				break;
			case '2':
				cout << "Podaj nowe nazwisko: ";
				itr->setLastName(HelperClass::convertStringToSentenceCase(HelperClass::loadLine()));
				contactFile.updateContactInFile(*itr);
				break;
			case '3':
				cout << "Podaj nowy numer telefonu: ";
				itr->setTelephoneNumber(HelperClass::loadLine());
				contactFile.updateContactInFile(*itr);
				break;
			case '4':
				cout << "Podaj nowy email: ";
				itr->setEmail(HelperClass::loadLine());
				contactFile.updateContactInFile(*itr);
				break;
			case '5':
				cout << "Podaj nowy adres zamieszkania: ";
				itr->setAddress(HelperClass::loadLine());
				contactFile.updateContactInFile(*itr);
				break;
			case '6':
				cout << endl << "Powrot do menu uzytkownika" << endl << endl;
				break;
			default:
				cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
				break;
			}
		}
	}
	if (isContact == false)
	{
		cout << endl << "Nie ma takiego adresata." << endl << endl;
	}
	system("pause");
}

void ContactManager::deleteContact()
{
	int idToDelete = 0;
	int numerLiniiUsuwanegoAdresata = 0;

	system("cls");
	cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
	idToDelete = chooseContact();

	char ch;
	bool isContact = false;

	for (vector <Contact>::iterator itr = contacts.begin(), end = contacts.end(); itr != end; itr++)
	{
		if (itr->getId() == idToDelete)
		{
			isContact = true;
			cout << endl << "Potwierdz naciskajac klawisz 't': ";
			ch = HelperClass::loadCharacter();
			if (ch == 't')
			{
				contactFile.deleteContactFromFile(*itr);
				updateLastContactId();
				contacts.erase(itr);
			
				cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
				system("pause");
				return;
			}
			else
			{
				cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
				system("pause");
				return;
			}
		}
	}
	if (isContact == false)
	{
		cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
		system("pause");
	}
	return;
}


ContactManager::~ContactManager()
{
}
