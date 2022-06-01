#pragma once
using namespace std;
#include <vector>
typedef int min_time;
class Station;

class Person
{
  Station* next_stop;
  vector <Station*>myroute;
public:
    Person(vector<Station*> route);
    Person(Station* next_stop);
    void setroute(vector <Station*>route1);
    Station* getNextStop() { return next_stop; };
    vector<Station*> getRoute() { return myroute; };
    void setNextStop(Station* new_stat) { next_stop = new_stat; };
};


