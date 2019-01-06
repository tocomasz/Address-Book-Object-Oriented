
#include "AddressBook.h"

AddressBook::AddressBook(string usersFileName, string contactsFileName)
	: userManager(usersFileName), CONTACTS_FILE_NAME(contactsFileName)
{
	contactManager = NULL;
	lastContactId = 0;
}

void AddressBook::registerUser()
{
	userManager.registerUser();
}

void AddressBook::printAllUsers()
{
	userManager.printAllUsers();
}

void AddressBook::logUserIn()
{
	userManager.logUserIn();
	if (userManager.isUserLoggedIn())
	{
		contactManager = new ContactManager(CONTACTS_FILE_NAME, userManager.getLoggedUserId());
	}
}
void AddressBook::changeUserPassword()
{
	userManager.changeUserPassword();
}

void AddressBook::logUserOut()
{
	userManager.logUserOut();
}

void AddressBook::addContact()
{
	lastContactId = contactManager->addNewContact(lastContactId);
}

void AddressBook::loadContacts()
{
	contactManager->loadLoggedUserContacts(lastContactId);
}

void AddressBook::printAllContacts()
{
	contactManager->printAllContacts();
}

AddressBook::~AddressBook()
{
	delete contactManager;
	contactManager = NULL;
}