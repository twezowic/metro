#include "Display_gui.h"
Display_gui::Display_gui() noexcept
{
	this->route = vector<Station>{};
	this->user = User();
}
Display_gui::Display_gui(Route route, User user) noexcept
{
	this->route = route;
	this->user = user;
}

void Display_gui::menu() noexcept
{
	user.helloWorld();
	cout << "Opens a graphical interface app and shows buttons with options.";
}
void Display_gui::printMap() noexcept
{
	int startX = route[0].getCoordinate().x;
	int startY = route[0].getCoordinate().y;
	for (int i = 1; i < route.getStations().size(); i++)
	{
		int nextX = route[i].getCoordinate().x;
		int nextY = route[i].getCoordinate().y;
		cout << "Draw line from (" << startX << ", " << startY;
		cout << ") to (" << nextX << ", "  << nextY << ")\n";
		startX = nextX;
		startY = nextY;
	}
}