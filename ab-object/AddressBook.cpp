#include "stdafx.h"
#include "AddressBook.h"

AddressBook::AddressBook()
{
	loggedUserId = 0;
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



AddressBook::~AddressBook()
{
}