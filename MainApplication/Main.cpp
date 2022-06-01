#include "../AppLib/MetroApp.h"
#include "../CoordinatorLib/CoordinatorLib.h"

#include <vector>
#include <iostream>


int main()
{
	min_time t = 60 * 12;
	int people_number = 100;

	auto metro = MetroApp();
	metro.start(people_number, t);
	metro.run();
	return 0;
}
