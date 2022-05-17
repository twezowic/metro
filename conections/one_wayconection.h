#pragma once
#include <string>
#include "../point/point.h"
using namespace std;
class one_wayconection

{protected:
    int distance1;
    point* station1id;
    point* station2id;
public:
    one_wayconection(point* id1, point* id2,  int distance);
    int distance(int idstation);
    int getstation1id() { return station1id->getid(); }
    int getstation2id() { return station2id->getid(); }
    std::string toString();
    virtual ~one_wayconection();
};
