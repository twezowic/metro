//everything except for reading files was done by Damian Pałyska
//main aplication and reading files by Tomasz Wężowicz


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
	min_time metro_start_time;
	Coordinator metro_coor;
	std::vector<std::pair<Train, Train>> trains_pairs; // since coordinator doesn't have this, metro probably should to ensure they don't get deleted
	std::vector<conection> connect_vec; // same as with trains
	std::vector<Person> person_vec;
	int people_in_metro;
	void addPeopleToStations();
public:
	min_time simulation_time;
	
	MetroApp(min_time start_time);
	Coordinator getCoordinator() { return metro_coor; }
	std::vector<std::pair<Train, Train>> getTrains() { return trains_pairs; }
	std::vector<conection> getConnections() { return connect_vec; }
	Train getCurrentTrain(std::pair<Train, Train>);
	void setTrains(vector<std::pair<Train, Train>> trains);
	void setConnections();
	bool hasPeople();
	min_time run();
	void readStationscsv();
	void readConnectionscsv();
	void readTrainscsv();
	void readData();
	void generatePeople(int people_number);

	void start(int people_number, min_time start_time);

	Station* getStation(int id);
};