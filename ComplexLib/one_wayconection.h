#pragma once
#include "conection.h"
class one_wayconection :
	public conection
{
public:
	one_wayconection(int id1, int id2, int mynewid, int distance, int distance2 = 0);
	int distance(int idstation);
	virtual ~one_wayconection();
};