#include "stdafx.h"
#include "User.h"


User::User()
{
}

int User::getUserId()
{
	return id;
}
string User::getUserLogin()
{
	return login;
}
string User::getUserPassword()
{
	return password;
}

void User::setUserId(int newId)
{
	if (newId >= 0)
		id = newId;
}

void User::setUserLogin(string newLogin)
{
	login = newLogin;
}
void User::setUserPassword(string newPassword)
{
	password = newPassword;
}


User::~User()
{
}
