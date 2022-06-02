
#pragma once
#include <string>
#include "./one_wayconection.h"
//all done by Michal Bogiel
class Station;
using namespace std;
class conection: public one_wayconection
{
protected:
    int distance2;
public:
    conection(Station* id1, Station* id2,  int distance);
    conection(Station* id1, Station* id2,  int distance, int distance3);
    int distance(int idstation);
    string toString();
};


