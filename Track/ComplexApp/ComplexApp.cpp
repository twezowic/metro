#include <iostream>
#include <iomanip>
#include "../ComplexLib/busstation.h"
#include "../ComplexLib/one_wayconection.h"

int main()
{
	station p("centrum", 5);

	string b = p.toString();
	cout << b << endl;
	p.add_timetable("grodzisk", 1250);
	p.add_timetable("pruszkow", 1350);
	p.add_timetable("piastow", 1300);
	p.add_timetable("Warszawa", 1400);
	b = p.nexttrain(1200);
	cout << b << endl;
	b = p.nexttrain(1255);
	cout << b << endl;
	b = p.nexttrain(1301);
	cout << b << endl;
	one_wayconection k(3, 4, 1, 5);
	one_wayconection k2(3, 4, 4, 5, 6);
	cout << k.toString() << endl;
	cout << k2.toString() << endl;

}