#include <fstream>s
#include "Route.h"
Route::Route() noexcept
{
	stations = {};
}
Route::Route(vector<Station> stations) noexcept
{
	this->stations = stations;
}

vector<Station> Route::getStations() const noexcept
{
	return stations;
}
vector<Coordinate> Route::getCoordinates() const noexcept
{
	vector<Coordinate> col;
	for (int i = 0; i < stations.size(); i++) {
		col.push_back(stations[i].getCoordinate());
	}
	return col;
}

void Route::setStations(vector<Station> const stations) noexcept
{
	this->stations = stations;
}
void Route::operator+=(Station const& station) noexcept
{
	stations.push_back(station);
}
void Route::operator-=(string const& name) noexcept
{
	for (int i = 0; i < stations.size(); i++)
	{
		if (stations[i].getName() == name)
		{
			stations.erase(stations.begin() + i);
			break;
		}
	}
}
Station Route::operator[](int i) const noexcept
{
	return stations[i];
}


ostream& operator<<(ostream& os, const Route& r)
{
	for (int i = 0; i < r.getStations().size(); i++) {
		os << r[i];
		if (i != r.getStations().size() - 1) {
			os << endl;
		}
	}
	return os;
}
istream& operator>>(istream& is, Route& r)
{
	Station station;
	vector<Station> col;
	while (!is.eof()) {

		is >> station;
		col.push_back(station);
	}
	r.setStations(col);
	return is;
}

void readFromFile(string filename, Route& r) noexcept
{
	ifstream file(filename);
	file >> r;
}
void saveToFile(string filename, Route& r) noexcept
{
	ofstream file(filename);
	file << r;
}