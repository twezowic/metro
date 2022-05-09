#include "Display_gui.h"

Display_gui::Display_gui() noexcept
{
	this->user = User();
}
Display_gui::Display_gui(User user) noexcept
{
	this->user = user;
}
User Display_gui::getUser() const noexcept
{
	return user;
}
void Display_gui::setUser(User const user) noexcept
{
	this->user = user;
}

void Display_gui::printMap(Route route) noexcept
{
	int startX = route[0].getCoordinate().x;
	int startY = route[0].getCoordinate().y;
	for (int i = 1; i < route.getStations().size(); i++)
	{
		int nextX = route[i].getCoordinate().x;
		int nextY = route[i].getCoordinate().y;
		cout << "Draw line from (" << startX << ", " << startY;
		cout << ") to (" << nextX << ", " << nextY << ")\n";
		startX = nextX;
		startY = nextY;
	}

}
void Display_gui::printStation(Station station) noexcept
{
	cout << "Print a basic information about station " << endl;
}
void Display_gui::printRoute(Route route) noexcept
{
	cout << "Print array with station informations in seperate rows." << endl;
	cout << "Mark with a colour first and last station";
}
void Display_gui::printUser(User user) noexcept
{
	cout << "Print a basic information about current user." << endl;
}
void Display_gui::printSchedule(string filename) noexcept
{
	cout << "Print a schedule from given file with: " << endl;
	cout << "- name of the line and name of current station" << endl;
	cout << "- route of the line" << endl;
	cout << "- schedule with seperate row for each hour" << endl;
}
void Display_gui::printMenu() noexcept
{
	cout << "Make buttons with options what to do: " << endl;
	cout << "Show routes"<<endl;
	cout << "Show schedules" << endl;
	cout << "Modify route (user_admin required)" << endl;
	cout << "Check fullness of trains and stations (user_admin required)" << endl;
}