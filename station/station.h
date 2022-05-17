#include "../point/point.h"
#pragma once
#include <queue>
#include <vector>
#include <string>
#include "../conections/one_wayconection.h"
#include "../timetable/timetable.h"

using namespace std;
class Station: public point
{
protected:
    string name;
    vector <one_wayconection*> out_conection_vec;
    //int peron_number;
    timetable* mytimetable;
public:
    Station(string name1, int id1,timetable& v,int x1=0,int x2=0);
    string toString();
    void add_conection(one_wayconection& id);
    void remove_conection(one_wayconection id);
    //void add_timetable(string trainname, int time, int peron);
    //string nexttrain(int time, int peron);
    void add_timetable(train& trainname, int time);
    string nexttrain(int time);
    vector <one_wayconection*> vec()
    {
        return out_conection_vec;
    }
};
