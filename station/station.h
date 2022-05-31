#pragma once

#include "../point/point.h"
#include <queue>
#include <vector>
#include <string>
#include "../conections/one_wayconection.h"
#include "../timetable/timetable.h"
#include "../person/people.h"

using namespace std;
class Station : public point
{
protected:
    string name;
    vector <one_wayconection*> out_conection_vec;
    timetable mytimetable;
    vector <Person*> waiting;
public:
    Station(string name1, int id1, int x1 = 0, int x2 = 0);
    string toString();
    void add_conection(one_wayconection& id);
    void remove_conection(one_wayconection id);
    void add_timetable(train& trainname, min_time time1);
    pair<std::vector<train*>, min_time> nexttrain(min_time time1);
    min_time getConnectionTime(Station* next_station); //@TODO
    vector <one_wayconection*> vec()
    {
        return out_conection_vec;
    }
    void setwaiting(vector <Person*> newvector);
    std::vector<train*> getNextTrains(min_time cur_time)
    {
        return nexttrain(cur_time).first;
    }
    std::vector<Person*> getWaitingList()
    {
        return waiting;
    };
    bool hasTrains(min_time i) {
        return i == nexttrain(i).second;
    }; 
};
