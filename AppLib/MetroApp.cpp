#include<fstream>
#include <sstream>
#include "MetroApp.h"


MetroApp::MetroApp() {}

void MetroApp::setTrains(vector<Train> trains)
{
	this->train_vec = trains;
}
void MetroApp::setConnections(vector<conection> connections)
{
	this->connect_vec = connections;
}

bool MetroApp::hasPeople()
{
	return false;
}

void MetroApp::start()
{
	readData();
}

int MetroApp::run()
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
	vector<Station> stations;
	vector<string> row;
	string line, word;

	fstream file("station.csv", ios::in);
	while (getline(file, line))
	{
		row.clear();

		stringstream str(line);

		while (getline(str, word, ';'))
			row.push_back(word);
		int id = stoi(row[0]);
		string name = row[1];
		int x = stoi(row[2]);
		int y = stoi(row[3]);
		stations.push_back(Station(name, id, x, y));
	}
	metro_coor.setStations(stations);
}
void MetroApp::readConnectionscsv()
{
	vector<conection> connections;
	vector<string> row;
	string line, word;

	fstream file("connection.csv", ios::in);
	while (getline(file, line))
	{
		row.clear();

		stringstream str(line);

		while (getline(str, word, ';'))
			row.push_back(word);
		
		//add connection to connections
		Station* station1 = getStation(row[0]);
		Station* station2 = getStation(row[1]);
		int distance = stoi(row[2]);
		connections.push_back(conection(station1, station2, distance));
	}
	setConnections(connections);
}
void MetroApp::readTrainscsv()
{
	vector<Train> trains;
	vector<string> row;
	string line, word;

	fstream file("trains.csv", ios::in);
	while (getline(file, line))
	{
		row.clear();

		stringstream str(line);

		while (getline(str, word, ';'))
			row.push_back(word);

		int id1 = stoi(row[0]);
		string name1 = row[1];
		int maxcapity = stoi(row[2]);
		Train train1(id1, name1, maxcapity);

		/*vector<Station*> stations;
		for (int i = 3; i < row.size(); i++)
		{
			stations.push_back(getStation(row[0]))
		}
		train1.setroute(stations);*/
		trains.push_back(train1);

	}
	setTrains(trains);
}
void MetroApp::readData()
{
	readStationscsv();
	readConnectionscsv();
	readTrainscsv();
}
Station* MetroApp::getStation(int id)
{
	return metro_coor.getStation(id);
		
		
	
}


