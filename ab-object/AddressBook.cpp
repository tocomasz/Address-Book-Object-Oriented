#include "stdafx.h"
#include "AddressBook.h"

AddressBook::AddressBook()
{
	usersFileName = "Uzytkownicy.txt";

}

void AddressBook::registerUser()
{
	User user = provideNewUserLoginCredentials();

	users.push_back(user);
	saveUserToFile(user);

	cout << endl << "Konto zalozono pomyslnie" << endl << endl;
	system("pause");
}

User AddressBook::provideNewUserLoginCredentials()
{
	User user;
	user.setId(newUserId());

	string login;
	do
	{
		cout << "Podaj login: ";
		cin >> login;
		user.setLogin(login);
	} while (isLoginTaken(user.getLogin()) == true);

	cout << "Podaj haslo: ";
	string password;
	cin >> password;
	user.setPassword(password);

	return user;
}

int AddressBook::newUserId()
{
	if (users.empty() == true)
		return 1;
	else
		return users.back().getId() + 1;
}

bool AddressBook::isLoginTaken(string login)
{
	for (vector <User>::iterator itr = users.begin(), end = users.end(); itr != end; itr++)
	{
		if (itr->getLogin() == login)
		{
			cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
			return true;
		}
	}
	return false;
}

void AddressBook::saveUserToFile(User user)
{
	fstream textFile;
	string line = "";
	textFile.open(usersFileName.c_str(), ios::app);

	if (textFile.good() == true)
	{
		line = addSeparatingLinesToUserData(user);

		if (isFileEmpty(textFile) == true)
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

string AddressBook::addSeparatingLinesToUserData(User user)
{
	string line = "";

	line += intToString(user.getId()) + '|';
	line += user.getLogin() + '|';
	line += user.getPassword() + '|';

	return line;
}

string AddressBook::intToString(int number)
{
	ostringstream ss;
	ss << number;
	string str = ss.str();
	return str;
}

bool AddressBook::isFileEmpty(fstream &textFile)
{
	textFile.seekg(0, ios::end);
	if ((int)textFile.tellg() == 0)
		return true;
	else
		return false;
}

void AddressBook::printAllUsers()
{
	for (vector <User>::iterator itr = users.begin(), end = users.end(); itr != end; itr++)
	{
		cout << itr->getId() << endl;
		cout << itr->getLogin() << endl;
		cout << itr->getPassword() << endl;
	}
}

AddressBook::~AddressBook()
{
}