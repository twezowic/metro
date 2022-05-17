#include "one_wayconection.h"



one_wayconection::one_wayconection(point* id1, point* id2,  int distance) {
    distance1=distance;
    station1id= id1;
    station2id=id2;
}

int one_wayconection::distance(int idstation)
{
    if (idstation == station1id->getid())
    {
        return distance1;
    }
    return -1;
}
one_wayconection::~one_wayconection()
{
}
std::string one_wayconection::toString()
{
    return to_string(station1id->getid()) + " " + to_string(station2id->getid()) + " " + to_string(distance1);
}
