#include "trainstation.h"

trainstation::trainstation(string name1, int id1,int peron1,timetable& v,int x1,int y1) : station(name1, id1,v,x1,y1),perons(peron1)
{
    for (int i = 0; i < perons; i++)
    {
        queue < pair<string, int>> p;
        pair<string, int> c("nic", 2400);
        pair<string, int> d("nic", 00);
        p.push(c);
        p.push(d);
        peron_timeteble_vec.push_back(p);
    }
}
void  trainstation::add_timetable(string trainname, int time,int peron)
{
    if (peron_timeteble_vec[peron - 1].front().second == 2400)
    {
        pair<string, int> c("nic", 2400);
        pair<string, int> d("nic", 00);
        peron_timeteble_vec[peron - 1].pop();
        peron_timeteble_vec[peron - 1].push(c);
        peron_timeteble_vec[peron - 1].pop();
        peron_timeteble_vec[peron - 1].push(d);
    }

    while (!(peron_timeteble_vec[peron - 1].back().second < time and peron_timeteble_vec[peron - 1].front().second>time))
    {

        pair<string, int> element = peron_timeteble_vec[peron - 1].front();
        peron_timeteble_vec[peron - 1].pop();
        peron_timeteble_vec[peron - 1].push(element);
        if (peron_timeteble_vec[peron - 1].front().second == 00)
        {
            pair<string, int> d("nic", 00);

            peron_timeteble_vec[peron - 1].pop();
            peron_timeteble_vec[peron - 1].push(d);
        }

    }
    pair<string, int> to_push(trainname, time);
    peron_timeteble_vec[peron - 1].push(to_push);
}
string trainstation::nexttrain(int time, int peron)
{
    if (peron_timeteble_vec[peron - 1].front().second == 2400)
    {
        pair<string, int> c("nic", 2400);
        pair<string, int> d("nic", 00);
        peron_timeteble_vec[peron - 1].pop();
        peron_timeteble_vec[peron - 1].push(c);
        peron_timeteble_vec[peron - 1].pop();
        peron_timeteble_vec[peron - 1].push(d);
    }

    while (!(peron_timeteble_vec[peron - 1].back().second < time and peron_timeteble_vec[peron - 1].front().second>time))
    {

        pair<string, int> element = peron_timeteble_vec[peron - 1].front();
        peron_timeteble_vec[peron - 1].pop();
        peron_timeteble_vec[peron - 1].push(element);
        if (peron_timeteble_vec[peron - 1].front().second == 00)
        {
            pair<string, int> d("nic", 00);

            peron_timeteble_vec[peron - 1].pop();
            peron_timeteble_vec[peron - 1].push(d);
        }

    }

    return peron_timeteble_vec[peron - 1].front().first + " " + to_string(peron_timeteble_vec[peron - 1].front().second);
}
