#include "MetroApp.h"


MetroApp::MetroApp() {}

void MetroApp::setTrains(vector<std::pair<Train, Train>> trains_pairss)
{
	this->trains_pairs = trains_pairss;
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

min_time MetroApp::run()
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

	fstream file("../station.csv", ios::in);
	getline(file, line);
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

	fstream file("../connection.csv", ios::in);
	getline(file, line);
	while (getline(file, line))
	{
		row.clear();

		stringstream str(line);

		while (getline(str, word, ';'))
			row.push_back(word);

		//add connection to connections
		Station* station1 = getStation(stoi(row[0]));
		Station* station2 = getStation(stoi(row[1]));
		int distance = stoi(row[2]);
		connections.push_back(conection(station1, station2, distance));
	}
	setConnections(connections);
}
void MetroApp::readTrainscsv()
{
	vector<std::pair<Train, Train>> trains_pair;
	vector<string> row;
	string line, word;

	fstream file("../trains.csv", ios::in);
	getline(file, line);
	while (getline(file, line))
	{
		row.clear();

		stringstream str(line);

		while (getline(str, word, ';'))
			row.push_back(word);

		int id1 = stoi(row[0]);
		string name1 = row[1];
		int maxcapacity = stoi(row[2]);
		Train train1(id1, name1, maxcapacity);
		vector<Station*> stations;
		for (int i = 3; i < row.size(); i++)
		{
			stations.push_back(getStation(stoi(row[i])));
		}
		train1.setroute(stations);
		Train train1prim(id1, name1 + "_prim", maxcapacity); // same train, but with opposite route is considered a new object
		std::reverse(stations.begin(), stations.end());
		train1prim.setroute(stations);


		trains_pair.push_back(std::make_pair(train1, train1prim));

	}
	setTrains(trains_pair);
}
void MetroApp::readData()
{
	readStationscsv();
	readConnectionscsv();
	readTrainscsv();
}


}

void MetroApp::create_svg()
{

}

