#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "Contact.h"
class ContactFile
{
	const string contactsFileName;
public:
	ContactFile(string CONTACTFILENAME) : contactsFileName(CONTACTFILENAME) {};
	~ContactFile();
};

