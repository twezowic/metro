#include "train.h"

train::train(int id1,string name1,int maxcapity1,int curent_capity1):id(id1),name(name1),maxcapity(maxcapity1),curent_capity(curent_capity1)
{

}
void train::setroute(vector <Station*> route1)
{
    routeid =route1;
}
bool train::isfull()
{
    return maxcapity<curent_capity;
}
string train::toString()
{
    return name+" "+to_string(id);
}
void train::increasecap()
{
    curent_capity++;
}
void train::decreasecap()
{
    curent_capity--;
}
