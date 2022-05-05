#pragma once
#include<string>
#include<iostream>
using namespace std;
struct Coordinate {
	int x;
	int y;
};
class Station
{
private:
	string name;
	Coordinate coordinate;
public:
	Station() noexcept;
	Station(string name, int x, int y) noexcept;

	string getName() const noexcept;
	Coordinate getCoordinate() const noexcept;

	void setName(string const name) noexcept;
	void setX(int const x) noexcept;
	void setY(int const y) noexcept;

	friend ostream& operator<<(ostream& os, const Station& s);
	friend istream& operator>>(istream& is, Station& s);
};

