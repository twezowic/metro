#pragma once
#include "../CoordinatorLib/CoordinatorLib.h"
class MetroApp
{
private:
	Coordinator metro_coor;

public:
	MetroApp();
	bool hasPeople();
	void run();
	void readStationscsv();
	void readConnectionscsv();
	void readTrainscsv();
	void readData();
	void start();
	
};