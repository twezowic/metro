#pragma once
#include <string>
using namespace std;
class conection
{
protected:
	int distance1;
	int distance2;
	int myid;
	int station1id;
	int station2id;
public:
	conection(int id1, int id2, int mynewid, int distance);
	conection(int id1, int id2, int mynewid, int distance, int distance3);
	int distance(int idstation);
	int getid() { return myid; }
	int getstation1id() { return station1id; }
	int getstation2id() { return station2id; }
	string toString();
};

