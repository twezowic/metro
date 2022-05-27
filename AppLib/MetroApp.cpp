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

string MetroApp::line(int x1, int y1, int x2, int y2)
{
	return "<line x1=\"" + to_string(x1) + "\" y1=\"" + to_string(y1) + "\" x2=\"" + to_string(x2) + "\" y2=\"" + to_string(y2) + "\" style=\"stroke:rgb(0, 0, 0);stroke-width:2\" />";
}
string MetroApp::dot(int x, int y)
{
	return "<circle cx=\"" + to_string(x) + "\" cy=\"" + to_string(y) + "\" r=\"4\" stroke=\"black\" stroke-width=\"3\" fill=\"red\" />";
}


void MetroApp::create_svg()
{
	string result;
	result += "<svg  version = \"1.1\" xmlns = \"http://www.w3.org/2000/svg\">\n";
	//connections
	for (int i = 0; i < connect_vec.size(); i++)
	{
		int x1, y1, x2, y2;
		//x1 = connect_vec[i].getstation1id().getX();
		//y1 = connect_vec[i].getstation1id().getY();
		//x2 = connect_vec[i].getstation2id().getX();
		//y2 = connect_vec[i].getstation2id().getY();
		result += line(x1, y1, x2, y2) + '\n';
	}
	// stations
	for (int i = 0; i < metro_coor.getStations().size(); i++)
	{
		int x, y;
		//x = metro_coor.getStations()[i].getX();
		//y = metro_coor.getStations()[i].getY();
		result += dot(x, y) + '\n';
	}
	//trains
	result += "</svg>";
}

