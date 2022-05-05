#include<iostream>
#include "User.h"
using namespace std;
User::User() noexcept
{
	this->human.first_name = "unknown";
	this->human.last_name = "unknown";
	this->username = "user";
	this->password = "user";
	this->mail = "unknown";
}
User::User(string first_name, string last_name, string username, string password, string mail) noexcept
{
	this->human.first_name = first_name;
	this->human.last_name = last_name;
	this->username = username;
	this->password = password;
	this->mail = mail;
}

string User::getFirstName() const noexcept
{
	return human.first_name;
}
string User::getLastName() const noexcept
{
	return human.last_name;
}
string User::getUsername() const noexcept
{
	return username;
}
string User::getMail() const noexcept
{
	return mail;
}

void User::setFirstName(string const firstname) noexcept
{
	this->human.first_name = firstname;
}
void User::setLastName(string const lastname) noexcept
{
	this->human.last_name = lastname;
}
void User::setUsername(string const username) noexcept
{
	this->username = username;
}
void User::setMail(string const mail) noexcept
{
	this->mail = mail;
}
void User::setPassword(string const password) noexcept
{
	this->password = password;
}
void User::helloWorld() noexcept
{
	cout << "Hello user: " << username << endl;
}