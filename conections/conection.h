
#pragma once
#include <string>
#include "./one_wayconection.h"


using namespace std;
class conection: public one_wayconection
{
protected:
    int distance2;
public:
    conection(point* id1, point* id2,  int distance);
    conection(point* id1, point* id2,  int distance, int distance3);
    int distance(int idstation);
    string toString();
};


