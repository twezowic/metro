#include "../AppLib/MetroApp.h"
#include "../CoordinatorLib/CoordinatorLib.h"

#include <vector>
//#include <iostream> - currently can not include, as it has a "time" object defined, which causes redefinition with our "time"


int main()
{

	class A
	{
	public:
		int aha = 2;
		A() {};
	};
	A a1 = A();
	auto a1_ptr = &a1;
	A a2 = A();
	A a3 = A();
	A a4 = A();
	std::vector<A*> v1;
	v1.push_back(a1_ptr);

	int a;



	// read stations, trains, connections from first file
	// read people from second file
	auto metro = MetroApp();
	metro.start();
	int sim_time = metro.run();
	//std::cout << sim_time;

	return 0;
}