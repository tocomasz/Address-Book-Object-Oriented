#pragma once
#include <fstream>
#include <string>
#include "User.h"
#include "HelperClass.h"
using namespace std;

class UserFile
{
	string usersFileName;
	fstream textFile;

	bool isFileEmpty();
	string addSeparatingLinesToUserData(User);

public:
	UserFile();
	void saveUserToFile(User);
	~UserFile();
};

