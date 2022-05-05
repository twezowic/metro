#pragma once
#include<string>
using namespace std;
class User_admin;
struct Human {
	string first_name;
	string last_name;
};
class User
{
	friend User_admin;
protected:
	string password;
	Human human;
	string username;
	string mail;
public:
	User() noexcept;
	User(string first_name, string last_name, string username, string password, string mail) noexcept;

	string getFirstName() const noexcept;
	string getLastName() const noexcept;
	string getUsername() const noexcept;
	string getMail() const noexcept;
	
	void setFirstName(string const firstname) noexcept;
	void setLastName(string const lastname) noexcept;
	void setUsername(string const username) noexcept;
	void setPassword(string const password) noexcept;
	void setMail(string const password) noexcept;

	virtual void helloWorld() noexcept;
};

