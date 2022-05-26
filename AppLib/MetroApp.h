#pragma once
#include "../CoordinatorLib/CoordinatorLib.h"
#include "../conections/conection.h"

string line(int x1, int y1, int x2, int y2)
{
	return "<line x1=" + to_string(x1) + " y1=" + to_string(y1) + " x2=" + to_string(x2) + " y2=" + to_string(y2) + "style = \"stroke:rgb(0, 0, 0); \"stroke - width:2\" />";
}

class MetroApp
{
private:
	Coordinator metro_coor;
	std::vector<Train> train_vec; // since coordinator doesn't have this, metro probably should to ensure they don't get deleted
	std::vector<conection> connect_vec; // same as with trains

public:
	time simulation_time;

	MetroApp();
	void setTrains(vector<Train> trains);
	void setConnections(vector<conection> connections);
	bool hasPeople();
	time run();
	void readStationscsv();
	void readConnectionscsv();
	void readTrainscsv();
	void readData();


	void create_svg();
	void start();
};