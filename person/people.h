#pragma once
using namespace std;
#include <vector>
typedef int time;
class Station;

class Person
{
  Station* next_stop;
  vector <Station*>myroute;
public:
    Person(Station* next_stop);
    void setroute(vector <Station*>route1);
};


