// ab-object.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AddressBook.h"

using namespace std;

int main()
{
	AddressBook ab;
	ab.printAllUsers();
	ab.logUserIn();
	ab.changeUserPassword();
    return 0;
}

