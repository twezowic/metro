#pragma once
#include "station.h"
#include "conection.h"
#include <vector>
class trackmaster
{
private:
	vector <station> stations;
	vector <conection> conections;
public:
	trackmaster();
	void add_station(station st);
	void add_conection(conection st);
	void print_stations();
	void print_conections();
	void findway(int id1, int id2);
	void add_timetable(int id, string trainname, int time);
	void edit_conection(int id, conection st);
	void block_conection(int idconection, int idstation);

	string nexttrain(int idstation, int time);
};

