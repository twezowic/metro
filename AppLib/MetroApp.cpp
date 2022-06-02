#include "MetroApp.h"
#include "Display.h"
#include<iostream>



MetroApp::MetroApp(min_time start_time): metro_start_time(start_time) { simulation_time = 0; people_in_metro = 0; }

Train MetroApp::getCurrentTrain(std::pair<Train, Train> trains_pairss)
{
	train first = trains_pairss.first;

	train second = trains_pairss.second;
	if (first.getRoute()[0] == first.getNextStop())
	{
		return second;
	}
	return first;
}

void MetroApp::setTrains(vector<std::pair<Train, Train>> trains_pairss)
{
	this->trains_pairs = trains_pairss;
}
void MetroApp::setConnections()
{
	for (auto ite = connect_vec.begin(); ite != connect_vec.end(); ++ite)
	{ 
		getStation((*ite).getstation1id())->add_conection(*(ite));
		getStation((*ite).getstation2id())->add_conection(*(ite));
	}
}

bool MetroApp::hasPeople()
{
	if (people_in_metro > 0)
		return true;
	else
		return false;
}

void MetroApp::start(int people_number, min_time start_time)
{
	srand(time(NULL));
	readData();
	metro_coor.setTime(start_time);
	metro_coor.fillTimetable(trains_pairs);
	generatePeople(people_number);
	addPeopleToStations();

	people_in_metro = person_vec.size();
}


min_time MetroApp::run()
{
	int input=1;
	bool goForward = false;
	auto display = Display();
	auto display_text = Display_text();
	while (input!=0)
	{
		cout << display.showMenu();
		cin >> input;
		cout << endl;
		switch (input)
		{
		case (1):
		{
			cout<<display_text.showStations(*this);
			break;
		}
		case (2):
		{
			cout<<display_text.showTrains(*this);
			break;
		}
		case (3):
		{
			display_text.create_map(*this);
			break;
		}
		case (4):
		{
			display.create_map(*this);
			break;
		}
		case (5):
		{
			cout  << display_text.showTime(metro_coor.getTime());
			cout  << display_text.showSimulationTime(simulation_time);
			break;
		}
		case (6):
		{
			int forward_time;
			std::cout << "How many minutes would you like to forward the time to: ";
			std::cin >> forward_time;
			for (int i = 0; i < forward_time; ++i)
			{
				metro_coor.HandleStations(this->people_in_metro);
				metro_coor.increaseTime(simulation_time);
				if (!people_in_metro and !goForward)
				{
					cout << display_text.showSimulationTime(simulation_time);
					cout << "There are no more people in metro\nDo you want to continue?\n0/1: ";
					cin >> input;
					if (input == 0)
					{
						break;
					}
					else
					{
						goForward = true;
					}
					
				}
			}
			break;
		}
		default:
			break;
		}
		goForward = false;
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
	//vector<conection> connections;
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
		connect_vec.push_back(conection(station1, station2, distance));
		}
	setConnections();
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

void MetroApp::generatePeople(int people_number)
{
	while (people_number > 0)
	{
		auto a = rand() % metro_coor.getStations().size();
		auto b = rand() % metro_coor.getStations().size();
		int start_stat_id = metro_coor.getStations()[a].getid();
		int end_stat_id = metro_coor.getStations()[b].getid();
		person_vec.push_back(Person(metro_coor.dijkstra(start_stat_id, end_stat_id)));
		--people_number;
	}
}

void MetroApp::addPeopleToStations()
{
	for (auto ite = person_vec.begin(); ite != person_vec.end(); ++ite)
	{
		(*ite).getRoute()[0]->addWaitingPerson(&(*ite));
	}
}



Station* MetroApp::getStation(int id)
{
	return metro_coor.getStation(id);
}

