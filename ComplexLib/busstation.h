#include "station.h"
class trainstation : public station
{
	int perons;
	vector <queue<pair<string, int>>>peron_timeteble_vec;
public:
	trainstation(string name1, int id1,int peron1);
	void add_timetable(string trainname, int time,int peron=0);
	string nexttrain(int time, int peron = 0);

};