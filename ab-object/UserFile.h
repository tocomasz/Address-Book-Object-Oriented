#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "User.h"
#include "HelperClass.h"
using namespace std;

class UserFile
{
	string usersFileName;
	fstream textFile;

	bool isFileEmpty();
	string addSeparatingLinesToUserData(User);
	User divideLineWithSeparatorsIntoUserData(string);

public:
	UserFile();
	void saveUserToFile(User);
	vector <User> loadUsersFromFile();;

	~UserFile();
};

