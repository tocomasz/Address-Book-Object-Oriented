#include "stdafx.h"

#include "UserFile.h"


UserFile::UserFile()
{
	usersFileName = "Uzytkownicy.txt";
}


bool UserFile::isFileEmpty()
{
	textFile.seekg(0, ios::end);
	if ((int)textFile.tellg() == 0)
		return true;
	else
		return false;
}

string UserFile::addSeparatingLinesToUserData(User user)
{
	string line = "";
	line += HelperClass::intToString(user.getId()) + '|';
	line += user.getLogin() + '|';
	line += user.getPassword() + '|';

	return line;
}

void UserFile::saveUserToFile(User user)
{
	string line = "";
	textFile.open(usersFileName.c_str(), ios::app);

	if (textFile.good() == true)
	{
		line = addSeparatingLinesToUserData(user);

		if (isFileEmpty() == true)
		{
			textFile << line;
		}
		else
		{
			textFile << endl << line;
		}
		textFile.close();
	}
	else
		cout << "Nie udalo sie otworzyc pliku " << usersFileName << " i zapisac w nim danych." << endl;
}

UserFile::~UserFile()
{
}
