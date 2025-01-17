#pragma once
//all done by Michal Bogiel
#include <vector>
#include <string>
#include "../person/people.h"
using namespace std;
class Station;
class train
{   int maxcapity;
    int id;
    string name;
    vector <Person*> people;
    vector <Station*> routeid;
    Station* nextstop;
public:
    train(int id1,string name1,int maxcapity);
    Station* getNextStop() { return nextstop; }
    string getName() { return name; }
    int getMaxCapacity() { return maxcapity; }
    int getPeopleNumber() { return people.size(); }
    void setroute(vector <Station*> route);
    bool isfull();
    string toString();
   
    void setpeople(vector <Person*> newpeople)
    {
        people = newpeople;
    }
    std::vector<Person*> getPeopleVec() { return people; };
    std::vector<Station*> getRoute() { return routeid; };
    void AddPerson(Person* new_per) { people.push_back(new_per); };
    bool hasFreeSpace() { return !isfull(); };
    double getx(int time);
    double gety(int time);
    void newstop();
};