#pragma once
#include "../CoordinatorLib/CoordinatorLib.h"
#include "../station/station.h"
#include "../conections/conection.h"
#include<fstream>
#include<sstream>
#include<cmath>

class MetroApp
{
private:
	Coordinator metro_coor;
	std::vector<std::pair<Train, Train>> trains_pairs; // since coordinator doesn't have this, metro probably should to ensure they don't get deleted
	std::vector<conection> connect_vec; // same as with trains

public:
	min_time simulation_time;

	MetroApp();
	Coordinator getCoordinator() { return metro_coor; }
	std::vector<std::pair<Train, Train>> getTrains() { return trains_pairs; }
	std::vector<conection> getConnections() { return connect_vec; }
	void setTrains(vector<std::pair<Train, Train>> trains);
	void setConnections(vector<conection> connections);
	bool hasPeople();
	min_time run();
	void readStationscsv();
	void readConnectionscsv();
	void readTrainscsv();
	void readData();

	string drawConnection(int x1, int y1, int x2, int y2);
	string drawStation(int x, int y);
	string drawTrain(int lastStationx, int lastStationy, int nextStationx, int nextStationy, double distance, double actualDistance);
	void create_map();
	void start();

	Station* getStation(int id);
};