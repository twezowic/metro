#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"../metro_route/Route.h"
#include"../metro_route/Station.h"
#include"../metro_user/User_admin.h"
using namespace std;
class Display_gui
{
protected:
	User user;
public:
	Display_gui() noexcept;
	Display_gui(User user) noexcept;

	User getUser() const noexcept;

	void setUser(User const user) noexcept;

	virtual void printMap(Route route) noexcept;
	virtual void printStation(Station station) noexcept;
	virtual void printRoute(Route route) noexcept;
	virtual void printUser(User user) noexcept;
	virtual void printSchedule(string filename) noexcept;
	virtual void printMenu() noexcept;
};

