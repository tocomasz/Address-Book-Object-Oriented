#include "stdafx.h"
#include "AddressBook.h"

AddressBook::AddressBook()
{
	
}

void AddressBook::registerUser()
{
	userManager.registerUser();
}

void AddressBook::printAllUsers()
{
	userManager.printAllUsers();
}



AddressBook::~AddressBook()
{
}