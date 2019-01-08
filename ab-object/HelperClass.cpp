
#include "HelperClass.h"


HelperClass::HelperClass()
{
}

string HelperClass::intToString(int number)
{
	ostringstream ss;
	ss << number;
	string str = ss.str();
	return str;
}


int HelperClass::stringToInt(string number)
{
	int intNumber;
	istringstream iss(number);
	iss >> intNumber;

	return intNumber;
}

string HelperClass::loadLine()
{
	cin >> ws;
	string input = "";
	getline(cin, input);
	return input;
}

string HelperClass::convertStringToSentenceCase(string input)
{
	if (!input.empty())
	{
		transform(input.begin(), input.end(), input.begin(), ::tolower);
		input[0] = toupper(input[0]);
	}
	return input;
}

bool HelperClass::isFileEmpty(string fileName)
{
	fstream textFile;
	textFile.open(fileName.c_str(), ios::in);
	textFile.seekg(0, ios::end);
	if ((int)textFile.tellg() == 0)
		return true;
	else
		return false;
}
string HelperClass::getNumber(string text, int position)
{
	string number = "";
	while (isdigit(text[position]))
	{
		number += text[position];
		position++;
	}
	return number;
}

int HelperClass::loadInteger()
{
	string input = "";
	int number = 0;

	while (true)
	{
		cin.ignore();
		getline(cin, input);

		stringstream myStream(input);
		if (myStream >> number)
			break;
		cout << "To nie jest liczba. Wpisz ponownie. " << endl;
	}
	return number;
}

char HelperClass::loadCharacter()
{
	string input = "";
	char ch = { 0 };

	while (true)
	{
		getline(cin, input);

		if (input.length() == 1)
		{
			ch = input[0];
			break;
		}
		cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
	}
	return ch;
}


HelperClass::~HelperClass()
{
}
