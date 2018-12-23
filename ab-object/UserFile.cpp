#include "stdafx.h"

#include "UserFile.h"


vector <User> UserFile::loadUsersFromFile()
{
	vector <User> users;
	string line;
	User user;
	fstream textFile;
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
	fstream textFile;
	textFile.open(usersFileName.c_str(), ios::app);

	if (textFile.good() == true)
	{
		line = addSeparatingLinesToUserData(user);
		
		if (HelperClass::isFileEmpty(usersFileName) == true)
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

void UserFile::updateUserInFile(User user)
{
	fstream textFile, temp;
	textFile.open(usersFileName.c_str(), ios::in);
	temp.open("temp.txt", ios::out);
	if (textFile.good() && temp.good())
	{
		string loadedLine;
		while (getline(textFile, loadedLine))
		{
			if (loadedLine[0] - '0' == user.getId())
			{
				temp << user.getId() << "|";
				temp << user.getLogin() << "|";
				temp << user.getPassword() << "|" << endl;
				continue;
			}
			temp << loadedLine << endl;
		}
	}
	textFile.close();
	textFile.clear();
	temp.close();
	temp.clear();
	remove(usersFileName.c_str());
	rename("temp.txt", usersFileName.c_str());
}


UserFile::~UserFile()
{
}
