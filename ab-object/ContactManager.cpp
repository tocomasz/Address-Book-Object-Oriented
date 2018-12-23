#include "stdafx.h"
#include "ContactManager.h"



ContactManager::ContactManager() : contactFile("Adresaci.txt")
{

}

int ContactManager::addNewContact(int loggedUserId , int lastContactId)
{
	Contact contact;

	system("cls");
	cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
	contact = inputNewContactData(loggedUserId, lastContactId);

	contacts.push_back(contact);
	contactFile.addContactToFile(contact);

	return ++lastContactId;
}

Contact ContactManager::inputNewContactData(int loggedUserId, int lastContactId)
{
	Contact contact;

	contact.setId(++lastContactId);
	contact.setUserId(loggedUserId);

	cout << "Podaj imie: ";
	string newFirstName = HelperClass::loadLine();
	newFirstName = HelperClass::convertStringToSenteceCase(newFirstName);
	contact.setFirstName(newFirstName);

	cout << "Podaj nazwisko: ";
	string newLastName = HelperClass::loadLine();
	newLastName = HelperClass::convertStringToSenteceCase(newLastName);
	contact.setLastName(newLastName);

	cout << "Podaj numer telefonu: ";
	contact.setTelephoneNumber(HelperClass::loadLine());

	cout << "Podaj email: ";
	contact.setEmail(HelperClass::loadLine());

	cout << "Podaj adres: ";
	contact.setAddress(HelperClass::loadLine());

	return contact;
}

void ContactManager::loadLoggedUserContacts(int loggedUserId, int &lastContactId)
{
	contacts = contactFile.loadLoggedUserContactsFromFile(loggedUserId, lastContactId );
	
}


void ContactManager::printAllContacts()
{
	for (vector <Contact>::iterator itr = contacts.begin(), end = contacts.end(); itr != end; itr++)
	{
		cout << itr->getId() << endl;
		cout << itr->getFirstName() << endl;
		cout << itr->getLastName() << endl;
		cout << itr->getTelephoneNumber() << endl;
		cout << itr->getEmail() << endl;
		cout << itr->getAddress() << endl;
	}
}


ContactManager::~ContactManager()
{
}
