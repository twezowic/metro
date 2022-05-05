#pragma once
#include "station.h"
using namespace std;

#include <queue>
#include <vector>
#include <string>
station::station(string name1, int id1)
{
	name = name1;
	id = id1;
	pair<string, int> c("nic", 2400);
	pair<string, int> d("nic", 00);
	timetable.push(c);
	timetable.push(d);
	
}
string station::toString()
{
	return (name + " " + to_string(id));
}
void station::add_conection(int id)
{
	out_conection_vec.push_back(id);
}
void station::remove_conection(int id)
{
	int position = 0;
	for (auto i = out_conection_vec.begin(); i < out_conection_vec.end(); i++)
	{
		if (*i == id)
		{
			position = i - out_conection_vec.begin();
		}
	}
	out_conection_vec.erase(out_conection_vec.begin() + position);
}
void  station::add_timetable(string trainname, int time)
{
	if (timetable.front().second == 2400)
	{
		pair<string, int> c("nic", 2400);
		pair<string, int> d("nic", 00);
		timetable.pop();
		timetable.push(c);
		timetable.pop();
		timetable.push(d);
	}

	while (!(timetable.back().second < time and timetable.front().second>time))
	{

		pair<string, int> element = timetable.front();
		timetable.pop();
		timetable.push(element);
		if (timetable.front().second == 00)
		{
			pair<string, int> d("nic", 00);

			timetable.pop();
			timetable.push(d);
		}

	}
	pair<string, int> to_push(trainname, time);
	timetable.push(to_push);
}
string station::nexttrain(int time)
{
	if (timetable.front().second == 2400)
	{
		pair<string, int> c("nic", 2400);
		pair<string, int> d("nic", 00);
		timetable.pop();
		timetable.push(c);
		timetable.pop();
		timetable.push(d);
	}

	while (!(timetable.back().second < time and timetable.front().second>time))
	{

		pair<string, int> element = timetable.front();
		timetable.pop();
		timetable.push(element);
		if (timetable.front().second == 00)
		{
			pair<string, int> d("nic", 00);

			timetable.pop();
			timetable.push(d);
		}

	}

	return timetable.front().first + " " + to_string(timetable.front().second);
}