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
pair<vector<train*>,int> Station::nexttrain(time time1) 
{
    return mytimetable.nextTrain(time1);
    
}
void Station::setwaiting(vector <Person*> newvector)
{
  
    waiting = newvector;
    
}

