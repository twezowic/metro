#pragma once
#include "../CoordinatorLib/CoordinatorLib.h"
class MetroApp
{
private:
	Coordinator metro_coor;

public:
	MetroApp();
	bool hasPeople();
	void run();
//	friend //czytaj z pliku
	void start();
	
};