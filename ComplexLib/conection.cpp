#include "conection.h"
conection::conection(int id1, int id2, int mynewid, int distance)
{
	myid = mynewid;
	station1id = id1;
	station2id = id2;
	distance1 = distance;
	distance2 = distance;
}
conection::conection(int id1, int id2, int mynewid, int distance, int distance3)
{
	myid = mynewid;
	station1id = id1;
	station2id = id2;
	distance1 = distance;
	distance2 = distance3;
}
int conection::distance(int idstation)
{
	if (station1id == idstation)
	{
		return distance1;
	}
	else if (station2id == idstation)
	{
		return distance2;
	}
	return -1;
}
string conection::toString()
{
	return to_string(station1id) + " " + to_string(station2id) + " " + to_string(distance1) + " " + to_string(distance2);
}