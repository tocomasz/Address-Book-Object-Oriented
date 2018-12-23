#include "stdafx.h"
#include "AddressBook.h"

AddressBook::AddressBook()
{
	loggedUserId = 0;
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
	loggedUserId = userManager.logUserIn();
}
void AddressBook::changeUserPassword()
{
	userManager.changeUserPassword(loggedUserId);
}

void AddressBook::logUserOut()
{
	loggedUserId = userManager.logUserOut();
}

void AddressBook::addContact()
{
	lastContactId = contactManager.addNewContact(loggedUserId, lastContactId);
}

void AddressBook::loadContacts()
{
	contactManager.loadLoggedUserContacts(loggedUserId, lastContactId);
}

void AddressBook::printAllContacts()
{
	contactManager.printAllContacts();
}

AddressBook::~AddressBook()
{
}