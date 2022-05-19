#include "../station/station.h"

vector<station*> stations;
int getpozition(int id)
{
    for (int i = 0; i < stations.size(); i++)
    {
        if (stations[i]->getid() == id)
        {
            return i;
        }

    }
    return -1;
}
vector<station*> dijkstra(int start, int second)
{
    vector<pair<int, int>> distan;
    while (distan.size() > 0)
    {
        distan.pop_back();
    }
    for (int i = 0; i < stations.size(); i++)
    {
        if (stations[i]->getid() != start)
        {
            distan.push_back(pair<int, int>(stations[i]->getid(), 999999));
        }
        else
        {
            distan.push_back(pair<int, int>(stations[i]->getid(), 0));
        }
    }
    priority_queue<pair<int, int>> tovisit;
    tovisit.push(pair<int, int>(-0, start));
    while (tovisit.size() != 0)
    {
        pair<int, int> present = tovisit.top();
        int presentpozition = getpozition(present.second);
        for (int i = 0; i < stations[presentpozition]->vec().size(); i++)
        {
            int koszt = (stations[presentpozition]->vec()[i])->distance(present.second);

            int disttous = distan[presentpozition].second;
            int distancetosec = distan[getpozition((stations[presentpozition]->vec()[i])->getstation2id())].second;
            if (disttous + koszt < distancetosec)
            {   //(stations[presentpozition]->vec()[i])->distance(presentpozition)odleg³osæ obecnegopo³
                distan[getpozition((stations[presentpozition]->vec()[i])->getstation2id())].second = (stations[presentpozition]->vec()[i])->distance(present.second) + distan[presentpozition].second;
                distan[getpozition((stations[presentpozition]->vec()[i])->getstation2id())].first = presentpozition;

                tovisit.push(pair<int, int>(-distan[getpozition((stations[presentpozition]->vec()[i])->getstation2id())].second, stations[presentpozition]->vec()[i]->getstation2id()));
            }
        }
        tovisit.pop();
    }
    vector<station*> trasa;
    int poz = getpozition(second);
    while (poz != getpozition(start))
    {
        trasa.push_back(stations[poz]);
        poz = distan[poz].first;
    }

    trasa.push_back(stations[poz]);
    return trasa;//vector stacji


}