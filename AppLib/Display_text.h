#pragma once
#include"MetroApp.h"
#include<string>
#include<iostream>
using namespace std;
class Display_text
{
protected:
	int width, height;
public:
	Display_text() { this->width = 25; this->height = 25; }
	Display_text(int width, int height) { this->width = width; this->height = height; }

	virtual void create_map(MetroApp metroapp);
	string showStations(MetroApp metroapp);
	string showTrains(MetroApp metroapp);
	string showTime(int time);
	string showSimulationTime(int time);

	string showMenu();
};

