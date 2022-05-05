#include <iostream>
#include "../TrainLib/Train.h"
#include "../WagonLib/Wagon.h"


int main()
{
	std::vector<int> vvvv = { 1,2,3,4,5 };
	Cistern w1 = Cistern(12, "oil", 10.0, 10.0, 2.0);
	LivestockWagon w3 = LivestockWagon(11, "cow", 10, 100, 50);
	SolidMatWagon w2 = SolidMatWagon(10, "coal", 10, 50.0, 10.0);
	PassenegerWagon wp = PassenegerWagon(10, 100, 50);

	std::vector<Wagon*> wag_vec = { &w1, &w2, &w3, &wp };
	std::vector<Station_ptr> v;
	Train t1 = Train(1, 10.0, wag_vec, v);
	
	//auto ffff = typeid(wp).hash_code() == typeid(PassenegerWagon).hash_code();
	//auto ggg = typeid(wp).hash_code();
	//auto hhh = typeid(Wagon).hash_code();
	//auto iii = typeid(vaa[3]).hash_code();

	std::string to_return = t1.GetInfoAboutWagons();
	std::cout << to_return;
	return 0;
}