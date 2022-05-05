#include "Train.h"


std::string Train::getInfoAboutOneWagon(int wagon_number)
{
	auto wag_ptr = wagon_vec[wagon_number];
	std::string info = "Wagon number: " + std::to_string(wagon_number) + " with an id " + std::to_string(wag_ptr->getID()) + " is a ";

	if (dynamic_cast<PassenegerWagon*>(wag_ptr) != nullptr) {
		PassenegerWagon* new_wag_ptr = dynamic_cast<PassenegerWagon*>(wag_ptr);
		info += "passeneger wagon, it has " + std::to_string(new_wag_ptr->findNumberOfFreePlaces()) + " out of " + std::to_string(new_wag_ptr->getNumberOfPlaces()) + " free sits";
	}

	if (dynamic_cast<LivestockWagon*>(wag_ptr) != nullptr) {
		LivestockWagon* new_wag_ptr = dynamic_cast<LivestockWagon*>(wag_ptr);
		info += "livestock wagon, it is " + std::to_string(new_wag_ptr->getFilledPerc()) + "% percentage full. Animal carried is: " + new_wag_ptr->getGoodsName();
	}
	if (dynamic_cast<Cistern*>(wag_ptr) != nullptr) {
		Cistern* new_wag_ptr = dynamic_cast<Cistern*>(wag_ptr);
		info += "Cistern, it is filled in " + std::to_string(new_wag_ptr->getFilledPerc()) + "% percentage with " + new_wag_ptr->getGoodsName();
	}
	if (dynamic_cast<SolidMatWagon*>(wag_ptr) != nullptr) {
		SolidMatWagon* new_wag_ptr = dynamic_cast<SolidMatWagon*>(wag_ptr);
		info += "material wagon, it is filled in " + std::to_string(new_wag_ptr->getFilledPerc()) + "% percentage with " + new_wag_ptr->getGoodsName();
	}
	return info;
}

//Train::WagonType Train::findWagonType(Wagon* wagon_ptr)
//{
//	if (typeid(wagon_ptr).hash_code() == typeid(PassenegerWagon*).hash_code())
//		return WagonType::PassenegerWagon;
//	if (typeid(wagon_ptr).hash_code() == typeid(LivestockWagon*).hash_code())
//		return WagonType::LivestockWagon;
//	if (typeid(wagon_ptr).hash_code() == typeid(SolidMatWagon*).hash_code())
//		return WagonType::SolidMatWagon;
//	if (typeid(wagon_ptr).hash_code() == typeid(Cistern*).hash_code())
//		return WagonType::Cistern;
//}

std::vector<Station_ptr> Train::getRoute()
{
	return route;
}

Train::Train(int idd, Tonnes weigthh, std::vector<Wagon*> wag_vec, std::vector<Station_ptr> routee): id(idd), weigth(weigthh), wagon_vec(wag_vec), route(routee) {}

Train::Train(int idd, Tonnes weigthh, std::vector<Station_ptr> routee): id(idd), weigth(weigthh), route(routee) {}

std::string Train::GetInfoAboutWagons()
{
	int i = 0;
	std::string end_str = "";
	for (int i = 0; i < wagon_vec.size(); ++i)
	{
		end_str += getInfoAboutOneWagon(i);
		end_str += '\n';
	}
	return end_str;
}
