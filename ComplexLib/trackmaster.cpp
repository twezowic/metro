#include "trackmaster.h"
#include <iostream>
trackmaster::trackmaster()
{

}
void trackmaster::add_station(station st)
{
	stations.push_back(st);
}
void trackmaster::add_conection(conection st)
{
	conections.push_back(st);
	//add connection  to outway do odpowiednich staji
	for (int i = 0; i < stations.size(); i++)
	{
		if (st.distance(stations[i].getid()) != -1)
		{
			stations[i].add_conection(st.getid());
		}
	}
}
void trackmaster::print_stations()
{
	for (int i = 0; i < stations.size(); i++)
	{
		cout << stations[i].toString();
	}
}
void trackmaster::print_conections()
{
	for (int i = 0; i < conections.size(); i++)
	{
		cout << conections[i].toString();
	}
}
void trackmaster::findway(int id1, int id2)
{
	//to do
}

void trackmaster::block_conection(int idconection, int idstation)
{
	for (int i = 0; i < stations.size(); i++)
	{
		if (stations[i].getid() == idstation)
		{
			stations[i].remove_conection(idconection);
		}
	}
}
void trackmaster::add_timetable(int idstation, string trainname, int time)
{
	for (int i = 0; i < stations.size(); i++)
	{
		if (stations[i].getid() == idstation)
		{
			stations[i].add_timetable(trainname, time);
		}
	}
}
string trackmaster::nexttrain(int idstation, int time)
{
	for (int i = 0; i < stations.size(); i++)
	{
		if (stations[i].getid() == idstation)
		{
			return stations[i].nexttrain(time);
		}
	}
}
void trackmaster::edit_conection(int id, conection st)
{
	int position = 0;
	for (auto i = conections.begin(); i < conections.end(); i++)
	{
		if ((*i).getid() == id)
		{
			position = i - conections.begin();
		}
	}
	block_conection(id, conections[position].getstation1id());
	block_conection(id, conections[position].getstation2id());
	conections.erase(conections.begin() + position);
	add_conection(st);

}