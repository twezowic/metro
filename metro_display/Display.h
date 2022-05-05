#pragma once
#include<iostream>
#include<string>
#include"../metro_route/Route.h"
#include"../metro_route/Station.h"
#include"../metro_user/User_admin.h"
using namespace std;
class Display
{
protected:
	Route route;
	User user;
public:
	Display() noexcept;
	Display(Route route, User user) noexcept;

	Route getRoute() const noexcept;
	User getUser() const noexcept;

	void setRoute(Route const route) noexcept;
	void setUser(User const user) noexcept;

	virtual void printMap() = 0;
	virtual void menu() = 0;
};

