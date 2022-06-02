#include "train.h"

#include"../station/station.h"
train::train(int id1,string name1,int maxcapity1):id(id1),name(name1),maxcapity(maxcapity1)
{
    people = {};
}
void train::setroute(vector <Station*> route1)
{
    routeid =route1;
    nextstop = routeid[0];
}
bool train::isfull()
{
    return maxcapity<=people.size();
}
string train::toString()
{
    return name+" "+to_string(id);
}

double train::getx(int time)
{
    double x = 0;
    bool end = false;
    int simultime = time;
    while (!end)
    {
       

    std:pair<vector<train*>,int>  para = nextstop->nexttrain(simultime);
        simultime = para.second + 1;
        vector<train*> trains = para.first;
        for (int i = 0; i < trains.size(); i++)
        {

            if (trains[i]->toString() == this->toString())
            {
                end = true;
                break;
            }
        }
    }

    //endtime
    int i = 0;
    for (i = 0; i < this->getRoute().size(); i++)
    {
        if (this->getRoute()[i] == nextstop)
        {
            i--;
            break;
        }
    }
    if (i == -1)
    {
        return this->getRoute()[0]->x;
    }
    int conectiontime = this->getRoute()[i]->getConnectionTime(nextstop);
    int starttime = simultime - conectiontime;
    int progres = time - starttime;
    double mul = (progres*1.00) / conectiontime;
    int x1 = this->getRoute()[i]->x;
    int x2 = nextstop->x;
    x = x1 + (x2 - x1) * mul;
    return x;
}
double train::gety(int time)
{
    double y = 0;
    bool end = false;
    int simultime = time;
    while (!end)
    {
    std:pair<vector<train*>, int>  para = nextstop->nexttrain(simultime);
        simultime = para.second + 1;
        vector<train*> trains = para.first;
        for (int i = 0; i < trains.size(); i++)
        {

            if (trains[i]->toString() == this->toString())
            {
                end = true;
            }
        }
    }

    //endtime
    int i = 0;
    for (i = 0; i < this->getRoute().size(); i++)
    {
        if (this->getRoute()[i] == nextstop)
        {
            i--;
            break;
        }
    }
    if (i == -1)
    {
        return this->getRoute()[0]->y;
    }
    int conectiontime = this->getRoute()[i]->getConnectionTime(nextstop);
    int starttime = simultime - conectiontime;
    int progres = time - starttime;
    double mul = (progres*1.00) / conectiontime;
    int y1 = this->getRoute()[i]->y;
    int y2 = nextstop->y;
    y = y1 + (y2 - y1) * mul;
    return y;
}
void train::newstop()
{
    int i = 0;
    for (i = 0; i < this->getRoute().size(); i++)
    {
        if (this->getRoute()[i] == nextstop)
        {
            if (i != this->getRoute().size() - 1)
            {
                nextstop = this->getRoute()[i + 1];
                break;
            }
            else
            {
                nextstop = this->getRoute()[0];
            }
        }
    }
}
