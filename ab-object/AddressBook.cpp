
#include "AddressBook.h"

AddressBook::AddressBook(string USERSFILENAME, string CONTACTSFILENAME)
	: userManager(USERSFILENAME), CONTACTS_FILE_NAME(CONTACTSFILENAME)
{
	contactManager = NULL;
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
	contactManager->addNewContact();
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