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
    void add_timetable(train& trainname, time time1);
    pair<std::vector<train*>, time> nexttrain(time time1); //#TODO, probably change function name to getNextTrains, or whatever
    vector <one_wayconection*> vec()
    {
        return out_conection_vec;
    }
    void setwaiting(vector <Person*> newvector);
    std::vector<train*> getNextTrains(time cur_time); //@TODO returns every train on the station during the given time - empty vector is none 
    std::vector<Person*> getWaitingList(); //@TODO
    bool hasTrains() { return false; }; //@TODO
};
