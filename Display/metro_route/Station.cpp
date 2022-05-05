#include "Station.h"
Station::Station() noexcept
{
	name = "unknown";
	coordinate.x = 1;
	coordinate.y = 1;
}
Station::Station(string name, int x, int y) noexcept
{
	this->name = name;
	this->coordinate.x = x;
	this->coordinate.y = y;
}

string Station::getName() const noexcept
{
	return name;
}
Coordinate Station::getCoordinate() const noexcept
{
	return coordinate;
}

void Station::setName(string const name) noexcept
{
	this->name = name;
}
void Station::setX(int const x) noexcept
{
	this->coordinate.x = x;
}
void Station::setY(int const y) noexcept
{
	this->coordinate.y = y;
}
ostream& operator<<(ostream& os, const Station& s)
{
	os << s.getName()<<" "<< s.getCoordinate().x << " " << s.getCoordinate().y;
	return os;
}
istream& operator>>(istream& is, Station& s)
{
	is >> s.name >>s.coordinate.x>>s.coordinate.y;
	return is;
}