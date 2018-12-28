
#include "Contact.h"


Contact::Contact()
{
}


int Contact::getId()
{
	return id;
}
int Contact::getUserId()
{
	return userId;
}
string Contact::getFirstName()
{
	return firstName;
}
string Contact::getLastName()
{
	return lastName;
}
string Contact::getTelephoneNumber()
{
	return telephoneNumber;
}
string Contact::getEmail()
{
	return email;
}
string Contact::getAddress()
{
	return address;
}

void Contact::setId(int newId)
{
	if (newId >= 0)
		id = newId;
}
void Contact::setUserId(int newId)
{
	if (newId >= 0)
		userId = newId;
}
void Contact::setFirstName(string newFirstName)
{
	firstName = newFirstName;
}
void Contact::setLastName(string newLastName)
{
	lastName = newLastName;
}
void Contact::setTelephoneNumber(string newTelephoneNumber)
{
	telephoneNumber = newTelephoneNumber;
}
void Contact::setEmail(string newEmail)
{
	email = newEmail;
}
void Contact::setAddress(string newAddress)
{
	address = newAddress;
}

Contact::~Contact()
{
}
