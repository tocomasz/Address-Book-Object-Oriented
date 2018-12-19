#include "stdafx.h"

#include "UserFile.h"


UserFile::UserFile()
{
	usersFileName = "Uzytkownicy.txt";
}

vector <User> UserFile::loadUsersFromFile()
{
	vector <User> users;
	string line;
	User user;

	textFile.open(usersFileName.c_str(), ios::in);
	if (textFile.good() == true)
	{
		while (getline(textFile, line))
		{
			user = divideLineWithSeparatorsIntoUserData(line);
			users.push_back(user);
		}
		textFile.close();
	}
	return users;
}


User UserFile::divideLineWithSeparatorsIntoUserData(string lineWithSeparators)
{
	User user;
	string singleData = "";
	int singleDataNumber = 1;

	for (int position = 0; position < lineWithSeparators.length(); position++)
	{
		if (lineWithSeparators[position] != '|')
		{
			singleData += lineWithSeparators[position];
		}
		else
		{

			switch (singleDataNumber)
			{
			case 1:
				user.setId(atoi(singleData.c_str()));
				break;
			case 2:
				user.setLogin(singleData);
				break;
			case 3:
				user.setPassword(singleData);
				break;
			}
			singleData = "";
			singleDataNumber++;
		}
	}
	return user;
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
