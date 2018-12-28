
#include "UserManager.h"


UserManager::UserManager() : userFile("Uzytkownicy.txt")
{
	users = userFile.loadUsersFromFile();
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
void UserManager::printAllUsers()
{
	for (vector <User>::iterator itr = users.begin(), end = users.end(); itr != end; itr++)
	{
		cout << itr->getId() << endl;
		cout << itr->getLogin() << endl;
		cout << itr->getPassword() << endl;
	}
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
	string login = "", password = "";

	cout << endl << "Podaj login: ";
	cin >> login;

	vector <User>::iterator itr = users.begin(), end = users.end();
	while (itr != end)
	{
		if (itr->getLogin() == login)
		{
			for (int iloscProb = 3; iloscProb > 0; iloscProb--)
			{
				cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
				cin >> password;

				if (itr->getPassword() == password)
				{
					cout << endl << "Zalogowales sie." << endl << endl;
					system("pause");
					return itr->getId();
				}
			}
			cout << "Wprowadzono 3 razy bledne haslo." << endl;
			system("pause");
			return 0;
		}
		itr++;
	}
	cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
	system("pause");
	return 0;
}

void UserManager::changeUserPassword(int loggedUserId)
{
	if (loggedUserId == 0)
		return;
	string newPassword = "";
	cout << "Podaj nowe haslo: ";
	cin >> newPassword;

	for (vector <User>::iterator itr = users.begin(), end = users.end(); itr != end; itr++)
	{
		if (itr->getId() == loggedUserId)
		{
			itr->setPassword(newPassword);
			cout << "Haslo zostalo zmienione." << endl << endl;
			userFile.updateUserInFile(*itr);
			system("pause");
		}
	}

}

int UserManager::logUserOut()
{
	return 0;
}


UserManager::~UserManager()
{
}
