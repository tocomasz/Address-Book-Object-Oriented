// ab-object.cpp : Defines the entry point for the console application.
//

#include "AddressBook.h"

using namespace std;

int main()
{
	AddressBook ab;
	ab.logUserIn();
	ab.loadContacts();
	ab.addContact();
	ab.addContact();

	ab.printAllContacts();
    return 0;
}

