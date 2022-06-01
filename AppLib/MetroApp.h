#pragma once
#include "../CoordinatorLib/CoordinatorLib.h"
#include "../station/station.h"
#include "../conections/conection.h"
#include<fstream>
#include<sstream>
#include<cmath>
#include <random>

class Display;
class MetroApp
{
private:
	Coordinator metro_coor;
	std::vector<std::pair<Train, Train>> trains_pairs; // since coordinator doesn't have this, metro probably should to ensure they don't get deleted
	std::vector<conection> connect_vec; // same as with trains
	std::vector<Person> person_vec;
public:
	min_time simulation_time = 720; //@TODO change time declaration
	
	MetroApp();
	Coordinator getCoordinator() { return metro_coor; }
	std::vector<std::pair<Train, Train>> getTrains() { return trains_pairs; }
	std::vector<conection> getConnections() { return connect_vec; }
	Train getCurrentTrain(std::pair<Train, Train>);
	void setTrains(vector<std::pair<Train, Train>> trains);
	void setConnections();
	bool hasPeople();
	min_time run(Display display);
	void readStationscsv();
	void readConnectionscsv();
	void readTrainscsv();
	void readData();
	void generatePeople(int people_number);

	void start();

	Station* getStation(int id);
};