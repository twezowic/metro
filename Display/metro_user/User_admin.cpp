#include "User_admin.h"
User_admin::User_admin() noexcept
{
	this->human.first_name = "unknown";
	this->human.last_name = "unknown";
	this->username = "admin";
	this->password = "admin";
	this->mail = "unknown";
}
User_admin::User_admin(string first_name, string last_name, string username, string password, string mail) noexcept
{
	this->human.first_name = first_name;
	this->human.last_name = last_name;
	this->username = username;
	this->password = password;
	this->mail = mail;
}

string User_admin::getPassword() const noexcept
{
	return User::password;
}
string User_admin::getPassword(const User& user) const noexcept
{
	return user.password;
}
void User_admin::helloWorld() noexcept
{
	cout << "Hello admin " << username << endl;
}