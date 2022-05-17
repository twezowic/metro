using namespace std;
#include <vector>
//#include "../station/station.h"

class Station;

class Person
{int idstation;
  vector <Station*>myroute;
public:
    Person(Station* next_stop);
    void setroute(vector <Station*>route1);
};


