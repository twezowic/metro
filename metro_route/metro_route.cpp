#include <iostream>
#include"Route.h"
#include"Station.h"

using namespace std;

int main()
{
    Route route;
    Station station("war", 1, 2);
    route += station;
    cout << route.getStations()[0].getName();
}