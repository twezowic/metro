#include "people.h"

Person::Person(Station* next_stopp): next_stop(next_stopp)
{

};

//people::people(station& station) :idstation(station)
//{
//
//};

void Person::setroute(vector <Station*> route1)
{
    myroute=route1;
}