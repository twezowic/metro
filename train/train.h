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
public:
    train(int id1,string name1,int maxcapity);
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
};