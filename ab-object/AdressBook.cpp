#include "stdafx.h"
#include "AdressBook.h"

AdressBook::AdressBook()
{
}

void AdressBook::registerUser()
{
	User user = provideNewUserLoginCredentials();

	users.push_back(user);
	//dopiszUzytkownikaDoPliku(user);

	cout << endl << "Konto zalozono pomyslnie" << endl << endl;
	system("pause");
}

User AdressBook::provideNewUserLoginCredentials()
{
	User user;
	user.setUserId(newUserId());

	string login;
	do
	{
		cout << "Podaj login: ";
		cin >> login;
		user.setUserLogin(login);
	} while (isLoginTaken(user.getUserLogin()) == true);

	cout << "Podaj haslo: ";
	string password;
	cin >> password;
	user.setUserPassword(password);

	return user;
}

int AdressBook::newUserId()
{
	if (users.empty() == true)
		return 1;
	else
		return users.back().getUserId() + 1;
}

bool AdressBook::isLoginTaken(string login)
{
	for (vector <User>::iterator itr = users.begin(), end = users.end(); itr != end; itr++)
	{
		if (itr->getUserLogin() == login)
		{
			cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
			return true;
		}
	}
	return false;
}

void AdressBook::printAllUsers()
{
	for (vector <User>::iterator itr = users.begin(), end = users.end(); itr != end; itr++)
	{
		cout << itr->getUserId() << endl;
		cout << itr->getUserLogin() << endl;
		cout << itr->getUserPassword() << endl;
	}
}

AdressBook::~AdressBook()
{
}