#include "MetroApp.h"
#include<iostream>



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
	file.close();
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
	file.close();
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
	file.close();
}
void MetroApp::readData()
{
	readStationscsv();
	readConnectionscsv();
	readTrainscsv();
}

string MetroApp::drawConnection(int x1, int y1, int x2, int y2)
{
	return "<line x1=\"" + to_string(x1) + "\" y1=\"" + to_string(y1) + "\" x2=\"" + to_string(x2) + "\" y2=\"" + to_string(y2) + "\" style=\"stroke:rgb(0, 0, 0);stroke-width:2\" />";
}
string MetroApp::drawStation(int x, int y)
{
	return "<circle cx=\"" + to_string(x) + "\" cy=\"" + to_string(y) + "\" r=\"4\" stroke=\"black\" stroke-width=\"3\" fill=\"red\" />";
}

string MetroApp::drawTrain(int lastStationx, int lastStationy, int nextStationx, int nextStationy, double distance, double actualDistance)
{
	double distancePercentage = actualDistance / distance;
	int newX, newY;

	if (lastStationx - nextStationx != 0)
	{
		int lineEquationX = (lastStationy - nextStationy) / (lastStationx - nextStationx);
		int lineEquationY = lastStationy - ((lastStationy - nextStationy) / (lastStationx - nextStationx)) * lastStationx;

		newX = abs(lastStationx - nextStationx) * distancePercentage + lastStationx;
		newY = lineEquationX * newX + lineEquationY;
	}
	else
	{
		newX = lastStationx;
		newY = abs(lastStationy - nextStationy) * distancePercentage + lastStationy;

	}

	return "<circle cx=\"" + to_string(newX) + "\" cy=\"" + to_string(newY) + "\" r=\"4\" stroke=\"black\" stroke-width=\"3\" fill=\"blue\" />";
}



void MetroApp::create_map()
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
		result += drawConnection(x1, y1, x2, y2) + '\n';
	}
	// stations
	for (int i = 0; i < metro_coor.getStations().size(); i++)
	{
		int x, y;
		//x = metro_coor.getStations()[i].getX();
		//y = metro_coor.getStations()[i].getY();
		result += drawStation(x, y) + '\n';
	}
	result += "</svg>";
	fstream file("../station.svg", ios::out);
	file << result;
	file.close();
}


void MetroApp::add_trains()
{
	string result;
	for (int i = 0; i < trains_pairs.size(); i++)
	{
		int lastStationx, lastStationy, nextStationx, nextStationy;
		double distance, actualDistance;
		//result += drawTrain(lastStationx, lastStationy, nextStationx, nextStationy, distance, actualDistance) + '\n';
	}

	stringstream text;
	ifstream in_file("../sample.svg");

	text << in_file.rdbuf();
	string str = text.str();
	int position = str.find("</svg>");
	str.replace(position, 6, result);
	in_file.close();

	ofstream out_file("../sample.svg");
	out_file << str << endl << "</svg>";
}

// TODO
// get attributes from classes to use them in in write methods