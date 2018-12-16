#pragma once
#include <iostream>
#include "User.h"
#include <vector>

using namespace std;

class AdressBook
{
	int idOfLastLoggedUser;
	int idOfLastContact;
	int idOfDeletedUser;


public:
	void registerUser(User);
	AdressBook();
	~AdressBook();
};

