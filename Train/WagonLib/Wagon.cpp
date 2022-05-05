#include "Wagon.h"

Wagon::Wagon(int idd, Tonnes weigthh) : id(idd), weigth(weigthh) {}


GoodsWagon::GoodsWagon(int idd, Tonnes weigthh, std::string goods_namee): Wagon(idd, weigthh), goods_name(goods_namee) {}

Cistern::Cistern(int idd, std::string goods_namee, Tonnes weigthh, Litres capacityy, Litres used_capp): GoodsWagon(idd, weigthh, goods_namee), capacity(capacityy), used_cap(used_capp) {}

double Cistern::getFilledPerc() const
{
	return used_cap/capacity*100;
}

SolidMatWagon::SolidMatWagon(int idd, std::string goods_namee, Tonnes weigthh, Tonnes capacityy, Tonnes used_capp): GoodsWagon(idd, weigthh, goods_namee), capacity(capacityy), used_cap(used_capp) {}

double SolidMatWagon::getFilledPerc() const
{
	return used_cap / capacity * 100;
}

LivestockWagon::LivestockWagon(int idd, std::string goods_namee, Tonnes weigthh, int livestock_capp, int cur_livestockk) : GoodsWagon(idd, weigthh, goods_namee), livestock_cap(livestock_capp), cur_livestock(cur_livestockk) {}

double LivestockWagon::getFilledPerc() const
{
	return double(cur_livestock) / double(livestock_cap) * 100.0;
}

PassenegerWagon::PassenegerWagon(int idd, Tonnes weigthh, int max_passenegers): Wagon(idd, weigthh)
{
	places_vec.assign(max_passenegers, 0);
}

int PassenegerWagon::findNumberOfFreePlaces()
{
	return std::count(places_vec.begin(), places_vec.end(), false);;
}

int PassenegerWagon::getNumberOfPlaces()
{
	return places_vec.size();
}

void PassenegerWagon::bookAPlace(int place) noexcept
{
	places_vec[place] = true;
}
