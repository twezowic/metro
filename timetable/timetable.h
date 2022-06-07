#include"../train/train.h"
//all done by Michal Bogiel
#include <queue>
class timetable
{
    queue<pair<train*, min_time>> my_timetable;
public:
    timetable();
    void add_timetable(train& trainname, min_time time);
    pair<vector<train*>, min_time>  nextTrain(min_time time);
};

