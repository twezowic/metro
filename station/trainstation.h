#include "station.h"
//#include "../person/people.h"
class trainstation : public Station
{
    int perons;
    vector <queue<pair<string, int>>>peron_timeteble_vec;
public:
    trainstation(string name1, int id1,int peron1,int x1=0,int y1=0);
    void add_timetable(string trainname, int time,int peron=0);
    string nexttrain(int time, int peron = 0);
    //std::vector<train> getCurrentTrains();
    //std::vector<people> getWaitingList();

};
