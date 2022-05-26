#include "train.h"

train::train(int id1,string name1,int maxcapity1):id(id1),name(name1),maxcapity(maxcapity1)
{

}
void train::setroute(vector <Station*> route1)
{
    routeid =route1;
}
bool train::isfull()
{
    return maxcapity<=people.size();
}
string train::toString()
{
    return name+" "+to_string(id);
}

