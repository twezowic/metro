#pragma once
#include <iostream>
#include "User.h"
using namespace std;
class User_admin :
    public User
{
public:
	User_admin() noexcept;
	User_admin(string first_name, string last_name, string username, string password, string mail) noexcept;


	string getPassword() const noexcept;
	string getPassword(const User& user) const noexcept;

	void helloWorld() noexcept;
};

