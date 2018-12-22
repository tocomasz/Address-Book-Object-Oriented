#pragma once
#include "Contact.h"
#include "ContactFile.h"
#include <vector>
#include <iostream>	

using namespace std;

class ContactManager
{
	vector <Contact> contacts;
	ContactFile contactFile;


public:
	ContactManager();
	~ContactManager();
};

