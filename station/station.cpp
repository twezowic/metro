#pragma once
#include "station.h"
using namespace std;

#include <queue>
#include <vector>
#include <string>
Station::Station(string name1, int id1, int x1, int y1) :point(x1, y1, id1)
{
    name = name1;

}

string Station::toString()
{
    return (name + " " + to_string(id));
}
void Station::add_conection(one_wayconection& id)
{
    out_conection_vec.push_back(&id);
}
void Station::remove_conection(one_wayconection id)
{
    int position = 0;
    for (auto i = out_conection_vec.begin(); i < out_conection_vec.end(); i++)
    {
        if (*i == &id)
        {
            position = i - out_conection_vec.begin();
        }
    }
    out_conection_vec.erase(out_conection_vec.begin() + position);
}
void  Station::add_timetable(train& trainname, time time)
{
    mytimetable.add_timetable(trainname, time);
}
pair<train*, time> Station::nexttrain(time time)
{
    return mytimetable.nextTrain(time);
}
void Station::setwaiting(vector <Person*> newvector)
{
    while (waiting.size() != 0)
    {
        waiting.pop_back();
    }
    for (int i = 0; i < newvector.size(); i++)
    {
        waiting.push_back(newvector[i]);
    }
}

std::vector<train*> Station::getNextTrains(time cur_time)
{
    return std::vector<train*>();
}

std::vector<Person*> Station::getWaitingList()
{
    return std::vector<Person*>();
}
