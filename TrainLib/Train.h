#include <vector>
#include <string>
#include "../WagonLib/Wagon.h"
#pragma once

typedef int* Station_ptr;

class Train
{
private:
	enum class WagonType { PassenegerWagon, LivestockWagon, SolidMatWagon, Cistern};
	Tonnes weigth;
	int id;
	std::vector<Wagon*> wagon_vec;
	std::vector<Station_ptr> route;
	std::string getInfoAboutOneWagon(int wagon_number);
	//WagonType findWagonType(Wagon* wagon_ptr);

public:
	int getWagonNumber() { return wagon_vec.size(); };
	std::vector<Station_ptr> getRoute();
	Train(int idd, Tonnes weigthh, std::vector<Wagon*> wag_vec, std::vector<Station_ptr>routee);
	Train(int idd, Tonnes weigthh, std::vector<Station_ptr>routee);
	std::string GetInfoAboutWagons();
	std::vector<Station_ptr> getStations() { return route; };
};
