#pragma once
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <cctype>

using namespace std;
class HelperClass
{
public:
	HelperClass();

	static string intToString(int);
	static int stringToInt(string);
	static string loadLine();
	static string convertStringToSentenceCase(string);
	static bool isFileEmpty(string);
	static string getNumber(string, int);
	

	~HelperClass();
};

