#include "Display.h"
Display::Display() noexcept
{
	this->route = vector<Station>{};
	this->user = User();
}
Display::Display(Route route, User user) noexcept
{
	this->route = route;
	this->user = user;
}

Route Display::getRoute() const noexcept
{
	return route;
}
User Display::getUser() const noexcept
{
	return user;
}
void Display::setRoute(Route const route) noexcept
{
	this->route = route;
}
void Display::setUser(User const user) noexcept
{
	this->user = user;
}