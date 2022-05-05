#include "one_wayconection.h"



one_wayconection::one_wayconection(int id1, int id2, int mynewid, int distance, int distance2) : conection(id1, id2, mynewid, distance, -1)
{
};

int one_wayconection::distance(int idstation)
{
	if (idstation == station1id)
	{
		return distance1;
	}
}
one_wayconection::~one_wayconection()
{
}