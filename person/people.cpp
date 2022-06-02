#include "people.h"

Person::Person(vector<Station*> route): myroute(route)
{
    next_stop = nullptr;
}

Person::Person(Station* next_stopp): next_stop(next_stopp)
{

};


void Person::setroute(vector <Station*> route1)
{
    myroute=route1;
}
