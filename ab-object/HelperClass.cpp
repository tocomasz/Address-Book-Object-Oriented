#include "stdafx.h"
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


HelperClass::~HelperClass()
{
}
