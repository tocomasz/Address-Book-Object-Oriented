// ab-object.cpp : Defines the entry point for the console application.
//

#include "AddressBook.h"

using namespace std;

int main()
{
	AddressBook ab("Uzytkownicy.txt", "Adresaci.txt");

	ab.logUserIn();
	ab.addContact();
	ab.addContact();

	ab.printAllContacts();
    return 0;
}

