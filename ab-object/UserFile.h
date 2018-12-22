#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "User.h"
#include "HelperClass.h"
using namespace std;

class UserFile
{
	const string usersFileName;


	bool isFileEmpty();
	string addSeparatingLinesToUserData(User);
	User divideLineWithSeparatorsIntoUserData(string);


public:
	UserFile(string USERFILENAME) : usersFileName(USERFILENAME) {};
	void saveUserToFile(User);
	vector <User> loadUsersFromFile();;
	void updateUserInFile(User);

	~UserFile();
};

