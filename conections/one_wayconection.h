#pragma once
#include <string>
using namespace std;
class Station;
class one_wayconection

{protected:
    int distance1;
    Station* station1id;
    Station* station2id;
public:
    one_wayconection(Station* id1, Station* id2,  int distance);
    virtual int distance(int idstation);
    
    std::string toString();
    virtual ~one_wayconection();
    int getstation1id();
    int getstation2id();
};
