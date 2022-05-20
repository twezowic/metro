#pragma once
#include "../CoordinatorLib/CoordinatorLib.h"
#include "../conections/conection.h"

class MetroApp
{
private:
	Coordinator metro_coor;
	std::vector<Train> train_vec; // since coordinator doesn't have this, metro probably should to ensure they don't get deleted
	std::vector<conection> connect_vec; // same as with trains

public:
	time simulation_time;

	MetroApp();
	bool hasPeople();
	time run();
	void readStationscsv();
	void readConnectionscsv();
	void readTrainscsv();
	void readData();
	void start();
};