#include "MetroApp.h"

MetroApp::MetroApp() {}

bool MetroApp::hasPeople()
{
	return false;
}

void MetroApp::start()
{
	readData();
}

time MetroApp::run()
{
		while (hasPeople());
	{
		metro_coor.HandleStations();
		metro_coor.increaseTime(simulation_time);
	}
	return simulation_time;
}

void MetroApp::readStationscsv()
{
	//metro_coor.addStation(Station(data_read)
}
void MetroApp::readConnectionscsv()
{

}
void MetroApp::readTrainscsv()
{

}
void MetroApp::readData()
{
	readStationscsv();
	readConnectionscsv();
	readTrainscsv();
}
