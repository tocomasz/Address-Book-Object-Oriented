
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
	if (userManager.isUserLoggedIn())
		contactManager->addNewContact();
}


void AddressBook::printAllContacts()
{
	if (userManager.isUserLoggedIn())
		contactManager->printAllContacts();
}

void AddressBook::findContactsByFirstName()
{
	if (userManager.isUserLoggedIn())
		contactManager->findContactsByFirstName();
}

void AddressBook::findContactsByLastName()
{
	if (userManager.isUserLoggedIn())
		contactManager->findContactsByLastName();
}

AddressBook::~AddressBook()
{
	delete contactManager;
	contactManager = NULL;
}