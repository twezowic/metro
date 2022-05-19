#include "conection.h"
#include "../station/station.h"
conection::conection(Station* id1, Station* id2,  int distance):one_wayconection(id1,id2,distance)
{

    distance2 = distance;
}
conection::conection(Station* id1, Station* id2,  int distance, int distance3):one_wayconection(id1,id2,distance)
{


    distance2 = distance3;
}
int conection::distance(int idstation)
{
    if (station1id->getid() == idstation)
    {
        return distance1;
    }
    else if (station2id->getid() == idstation)
    {
        return distance2;
    }
    return -1;
}
string conection::toString()
{
    return to_string(station1id->getid()) + " " + to_string(station2id->getid()) + " " + to_string(distance1) + " " + to_string(distance2);
}


