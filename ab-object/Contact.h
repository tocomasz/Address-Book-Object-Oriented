#pragma once
#include <iostream>
using namespace std;

class Contact
{
	int id, userId;
	string firstName, lastName, telephoneNumber, email, address;
public:
	Contact();


	int getId();
	int getUserId();
	string getFirstName();
	string getLastName();
	string getTelephoneNumber();
	string getEmail();
	string getAddress();

	void setId(int);
	void setUserId(int);
	void setFirstName(string);
	void setLastName(string);
	void setTelephoneNumber(string);
	void setEmail(string);
	void setAddress(string);


	~Contact();
};

