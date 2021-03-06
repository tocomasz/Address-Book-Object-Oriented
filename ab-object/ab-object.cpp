// ab-object.cpp : Defines the entry point for the console application.
//

#include "AddressBook.h"


using namespace std;

char mainMenu()
{
	char ch;

	system("cls");
	cout << "    >>> MENU  GLOWNE <<<" << endl;
	cout << "---------------------------" << endl;
	cout << "1. Rejestracja" << endl;
	cout << "2. Logowanie" << endl;
	cout << "9. Koniec programu" << endl;
	cout << "---------------------------" << endl;
	cout << "Twoj wybor: ";
	ch = HelperClass::loadCharacter();

	return ch;
}

char userMenu()
{
	char ch;

	system("cls");
	cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
	cout << "---------------------------" << endl;
	cout << "1. Dodaj adresata" << endl;
	cout << "2. Wyszukaj po imieniu" << endl;
	cout << "3. Wyszukaj po nazwisku" << endl;
	cout << "4. Wyswietl adresatow" << endl;
	cout << "5. Usun adresata" << endl;
	cout << "6. Edytuj adresata" << endl;
	cout << "---------------------------" << endl;
	cout << "7. Zmien haslo" << endl;
	cout << "8. Wyloguj sie" << endl;
	cout << "---------------------------" << endl;
	cout << "Twoj wybor: ";
	ch = HelperClass::loadCharacter();

	return ch;
}

int main()
{
	AddressBook ab("Uzytkownicy.txt", "Adresaci.txt");
	char choice;
	while (true)
	{
		if (ab.getLoggedUserId() == 0)
		{
			choice = mainMenu();
			switch (choice)
			{
			case '1':
				ab.registerUser();
				break;
			case '2':
				ab.logUserIn();
				break;
			case '9':
				exit(0);
				break;
			default:
				cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
				HelperClass::pauseProgram;
				break;
			}
		}
		else
		{
			choice = userMenu();
			switch (choice)
			{
			case '1':
				ab.addContact();
				break;
			case '2':
				ab.findContactsByFirstName();
				break;
			case '3':
				ab.findContactsByLastName();
				break;
			case '4':
				ab.printAllContacts();
				break;
			case '5':
				ab.deleteContact();
				break;
			case '6':
				ab.editContact();
				break;
			case '7':
				ab.changeUserPassword();
				break;
			case '8':
				ab.logUserOut();
				break;
			}
		}

	}

    return 0;
}

