#include <vector>
#include <string>
#include "../person/people.h"
using namespace std;

class train
{   int maxcapity;
    int curent_capity;
    int id;
    string name;
    vector <int> routeid;
public:
    train(int id1,string name1,int maxcapity,int curent_capity=0);
    void setroute(vector <int> route);
    bool isfull();
    string toString();
    void increasecap();
    void decreasecap();
};