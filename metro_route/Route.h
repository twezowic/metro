#pragma once
#include<vector>
#include"Station.h"
class Route
{
private:
	vector<Station> stations;
public:
	Route() noexcept;
	Route(vector<Station> stations) noexcept;

	vector<Station> getStations() const noexcept;
	vector<Coordinate> getCoordinates() const noexcept;

	void setStations(vector<Station> const stations) noexcept;

	void operator+=(Station const& station) noexcept;
	void operator-=(string const& name) noexcept;

	Station operator[](int i) const noexcept;

	friend ostream& operator<<(ostream& os, const Route& r);
	friend istream& operator>>(istream& is, Route& r);
};

void readFromFile(string filename, Route& r) noexcept;
void saveToFile(string filename, Route& r) noexcept;