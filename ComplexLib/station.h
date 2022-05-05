#pragma once

#include <queue>
#include <vector>
#include <string>
using namespace std;
class station
{
protected:
	string name;
	vector <int> out_conection_vec;
	int id;
	//int peron_number;
	queue<pair<string, int>> timetable;
public:
	station(string name1, int id1);
	string toString();
	void add_conection(int id);
	void remove_conection(int id);
    //void add_timetable(string trainname, int time, int peron);
	//string nexttrain(int time, int peron);
	void add_timetable(string trainname, int time);
	string nexttrain(int time);
	int getid() { return id; }
};

