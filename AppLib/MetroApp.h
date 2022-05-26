#pragma once
#include "../CoordinatorLib/CoordinatorLib.h"
#include "../station/station.h"
#include "../conections/conection.h"

string line(int x1, int y1, int x2, int y2)
{
	return "<line x1=" + to_string(x1) + " y1=" + to_string(y1) + " x2=" + to_string(x2) + " y2=" + to_string(y2) + "style = \"stroke:rgb(0, 0, 0); \"stroke - width:2\" />";
}

class MetroApp
{
private:
	Coordinator metro_coor;
	std::vector<std::pair<Train, Train>> trains_pairs; // since coordinator doesn't have this, metro probably should to ensure they don't get deleted
	std::vector<conection> connect_vec; // same as with trains

public:
	min_time simulation_time;

	MetroApp();
	void setTrains(vector<std::pair<Train, Train>> trains);
	void setConnections(vector<conection> connections);
	bool hasPeople();
	min_time run();
	void readStationscsv();
	void readConnectionscsv();
	void readTrainscsv();
	void readData();


	void create_svg();
	void start();
	Station* getStation(int id);
};