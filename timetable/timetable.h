#include"../train/train.h"
#include <queue>
class timetable
{
    typedef int time;
    queue<pair<train*, time>> my_timetable;
public:
    timetable();
    void add_timetable(train& trainname, time time);
    pair<vector<train*>, time>  nextTrain(time time);
};

