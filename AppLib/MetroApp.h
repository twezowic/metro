#pragma once
#include "../CoordinatorLib/CoordinatorLib.h"
#include "../conections/conection.h"
class Station;
class MetroApp
{
	typedef int time2;
private:
	Coordinator metro_coor;
	std::vector<Train> train_vec; // since coordinator doesn't have this, metro probably should to ensure they don't get deleted
	std::vector<conection> connect_vec; // same as with trains

public:
	time2 simulation_time;

	MetroApp();
	void setTrains(vector<Train> trains);
	void setConnections(vector<conection> connections);
	bool hasPeople();
	time2 run();
	void readStationscsv();
	void readConnectionscsv();
	void readTrainscsv();
	void readData();
	void start();
	Station* getStation(int id);
};