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

void MetroApp::run()
{
	//	while (metro.hasPeople());
	//{
	//	metro_coordinator.HandleStations();
	//	++time;
	//}

}

void MetroApp::readStationscsv()
{

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
