#include "stdafx.h"
#include "UserManager.h"


UserManager::UserManager()
{
}


int UserManager::newUserId()
{
	if (users.empty() == true)
		return 1;
	else
		return users.back().getId() + 1;
}
bool UserManager::isLoginTaken(string login)
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



User UserManager::provideNewUserLoginCredentials()
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
void UserManager::registerUser()
{
	User user = provideNewUserLoginCredentials();

	users.push_back(user);
	userFile.saveUserToFile(user);

	cout << endl << "Konto zalozono pomyslnie" << endl << endl;
	system("pause");
}
int UserManager::logUserIn()
{
	return 0;
}


UserManager::~UserManager()
{
}
